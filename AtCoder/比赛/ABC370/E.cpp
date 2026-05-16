#include <bits/stdc++.h>
using namespace std;

#define int long long

#define endl '\n'
#define FRR(file) freopen(file,"r",stdin)
#define FRW(file) freopen(file,"w",stdout)
#define _rep(i,a,b) for (int i=(a);i<=(b);++i)
#define _reps(i,a,b,c) for (int i=(a);i<=(b);c)
#define _rrep(i,a,b) for (int i=(a);i>=(b);--i)
#define _rreps(i,a,b,c) for (int i=(a);i>=(b);c)
#define _iter(i,a) for (auto i=a.begin();i!=a.end();++i)
#define _graph(i,u) for (int i=h[u];~i;i=ne[i])
#define rint register int
#define LL long long
typedef pair<int,int> pii;

const int N=200005;
const int mod=998244353;

int n,k;
int arr[N];
int pre[N];
int pw[N];
int d[N];
int f[N];
unordered_set<int> vec[N];
unordered_map<int,int> hs;

// void init() {
//     pw[0]=1;
//     _rep(i,1,N-1) pw[i]=(pw[i-1]*2)%mod;
// }

signed main() {
    // init();
    scanf("%lld %lld",&n,&k);
    _rep(i,1,n) scanf("%lld",&arr[i]);
    _rep(i,1,n) pre[i]=pre[i-1]+arr[i];
    pw[0]=1;
    _rep(i,1,n) {
        pw[i]=pw[i-1]*2%mod;
        d[i]=hs[arr[i]-k];
        pw[i]-=d[i];
        hs[pre[i-1]]+=(i-2<0)?0:pw[i-2];
    }
    _rep(i,1,n) printf("%d ",pw[i]);
}