#include <bits/stdc++.h>

#define int long long
#define int128 __int128

using namespace std;

const int N=200005;
const int mod=1LL<<32;
const int inf=1e18;

int n,m;
int arr[N];

struct SegmentTree {
    int l,r;
    int sum;
    int lcm;
} tr[N*4];

int gcd(int a,int b) {
    return (!b)?a:gcd(b,a%b);
}

int lcm(int a,int b) {
    int128 k=((int128)a)*((int128)b)/((int128)gcd(a,b));
    if (k>(int128)(inf)) k=(int128)inf+(int128)1;
    return k;
}

void pushup(int u) {
    tr[u].sum=tr[u<<1].sum+tr[u<<1|1].sum;
    tr[u].sum%=mod;
    tr[u].lcm=lcm(tr[u<<1].lcm,tr[u<<1|1].lcm);
}

void build(int u,int l,int r) {
    tr[u]={l,r,arr[l],arr[l]};
    if (l==r) return;
    int mid=l+r>>1;
    build(u<<1,l,mid);
    build(u<<1|1,mid+1,r);
    pushup(u);
}

void modify(int u,int l,int r,int x) {
    if (tr[u].lcm<=inf && x%tr[u].lcm==0) return;
    if (tr[u].l==tr[u].r) {
        tr[u].sum=gcd(tr[u].sum,x);
        tr[u].lcm=tr[u].sum;
    } else {
        int mid=tr[u].l+tr[u].r>>1;
        if (l<=mid) modify(u<<1,l,r,x);
        if (r>mid) modify(u<<1|1,l,r,x);
        pushup(u);
    }
}

int query(int u,int l,int r) {
    if (tr[u].l>=l && tr[u].r<=r) return tr[u].sum;
    int mid=tr[u].l+tr[u].r>>1;
    int ans=0;
    if (l<=mid) ans+=query(u<<1,l,r);
    if (r>mid) ans+=query(u<<1|1,l,r);
    ans%=mod;
    return ans;
}

signed main() {
    scanf("%lld %lld",&n,&m);
    for (int i=1;i<=n;++i) {
        scanf("%lld",&arr[i]);
    }
    build(1,1,n);
    while (m--) {
        int op,l,r;
        scanf("%lld %lld %lld",&op,&l,&r);
        if (op==1) {
            int x;
            scanf("%lld",&x);
            modify(1,l,r,x);
        } else {
            printf("%lld\n",query(1,l,r)%mod);
        }
    }
    return 0;
}