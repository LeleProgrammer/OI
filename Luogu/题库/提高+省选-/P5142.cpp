#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N=100005;
const int mod=1e9+7;

int n,m;
int arr[N];

struct SegmentTree {
    int l,r;
    int sum;
    int sum2;
} tr[N*4];

int exgcd(int a,int b,int& x,int& y) {
    if (!b) {
        x=1,y=0;
        return a;
    }
    int d=exgcd(b,a%b,x,y);
    int t=x;
    x=y;
    y=t-(a/b)*y;
    return d;
}

int getMod(int a,int b,int p) {
    swap(a,b);
    swap(b,p);
    int x0,y0;
    int d=exgcd(a,b,x0,y0);
    if (p%d) {
        assert(false);
        return 0;
    }
    int x1,y1;
    x1=x0*p/d;
    y1=y0*p/d;
    int dx;
    dx=b/d;
    int s;
    s=ceil((-x1+1.00)/dx);
    return x1+s*dx;
}

void pushup(int u) {
    tr[u].sum=tr[u<<1].sum+tr[u<<1|1].sum;
    tr[u].sum%=mod;
    tr[u].sum2=tr[u<<1].sum2+tr[u<<1|1].sum2;
    tr[u].sum2%=mod;
}

void build(int u,int l,int r) {
    tr[u]={l,r,arr[l]%mod,arr[l]*arr[l]%mod};
    if (l==r) return;
    int mid=l+r>>1;
    build(u<<1,l,mid); build(u<<1|1,mid+1,r);
    pushup(u);
}

void modify(int u,int p,int k) {
    if (tr[u].l==p && tr[u].r==p) tr[u].sum=k%mod,tr[u].sum2=k*k%mod;
    else {
        int mid=tr[u].l+tr[u].r>>1;
        if (p<=mid) modify(u<<1,p,k);
        else modify(u<<1|1,p,k);
        pushup(u);
    }
}

SegmentTree query(int u,int l,int r) {
    if (tr[u].l>=l && tr[u].r<=r) return tr[u];
    int mid=tr[u].l+tr[u].r>>1;
    SegmentTree ans;
    ans.sum=0;
    ans.sum2=0;
    if (l<=mid) {
        SegmentTree t=query(u<<1,l,r);
        ans.sum+=t.sum;
        ans.sum%=mod;
        ans.sum2+=t.sum2;
        ans.sum2%=mod;
    }
    if (r>mid) {
        SegmentTree t=query(u<<1|1,l,r);
        ans.sum+=t.sum;
        ans.sum%=mod;
        ans.sum2+=t.sum2;
        ans.sum2%=mod;
    }
    return ans;
}

signed main() {
    scanf("%lld %lld",&n,&m);
    for (int i=1;i<=n;++i) scanf("%lld",&arr[i]);
    build(1,1,n);
    while (m--) {
        int op,x,y;
        scanf("%lld %lld %lld",&op,&x,&y);
        if (op==1) modify(1,x,y);
        else {
            SegmentTree ans=query(1,x,y);
            int up,down,res,len;
            len=y-x+1;
            up=ans.sum*ans.sum;
            up%=mod;
            down=len;
            res=getMod(up,down,mod);
            res%=mod;
            up=ans.sum2-res;
            up=(up+mod)%mod;
            down=len;
            res=getMod(up,down,mod);
            res%=mod;
            printf("%lld\n",res);
        }
    }
    return 0;
}