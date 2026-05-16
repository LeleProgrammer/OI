#include <bits/stdc++.h>

#define inf 2147483647

using namespace std;

const int N=2000005;

int n,m;
int arr[N];

struct SegmentTree {
    int l,r;
    int root;
} seg[N];

struct SplayTree {
    int s[2],p,v;
    int size;
    void init(int v,int p) {
        this->v=v;
        this->p=p;
        size=1;
    }
} tr[N];

int tot;

void pushup(int u) {
    tr[u].size=tr[tr[u].s[0]].size+tr[tr[u].s[1]].size+1;
}

void rotate(int x) {
    int y=tr[x].p;
    int z=tr[y].p;
    int k=tr[y].s[1]==x;
    tr[z].s[tr[z].s[1]==y]=x,tr[x].p=z;
    tr[y].s[k]=tr[x].s[k^1],tr[tr[x].s[k^1]].p=y;
    tr[x].s[k^1]=y,tr[y].p=x;
    pushup(y);
    pushup(x);
}

void splay(int& root,int x,int k) {
    while (tr[x].p!=k) {
        int y=tr[x].p;
        int z=tr[y].p;
        if (z!=k) {
            if ((tr[z].s[1]==y)^(tr[y].s[1]==x)) rotate(x);
            else rotate(y);
        }
        rotate(x);
    }
    if (!k) root=x;
}

int get_k(int root,int k) {
    int u=root;
    while (u) {
        if (tr[tr[u].s[0]].size>=k) u=tr[u].s[0];
        else if (tr[tr[u].s[0]].size+1==k) return u;
        else k-=tr[tr[u].s[0]].size+1,u=tr[u].s[1];
    }
    return -1;
}

int get_rank(int root,int x) {
    int u=root,rank=0;
    while (u) {
        if (x<=tr[u].v) u=tr[u].s[0];
        else {
            rank+=tr[tr[u].s[0]].size+1;
            u=tr[u].s[1];
        }
    }
    return rank;
}

int gett(int root,int x) {
    int u=root;
    while (u) {
        if (x<tr[u].v) u=tr[u].s[0];
        else if (x==tr[u].v) return u;
        else u=tr[u].s[1];
    }
    return -1;
}

void insert(int& root,int k) {
    int u=root,p=0;
    while (u) p=u,u=tr[u].s[k>tr[u].v];
    u=++tot;
    if (p) tr[p].s[k>tr[p].v]=u;
    tr[u].init(k,p);
    splay(root,u,0);
}

void build(int u,int l,int r) {
    seg[u]={l,r,0};
    insert(seg[u].root,-inf);
    insert(seg[u].root,inf);
    for (int i=l;i<=r;++i) insert(seg[u].root,arr[i]);
    if (l==r) return;
    int mid=l+r>>1;
    build(u<<1,l,mid);
    build(u<<1|1,mid+1,r);
}

void change(int& root,int old,int x) {
    int u=gett(root,old);
    splay(root,u,0);
    int l=tr[u].s[0];
    int r=tr[u].s[1];
    while (tr[l].s[1]) l=tr[l].s[1];
    while (tr[r].s[0]) r=tr[r].s[0];
    splay(root,l,0);
    splay(root,r,l);
    tr[r].s[0]=0;
    pushup(r);
    pushup(l);
    insert(root,x);
}

void modify(int u,int pos,int x) {
    change(seg[u].root,arr[pos],x);
    if (seg[u].l==seg[u].r) return;
    int mid=seg[u].l+seg[u].r>>1;
    if (pos<=mid) modify(u<<1,pos,x);
    else modify(u<<1|1,pos,x);
}

int query_rank(int u,int l,int r,int k) {
    if (seg[u].l>=l && seg[u].r<=r) return get_rank(seg[u].root,k)-1;
    int mid=seg[u].l+seg[u].r>>1;
    int ans=0;
    if (l<=mid) ans+=query_rank(u<<1,l,r,k);
    if (r>mid) ans+=query_rank(u<<1|1,l,r,k);
    return ans;
}

int get_previous(int root,int x) {
    int u=root;
    int ans=-inf;
    while (u) {
        if (x>tr[u].v) ans=max(ans,tr[u].v),u=tr[u].s[1];
        else u=tr[u].s[0];
    }
    return ans;
}

int get_next(int root,int x) {
    int u=root;
    int ans=inf;
    while (u) {
        if (x<tr[u].v) ans=min(ans,tr[u].v),u=tr[u].s[0];
        else u=tr[u].s[1];
    }
    return ans;
}

int query_previous(int u,int l,int r,int x) {
    if (seg[u].l>=l && seg[u].r<=r) return get_previous(seg[u].root,x);
    int mid=seg[u].l+seg[u].r>>1;
    int ans=-inf;
    if (l<=mid) ans=max(ans,query_previous(u<<1,l,r,x));
    if (r>mid) ans=max(ans,query_previous(u<<1|1,l,r,x));
    return ans;
}

int query_next(int u,int l,int r,int x) {
    if (seg[u].l>=l && seg[u].r<=r) return get_next(seg[u].root,x);
    int mid=seg[u].l+seg[u].r>>1;
    int ans=inf;
    if (l<=mid) ans=min(ans,query_next(u<<1,l,r,x));
    if (r>mid) ans=min(ans,query_next(u<<1|1,l,r,x));
    return ans;
}

int main() {
    scanf("%d %d",&n,&m);
    for (int i=1;i<=n;++i) {
        scanf("%d",&arr[i]);
    }
    build(1,1,n);
    while (m--) {
        int op;
        scanf("%d",&op);
        if (op==1) {
            int l,r,x;
            scanf("%d %d %d",&l,&r,&x);
            printf("%d\n",query_rank(1,l,r,x)+1);
        } else if (op==2) {
            int a,b,k;
            scanf("%d %d %d",&a,&b,&k);
            int l=0,r=100000000;
            while (l<r) {
                int mid=l+r+1>>1;
                if (query_rank(1,a,b,mid)+1<=k) l=mid;
                else r=mid-1;
            }
            printf("%d\n",r);
        } else if (op==3) {
            int pos,k;
            scanf("%d %d",&pos,&k);
            modify(1,pos,k);
            arr[pos]=k;
        } else if (op==4) {
            int l,r,x;
            scanf("%d %d %d",&l,&r,&x);
            int ans=query_previous(1,l,r,x);
            printf("%d\n",ans);
        } else {
            int l,r,x;
            scanf("%d %d %d",&l,&r,&x);
            int ans=query_next(1,l,r,x);
            printf("%d\n",ans);
        }
    }
    return 0;
}