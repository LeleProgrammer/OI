#include <bits/stdc++.h>

#define int long long

using namespace std;

int n,m;
char op[2];
int x,y,k;
int a[100005];

struct Node {
    int l;
    int r;
    int sum;
    int add;
} tr[400020];

void pushup(int u) {
    tr[u].sum=tr[u<<1].sum+tr[u<<1|1].sum;
}

void pushdown(int u) {
    auto& left=tr[u<<1],&right=tr[u<<1|1],&root=tr[u];
    left.add+=root.add;
    right.add+=root.add;
    left.sum+=(left.r-left.l+1)*root.add;
    right.sum+=(right.r-right.l+1)*root.add;
    root.add=0;
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

void modify(int u,int l,int r,int k) {
    if (tr[u].l>=l && tr[u].r<=r) {
        tr[u].add+=k;
        tr[u].sum+=(tr[u].r-tr[u].l+1)*k;
    } else {
        int mid=tr[u].l+tr[u].r>>1;
        pushdown(u);
        if (l<=mid) modify(u<<1,l,r,k);
        if (r>=mid+1) modify(u<<1|1,l,r,k);
        pushup(u);
    }
}

int query(int u,int l,int r) {
    if (tr[u].l>=l && tr[u].r<=r) return tr[u].sum;
    int mid=tr[u].l+tr[u].r>>1;
    pushdown(u);
    int res=0;
    if (l<=mid) res+=query(u<<1,l,r);
    if (r>=mid+1) res+=query(u<<1|1,l,r);
    return res;
}

signed main() {
    scanf("%lld %lld",&n,&m);
    for (int i=1;i<=n;++i) scanf("%lld",&a[i]);
    build(1,1,n);
    while (m--) {
        scanf("%s %lld %lld",op,&x,&y);
        if (*op=='1') {
            scanf("%lld",&k);
            modify(1,x,y,k);
        } else {
            printf("%lld\n",query(1,x,y));
        }
    }
    return 0;
}