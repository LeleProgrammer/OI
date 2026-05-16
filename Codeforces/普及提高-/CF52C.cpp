#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N=200005;

int n,m;
int a[N];
int l,r,v;

struct node {
    int l,r;
    int minn;
    int add;
} tr[N*4];

void pushup(int u) {
    tr[u].minn=min(tr[u<<1].minn,tr[u<<1|1].minn);
}

void pushdown(int u) {
    auto &root=tr[u],&left=tr[u<<1],&right=tr[u<<1|1];
    if (root.add) {
        left.add+=root.add; right.add+=root.add;
        left.minn+=root.add; right.minn+=root.add;
        root.add=0;
    }
}

void build(int u,int l,int r) {
    if (l==r) {
        tr[u]={l,r,a[l],0};
    } else {
        tr[u]={l,r,0,0};
        int mid=l+r>>1;
        build(u<<1,l,mid);
        build(u<<1|1,mid+1,r);
        pushup(u);
    }
}

void inc(int u,int l,int r,int v) {
    if (tr[u].l>=l && tr[u].r<=r) {
        tr[u].add+=v;
        tr[u].minn+=v;
    } else {
        pushdown(u);
        int mid=tr[u].l+tr[u].r>>1;
        if (l<=mid) inc(u<<1,l,r,v);
        if (r>mid) inc(u<<1|1,l,r,v);
        pushup(u);
    }
}

int rmq(int u,int l,int r) {
    if (tr[u].l>=l && tr[u].r<=r) return tr[u].minn;
    pushdown(u);
    int mid=tr[u].l+tr[u].r>>1;
    int res=0x3f3f3f3f3f3f3f3f;
    if (l<=mid) res=rmq(u<<1,l,r);
    if (r>mid) res=min(res,rmq(u<<1|1,l,r));
    return res;
}

signed main() {
    scanf("%lld",&n);
    for (int i=1;i<=n;++i) cin>>a[i];
    build(1,1,n);
    scanf("%lld",&m);
    while (m--) {
        scanf("%lld %lld",&l,&r); l++,r++;
        char c=getchar();
        if (c==' ') {
            scanf("%lld",&v);
            if (l>r) {
                inc(1,l,n,v);
                inc(1,1,r,v);
            } else {
                inc(1,l,r,v);
            }
        } else {
            int res;
            if (l>r) {
                res=min(rmq(1,l,n),rmq(1,1,r));
            } else {
                res=rmq(1,l,r);
            }
            printf("%lld\n",res);
        }
    }
    return 0;
}