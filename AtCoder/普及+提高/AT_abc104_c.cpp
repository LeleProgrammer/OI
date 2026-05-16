#include <bits/stdc++.h>
using namespace std;

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

const int N=15;
const int M=1005;

int n,g;
int p[N],c[N];
int pre[N];
int f[N][M];

int main() {
    scanf("%d %d",&n,&g);
    _rep(i,1,n) {
        scanf("%d %d",&p[i],&c[i]);
        pre[i]=pre[i-1]+p[i];
    }
    _rep(i,1,n) {
        _rep(j,0,pre[i]) {
            _rep(k,0,p[i]) {
                if (j-k<0) continue;
                if (k==p[i]) f[i][j]=max(f[i][j],f[i-1][j-k]+i*k*100+c[i]);
                else f[i][j]=max(f[i][j],f[i-1][j-k]+i*k*100);
            }
        }
    }
    _rep(i,0,pre[n]) {
        if (f[n][i]>=g) {
            printf("%d",i);
            return 0;
        }
    }
    return 0;
}