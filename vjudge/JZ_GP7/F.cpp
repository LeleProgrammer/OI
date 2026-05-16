#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N=100005;

int n,m;
int arr[N];

struct SegmentTree {
    int l,r;
    int sum;
    bool tag;
} tr[N*4];

bool check(int x) {
    return x==0 || x==1;
}

void pushup(int u) {
    tr[u].sum=tr[u<<1].sum+tr[u<<1|1].sum;
    tr[u].tag=tr[u<<1].tag&tr[u<<1|1].tag;
}

void build(int u,int l,int r) {
    tr[u]={l,r,arr[l],check(arr[l])};
    if (l==r) return;
    int mid=l+r>>1;
    build(u<<1,l,mid); build(u<<1|1,mid+1,r);
    pushup(u);
}

void modify(int u,int l,int r) {
    if (tr[u].tag) return;
    if (tr[u].l==tr[u].r) {
        tr[u].sum=sqrt(tr[u].sum);
        tr[u].tag=check(tr[u].sum);
    } else {
        int mid=tr[u].l+tr[u].r>>1;
        if (l<=mid) modify(u<<1,l,r);
        if (r>mid) modify(u<<1|1,l,r);
        pushup(u);
    }
}

int query(int u,int l,int r) {
    if (tr[u].l>=l && tr[u].r<=r) return tr[u].sum;
    int mid=tr[u].l+tr[u].r>>1;
    int ans=0;
    if (l<=mid) ans+=query(u<<1,l,r);
    if (r>mid) ans+=query(u<<1|1,l,r);
    return ans;
}

signed main() {
    scanf("%lld",&n);
    for (int i=1;i<=n;++i) scanf("%lld",&arr[i]);
    build(1,1,n);
    scanf("%lld",&m);
    while (m--) {
        int op,a,b;
        scanf("%lld %lld %lld",&op,&a,&b);
        if (a>b) swap(a,b);
        if (!op) modify(1,a,b);
        else printf("%lld\n",query(1,a,b));
    }
    return 0;
}