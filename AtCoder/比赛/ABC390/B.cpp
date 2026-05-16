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

const int N=105;
const double eps=1e-18;

int n;
int arr[N];

signed main() {
    scanf("%lld",&n);
    _rep(i,1,n) scanf("%lld",&arr[i]);
    bool ok=true;
    _rep(i,2,n) {
        if (arr[i]*arr[1]!=arr[2]*arr[i-1]) {
            ok=false;
            break;
        }
    }
    if (ok) puts("Yes");
    else puts("No");
    return 0;
}