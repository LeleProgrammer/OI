#include <bits/stdc++.h>

#define inf 2000000000

using namespace std;

const int N=500005;

int n,m;
int arr[N];
int trash[N],cnt;
int root;

struct node {

    int s[2],p,v;
    int mod,fli,sum,size;
    int lmax,amax,rmax;

    void init(int v,int p) {
        this->v=v;
        this->p=p;
        mod=0;
        fli=0;
        sum=v;
        size=1;
        lmax=max(v,0);
        rmax=max(v,0);
        amax=v;
        s[0]=0;
        s[1]=0;
    }

} tr[N];

void pushup(int u) {
    auto &curr=tr[u],&left=tr[tr[u].s[0]],&right=tr[tr[u].s[1]];
    curr.sum=left.sum+right.sum+curr.v;
    curr.size=left.size+right.size+1;
    curr.lmax=max(left.lmax,left.sum+curr.v+right.lmax);
    curr.rmax=max(right.rmax,right.sum+curr.v+left.rmax);
    curr.amax=max(left.rmax+curr.v+right.lmax,max(left.amax,right.amax));
}

void pushdown(int u) {
    auto &curr=tr[u],&left=tr[tr[u].s[0]],&right=tr[tr[u].s[1]];
    if (curr.mod) {
        if (curr.s[0]) {
            left.mod=1;
            left.v=curr.v;
            left.sum=left.size*curr.v;
        }
        if (curr.s[1]) {
            right.mod=1;
            right.v=curr.v;
            right.sum=right.size*curr.v;
        }
        curr.mod=0;
        curr.fli=0;
        if (curr.v>0) {
            if (curr.s[0]) {
                left.lmax=left.sum;
                left.rmax=left.sum;
                left.amax=left.sum;
            }
            if (curr.s[1]) {
                right.lmax=right.sum;
                right.rmax=right.sum;
                right.amax=right.sum;
            }
        } else {
            if (curr.s[0]) {
                left.lmax=0;
                left.rmax=0;
                left.amax=curr.v;
            }
            if (curr.s[1]) {
                right.lmax=0;
                right.rmax=0;
                right.amax=curr.v;
            }
        }
    } else if (curr.fli) {
        curr.fli=0;
        left.fli^=1;
        right.fli^=1;
        swap(left.lmax,left.rmax);
        swap(right.lmax,right.rmax);
        swap(left.s[0],left.s[1]);
        swap(right.s[0],right.s[1]);
    }
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

void splay(int x,int k) {
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

int get_k(int k) {
    int u=root;
    while (u) {
        pushdown(u);
        if (tr[tr[u].s[0]].size>=k) u=tr[u].s[0];
        else if (tr[tr[u].s[0]].size+1==k) return u;
        else k-=tr[tr[u].s[0]].size+1,u=tr[u].s[1];
    }
    return -1;
}

int build(int l,int r,int fa) {
    int u=trash[cnt--];
    int mid=l+r>>1;
    tr[u].init(arr[mid],fa);
    if (l<mid) tr[u].s[0]=build(l,mid-1,u);
    if (r>mid) tr[u].s[1]=build(mid+1,r,u);
    pushup(u);
    return u;
}

void clear(int x) {
    trash[++cnt]=x;
    if (tr[x].s[0]) clear(tr[x].s[0]);
    if (tr[x].s[1]) clear(tr[x].s[1]);
}

int main() {
    scanf("%d %d",&n,&m);
    for (int i=1;i<N;++i) {
        trash[++cnt]=i;
    }
    tr[0].amax=-inf;
    arr[0]=-inf;
    for (int i=1;i<=n;++i) {
        scanf("%d",&arr[i]);
    }
    arr[n+1]=-inf;
    root=build(0,n+1,0);
    while (m--) {
        char op[15];
        scanf("%s",op);
        if (!strcmp(op,"INSERT")) {
            int posi,tt;
            scanf("%d %d",&posi,&tt);
            for (int i=1;i<=tt;++i) {
                scanf("%d",&arr[i]);
            }
            int left=get_k(posi+1);
            int right=get_k(posi+2);
            splay(left,0);
            splay(right,left);
            int u=build(1,tt,right);
            tr[right].s[0]=u;
            pushup(right);
            pushup(left);
        } else if (!strcmp(op,"DELETE")) {
            int posi,tt;
            scanf("%d %d",&posi,&tt);
            int left=get_k(posi);
            int right=get_k(posi+tt+1);
            splay(left,0);
            splay(right,left);
            clear(tr[right].s[0]);
            tr[right].s[0]=0;
            pushup(right);
            pushup(left);
        } else if (!strcmp(op,"MAKE-SAME")) {
            int posi,tt,c;
            scanf("%d %d %d",&posi,&tt,&c);
            int left=get_k(posi);
            int right=get_k(posi+tt+1);
            splay(left,0);
            splay(right,left);
            auto &u=tr[tr[right].s[0]];
            u.mod=1;
            u.v=c;
            u.sum=u.size*c;
            if (c>0) {
                u.lmax=u.sum;
                u.rmax=u.sum;
                u.amax=u.sum;
            } else {
                u.lmax=0;
                u.rmax=0;
                u.amax=c;
            }
            pushup(right);
            pushup(left);
        } else if (!strcmp(op,"REVERSE")) {
            int posi,tt;
            scanf("%d %d",&posi,&tt);
            int left=get_k(posi);
            int right=get_k(posi+tt+1);
            splay(left,0);
            splay(right,left);
            auto &u=tr[tr[right].s[0]];
            u.fli^=1;
            swap(u.lmax,u.rmax);
            swap(u.s[0],u.s[1]);
            pushup(right);
            pushup(left);
        } else if (!strcmp(op,"GET-SUM")) {
            int posi,tt;
            scanf("%d %d",&posi,&tt);
            int left=get_k(posi);
            int right=get_k(posi+tt+1);
            splay(left,0);
            splay(right,left);
            auto u=tr[tr[right].s[0]];
            printf("%d\n",u.sum);
        } else if (!strcmp(op,"MAX-SUM")) {
            int a,b;
            scanf("%d %d",&a,&b);
            int left=get_k(a);
            int right=get_k(a+b+1);
            splay(left,0);
            splay(right,left);
            printf("%d\n",tr[tr[right].s[0]].amax);
        } else if (!strcmp(op,"GET")) {
            int x;
            scanf("%d",&x);
            int u=get_k(x+1);
            printf("%d\n",tr[u].v);
        }
    }
    return 0;
}