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

const int N=1005;
const int inf=2e9;

int n,m;
char arr[N][N];
int mnx=inf,mny=inf,mxx=-inf,mxy=-inf;

int main() {
    scanf("%d %d",&n,&m);
    bool un=false;
    _rep(i,1,n) _rep(j,1,m) {
        char c;
        scanf(" %c",&c);
        if (c=='#') mnx=min(mnx,i),mxx=max(mxx,i),mny=min(mny,j),mxy=max(mxy,j);
        else if (c=='?') un=true;
        arr[i][j]=c;
    }
    if (mnx==inf) {
        if (un) puts("Yes");
        else puts("No");
    } else {
        bool ok=true;
        _rep(i,mnx,mxx) _rep(j,mny,mxy) if (arr[i][j]=='.') ok=false;
        if (ok) puts("Yes");
        else puts("No");
    }
    return 0;
}