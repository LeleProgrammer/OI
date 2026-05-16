#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N=50005;
const int inf=9e18;

int n,m;
int arr[N];

struct SegmentTree {
    int l,r;
    int sum;
    int lmax;
    int rmax;
    int mmax;
} tr[N*4];

void pushup(int u) {
    tr[u].sum=tr[u<<1].sum+tr[u<<1|1].sum;
    tr[u].lmax=max(tr[u<<1].lmax,tr[u<<1].sum+tr[u<<1|1].lmax);
    tr[u].rmax=max(tr[u<<1|1].rmax,tr[u<<1|1].sum+tr[u<<1].rmax);
    tr[u].mmax=max(max(tr[u<<1].mmax,tr[u<<1|1].mmax),tr[u<<1].rmax+tr[u<<1|1].lmax);
}

void build(int u,int l,int r) {
    tr[u]={l,r,arr[l],arr[l],arr[l],arr[l]};
    if (l==r) return;
    int mid=l+r>>1;
    build(u<<1,l,mid);
    build(u<<1|1,mid+1,r);
    pushup(u);
}

SegmentTree query(int u,int l,int r) {
    if (tr[u].l>=l && tr[u].r<=r) return tr[u];
    int mid=tr[u].l+tr[u].r>>1;
    SegmentTree ans;
    if (l<=mid && r>mid) {
        auto L=query(u<<1,l,r);
        auto R=query(u<<1|1,l,r);
        ans.lmax=max(L.lmax,L.sum+R.lmax);
        ans.rmax=max(R.rmax,R.sum+L.rmax);
        ans.mmax=max(max(L.mmax,R.mmax),L.rmax+R.lmax);
    } else if (l<=mid) ans=query(u<<1,l,r);
    else ans=query(u<<1|1,l,r);
    return ans;
}

signed main() {
    scanf("%lld",&n);
    for (int i=1;i<=n;++i) {
        scanf("%lld",&arr[i]);
    }
    build(1,1,n);
    scanf("%lld",&m);
    while (m--) {
        int a,b;
        scanf("%lld %lld",&a,&b);
        auto t=query(1,a,b);
        printf("%lld\n",t.mmax);
    }
    return 0;
}