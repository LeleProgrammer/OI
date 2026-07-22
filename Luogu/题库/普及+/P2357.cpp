#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N=200005;

int n,Q;
int arr[N];

struct SegmentTree {
    int l,r;
    int add;
    int sum;
} tr[N*4];

void pushup(int u) {
    tr[u].sum=tr[u<<1].sum+tr[u<<1|1].sum;
}

void pushdown(int u) {
    auto &root=tr[u],&left=tr[u<<1],&right=tr[u<<1|1];
    if (root.add) {
        left.add+=root.add;
        right.add+=root.add;
        left.sum+=(left.r-left.l+1)*root.add;
        right.sum+=(right.r-right.l+1)*root.add;
        root.add=0;
    }
}

void build(int u,int l,int r) {
    tr[u]={l,r,0,arr[l]};
    if (l==r) return;
    int mid=l+r>>1;
    build(u<<1,l,mid);
    build(u<<1|1,mid+1,r);
    pushup(u);
}

void modify(int u,int l,int r,int k) {
    if (tr[u].l>=l && tr[u].r<=r) {
        tr[u].add+=k;
        tr[u].sum+=(tr[u].r-tr[u].l+1)*k;
    } else {
        pushdown(u);
        int mid=tr[u].l+tr[u].r>>1;
        if (l<=mid) modify(u<<1,l,r,k);
        if (r>mid) modify(u<<1|1,l,r,k);
        pushup(u);
    }
}

int query(int u,int l,int r) {
    if (tr[u].l>=l && tr[u].r<=r) return tr[u].sum;
    pushdown(u);
    int mid=tr[u].l+tr[u].r>>1;
    int ans=0;
    if (l<=mid) ans+=query(u<<1,l,r);
    if (r>mid) ans+=query(u<<1|1,l,r);
    return ans;
}

signed main() {
    scanf("%lld %lld",&n,&Q);
    for (int i=1;i<=n;++i) {
        scanf("%lld",&arr[i]);
    }
    build(1,1,n);
    while (Q--) {
        int op;
        scanf("%lld",&op);
        if (op==1) {
            int l,r,k;
            scanf("%lld %lld %lld",&l,&r,&k);
            modify(1,l,r,k);
        } else if (op==2) {
            int k;
            scanf("%lld",&k);
            modify(1,1,1,k);
        } else if (op==3) {
            int k;
            scanf("%lld",&k);
            modify(1,1,1,-k);
        } else if (op==4) {
            int l,r;
            scanf("%lld %lld",&l,&r);
            printf("%lld\n",query(1,l,r));
        } else {
            printf("%lld\n",query(1,1,1));
        }
    }
    return 0;
}