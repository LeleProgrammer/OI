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

const int N=200005;
const int inf=9e18;

int n;
int arr[N];
int f[N][2];

signed main() {
    scanf("%lld",&n);
    _rep(i,1,n) scanf("%lld",&arr[i]);
    _rep(i,1,n) _rep(j,0,1) f[i][j]=-inf;
    f[0][1]=-inf;
    _rep(i,1,n) {
        _rep(j,0,1) {
            f[i][j]=max(f[i-1][j],f[i-1][j^1]+arr[i]*(j==1?1:2));
        }
    }
    printf("%lld",max(f[n][0],f[n][1]));
    return 0;
}