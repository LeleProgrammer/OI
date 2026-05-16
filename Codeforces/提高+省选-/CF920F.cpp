#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N=300005;
const int M=5;
const int K=1000005;

int n,m;
int arr[N];
int d[K];

struct SegmentTree {
    int l,r;
    int sum;
    bool tag;
} tr[N*4];

void init() {
    for (int i=1;i<K;++i) {
        for (int j=1;i*j<K;++j) {
            d[i*j]++;
        }
    }
}

void pushup(int u) {
    tr[u].sum=tr[u<<1].sum+tr[u<<1|1].sum;
    tr[u].tag=tr[u<<1].tag && tr[u<<1|1].tag;
}

void build(int u,int l,int r) {
    tr[u]={l,r,arr[l],0};
    if (l==r) return;
    int mid=l+r>>1;
    build(u<<1,l,mid);
    build(u<<1|1,mid+1,r);
    pushup(u);
}

void modify(int u,int l,int r) {
    if (tr[u].tag) return;
    if (tr[u].l==tr[u].r) {
        tr[u].sum=d[tr[u].sum];
        tr[u].tag=tr[u].sum<=2;
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
    init();
    scanf("%lld %lld",&n,&m);
    for (int i=1;i<=n;++i) {
        scanf("%lld",&arr[i]);
    }
    build(1,1,n);
    while (m--){
        int op,l,r;
        scanf("%lld %lld %lld",&op,&l,&r);
        if (op==1) modify(1,l,r);
        else printf("%lld\n",query(1,l,r));
    }
    return 0;
}