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

const int N=19;
const int M=(1<<19);
const int inf=2e9;

int n,w;
int arr[N];
int f[N][M];

int main() {
    _rep(i,0,N-1) _rep(j,0,M-1) f[i][j]=inf;
    scanf("%d %d",&n,&w);
    _rep(i,1,n) scanf("%d",&arr[i]);
    f[1][0]=0;
    _rep(i,1,n) {
        _rep(j,0,(1<<n)-1) {
            if (f[i][j]==inf) continue;
            _rep(k,1,n) {
                if ((j>>(k-1))&1) continue;
                if (f[i][j]+arr[k]<=w) f[i][j|(1<<(k-1))]=min(f[i][j|(1<<(k-1))],f[i][j]+arr[k]);
                if (i!=n) f[i+1][j|(1<<(k-1))]=min(f[i+1][j|(1<<(k-1))],arr[k]);
            }
        }
    }
    _rep(i,1,n) {
        if (f[i][(1<<n)-1]!=inf) {
            printf("%d",i);
            break;
        }
    }
    return 0;
}