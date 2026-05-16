#include <bits/stdc++.h>
using namespace std;

#define int long long

#define endl '\n'
#define FRR(file) freopen(file,"r",stdin)
#define FRW(file) freopen(file,"w",stdout)
#define TIMESTAMP cerr<<fixed<<setprecision(3)<<clock()*1.0/CLOCKS_PER_SEC<<"s"<<endl;
#define _rep(i,a,b) for (int i=(a);i<=(b);++i)
#define _reps(i,a,b,c) for (int i=(a);i<=(b);c)
#define _rrep(i,a,b) for (int i=(a);i>=(b);--i)
#define _rreps(i,a,b,c) for (int i=(a);i>=(b);c)
#define _iter(i,a) for (auto i=a.begin();i!=a.end();++i)
#define _graph(i,u) for (int i=h[u];~i;i=ne[i])
#define rint register int
#define LL long long
typedef pair<int,int> pii;

const int N=100005;

int T,q,mod;

struct Seg {
    int l,r;
    int val;
} tr[N<<2];

void pushup(int u) {
    tr[u].val=tr[u<<1].val*tr[u<<1|1].val%mod;
}

void build(int u,int l,int r) {
    tr[u]={l,r,1};
    if (l==r) return;
    int mid=l+r>>1;
    build(u<<1,l,mid); build(u<<1|1,mid+1,r);
    pushup(u);
}

void modify(int u,int p,int k) {
    if (tr[u].l==p && tr[u].r==p) tr[u].val=k;
    else {
        int mid=tr[u].l+tr[u].r>>1;
        if (p<=mid) modify(u<<1,p,k);
        else modify(u<<1|1,p,k);
        pushup(u);
    }
}

int query(int u,int l,int r) {
    if (tr[u].l>=l && tr[u].r<=r) return tr[u].val;
    int mid=tr[u].l+tr[u].r>>1;
    int ans=1;
    if (l<=mid) ans=ans*query(u<<1,l,r)%mod;
    if (r>mid) ans=ans*query(u<<1|1,l,r)%mod;
    return ans;
}

signed main() {
    scanf("%lld",&T);
    while (T--) {
        scanf("%lld %lld",&q,&mod);
        build(1,1,q);
        _rep(i,1,q) {
            int op,k;
            scanf("%lld %lld",&op,&k);
            if (op==1) {
                modify(1,i,k);
                printf("%lld\n",query(1,1,q));
            } else {
                modify(1,k,1);
                printf("%lld\n",query(1,1,q));
            }
        }
    }
    return 0;
}