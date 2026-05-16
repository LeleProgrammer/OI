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

const int N=105;

int n,m,k;
char arr[N][N];

int main() {
    scanf("%d %d %d",&n,&m,&k);
    _rep(i,1,n) _rep(j,1,m) arr[i][j]='.';
    _reps(i,1,n,i+=2) {
        _reps(j,1,m,j+=2){
            arr[i][j]='#',k--;
            if (!k) break;
        }
        if (!k) break;
    }
    if (k) puts("IMPOSSIBLE");
    else {
        _rep(i,1,n) {
            _rep(j,1,m) putchar(arr[i][j]);
            putchar(10);
        }
    }
    return 0;
}