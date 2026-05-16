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

const int N=21;

int n,m;
int arr[N],mul[N];

struct Seg {
    int l,r;
    int sum;
} tr[N<<2];

void pushup(int u) {
    tr[u].sum=tr[u<<1].sum+tr[u<<1|1].sum;
}

void build(int u,int l,int r) {
    tr[u]={l,r,1};
    if (l==r) return;
    int mid=l+r>>1;
    build(u<<1,l,mid); build(u<<1|1,mid+1,r);
    pushup(u);
}

void modify(int u,int p,int k) {
    if (tr[u].l==p && tr[u].r==p) tr[u].sum=k;
    else {
        int mid=tr[u].l+tr[u].r>>1;
        if (p<=mid) modify(u<<1,p,k);
        else modify(u<<1|1,p,k);
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

void init() {
    mul[0]=1;
    _rep(i,1,N-1) mul[i]=mul[i-1]*i;
}

signed main() {
    init();
    scanf("%lld %lld",&n,&m);
    while (m--) {
        char op;
        scanf(" %c",&op);
        if (op=='P') {
            int k;
            scanf("%lld",&k); k--;
            build(1,1,n);
            _rep(i,1,n) {
                int p=k/mul[n-i]+1;
                k%=mul[n-i];
                int u=1;
                while (tr[u].l!=tr[u].r) {
                    if (p<=tr[u<<1].sum) u<<=1;
                    else p-=tr[u<<1].sum,u=u<<1|1;
                }
                printf("%lld ",tr[u].l);
                modify(1,tr[u].l,0);
            }
            putchar(10);
        } else {
            _rep(i,1,n) scanf("%lld",&arr[i]);
            build(1,1,n);
            int ans=1;
            _rep(i,1,n) ans+=(query(1,1,arr[i])-1)*mul[n-i],modify(1,arr[i],0);
            printf("%lld\n",ans);
        }
    }
    return 0;
}