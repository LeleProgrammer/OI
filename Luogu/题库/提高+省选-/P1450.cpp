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
const int M=5;

int n;
int c[M],d[M],s;
int f[N];

void init() {
    f[0]=1;
    _rep(i,1,4) _rep(j,c[i],N-1) f[j]+=f[j-c[i]];
}

signed main() {
    _rep(i,1,4) scanf("%lld",&c[i]);
    init();
    scanf("%lld",&n);
    while (n--) {
        _rep(i,1,4) scanf("%lld",&d[i]);
        scanf("%lld",&s);
        int k=0;
        _rep(i,1,15) {
            int t=s,cnt=0;
            _rep(j,1,4) if ((i>>(j-1))&1) t-=c[j]*(d[j]+1),cnt++;
            if (t<0) continue;
            if (cnt&1) k+=f[t];
            else k-=f[t];
        }
        printf("%lld\n",f[s]-k);
    }
    return 0;
}