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

int n;
int arr[N];
int f[N];

signed main() {
    scanf("%lld",&n);
    _rep(i,1,n) scanf("%lld",&arr[i]);
    _rep(i,1,n) {
        f[i]=i==1?1:2;
        if (i!=1 && arr[i]-arr[i-1]==arr[i-1]-arr[i-2]) f[i]+=f[i-1]-1;
    }
    int ans=0;
    _rep(i,1,n) {
        ans+=f[i];
    }
    printf("%lld",ans);
    return 0;
}