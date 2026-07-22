#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N=100005;
const int inf=9e18;

int n,m;
int f[N],s[N];

struct SegmentTree {
    int l,r;
    int max;
} tr[N*4];

void pushup(int u) {
    tr[u].max=max(tr[u<<1].max,tr[u<<1|1].max);
}

void build(int u,int l,int r) {
    tr[u]={l,r,s[l]};
    if (l==r) return;
    int mid=l+r>>1;
    build(u<<1,l,mid);
    build(u<<1|1,mid+1,r);
    pushup(u);
}

int query(int u,int l,int r) {
    if (tr[u].l>=l && tr[u].r<=r) return tr[u].max;
    int mid=tr[u].l+tr[u].r>>1;
    int ans=0;
    if (l<=mid) ans=max(ans,query(u<<1,l,r));
    if (r>mid) ans=max(ans,query(u<<1|1,l,r));
    return ans;
}

signed main() {
    scanf("%lld %lld",&n,&m);
    for (int i=1;i<=n;++i) {
        scanf("%lld %lld",&f[i],&s[i]);
    }
    build(1,1,n);
    int l=1,r=0,sum=0,ans=inf;
    while (r<=n) {
        while (sum<m && r<=n) sum+=f[++r];
        while (sum>=m && l<=r) {
            ans=min(ans,query(1,l,r));
            sum-=f[l++];
        }
    }
    printf("%lld",ans);
    return 0;
}