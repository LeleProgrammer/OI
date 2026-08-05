#include <bits/stdc++.h>
using namespace std;

#define int unsigned long long

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

const int N=500005;
const int M=35;
const int mod=1LL<<32;

int n;
int arr[N];
int ans;

signed main() {
    scanf("%llu",&n);
    _rep(i,1,n) scanf("%llu",&arr[i]);
    _rep(i,0,M) {
        int zero=0,one=0;
        _rep(j,1,n) {
            if ((arr[j]>>i)&1) one++;
            else zero++;
        }
        ans+=(1LL<<i)*((zero*one%mod*2%mod+one*one%mod)%mod*((zero*zero%mod+zero*one%mod*2%mod)%mod)%mod)%mod;
        ans%=mod;
        ans+=((1LL<<i)*(zero*zero%mod)%mod)*(one*one%mod)%mod;
        ans%=mod;
    }
    printf("%llu",ans);
    return 0;
}