#include <bits/stdc++.h>
using namespace std;

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

int T,n;
int a[N];

int main() {
    scanf("%d",&T);
    while (T--) {
        scanf("%d",&n);
        _rep(i,1,n) scanf("%d",&a[i]);
        bool ok=true;
        int p=2*n-2,q=0;
        _rep(i,1,n) {
            if (a[i]<=max(p,q)) {
                ok=false;
                break;
            }
            p-=2,q+=2;
        }
        if (ok) puts("YES");
        else puts("NO");
    }
    return 0;
}