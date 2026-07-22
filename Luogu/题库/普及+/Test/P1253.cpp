#include <bits/stdc++.h>

#define int long long

using namespace std;

const int MAXN=1000005;
const int inf=0x3f3f3f3f3f3f3f3f;

int n,q,op,l,r,x;

struct node {
    int l;
    int r;
    int maxx;
    int add;
    int adj;
} tr[MAXN*4];

int arr[MAXN];

void pushup(int u) {
    tr[u].maxx=max(tr[u<<1].maxx,tr[u<<1|1].maxx);
}

void pushdown(int u,int mode=1) {
    auto &root=tr[u],&left=tr[u<<1],&right=tr[u<<1|1];
    if (mode==1 || mode==3) {
        if (root.adj!=inf) {
            left.add=0;
            right.add=0;
            left.adj=root.adj;
            right.adj=root.adj;
            left.maxx=root.adj;
            right.maxx=root.adj;
            root.adj=inf;
        }
    }
    if (mode==1 || mode==2) {
        if (root.add) {
            pushdown(u,3);
            left.add+=root.add;
            right.add+=root.add;
            left.maxx+=root.add;
            right.maxx+=root.add;
            root.add=0;
        }
    }
}

void build(int u,int l,int r) {
    if (l==r) tr[u]={l,r,arr[l],0,inf};
    else {
        tr[u]={l,r,-inf,0,inf};
        int mid=l+r>>1;
        build(u<<1,l,mid); build(u<<1|1,mid+1,r);
        pushup(u);
    }
}

void modify(int u,int l,int r,int x) {
    if (tr[u].l>=l && tr[u].r<=r) {
        tr[u].add=0;
        tr[u].adj=x;
        tr[u].maxx=x;
    } else {
        pushdown(u);
        int mid=tr[u].l+tr[u].r>>1;
        if (l<=mid) modify(u<<1,l,r,x);
        if (r>=mid+1) modify(u<<1|1,l,r,x);
        pushup(u);
    }
}

void adjust(int u,int l,int r,int k) {
    if (tr[u].l>=l && tr[u].r<=r) {
        pushdown(u,3);
        tr[u].add+=k;
        tr[u].maxx+=k;
    } else {
        pushdown(u);
        int mid=tr[u].l+tr[u].r>>1;
        if (l<=mid) adjust(u<<1,l,r,k);
        if (r>=mid+1) adjust(u<<1|1,l,r,k);
        pushup(u);
    }
}

int query(int u,int l,int r) {
    if (tr[u].l>=l && tr[u].r<=r) return tr[u].maxx;
    pushdown(u);
    int mid=tr[u].l+tr[u].r>>1;
    int maxx=-inf;
    if (l<=mid) maxx=max(maxx,query(u<<1,l,r));
    if (r>=mid+1) maxx=max(maxx,query(u<<1|1,mid+1,r));
    return maxx;
}

signed main() {
    scanf("%lld %lld",&n,&q);
    for (int i=1;i<=n;++i) scanf("%lld",&arr[i]);
    build(1,1,n);
    while (q--) {
        scanf("%lld %lld %lld",&op,&l,&r);
        if (op==1) {
            scanf("%lld",&x);
            modify(1,l,r,x);
        } else if (op==2) {
            scanf("%lld",&x);
            adjust(1,l,r,x);
        } else {
            printf("%lld\n",query(1,l,r));
        }
    }
    return 0;
}