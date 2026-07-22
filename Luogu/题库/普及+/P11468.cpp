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

const int N=200005;
const int M=200005;

int n,indeg[N];
int e[M],ne[M],h[N],tot;
int f[N],g[N];
queue<int> q;

void add(int a,int b) {
    e[tot]=b,ne[tot]=h[a],h[a]=tot++;
}

void topu() {
    _rep(i,1,n) if (!indeg[i]) q.emplace(i);
    while (!q.empty()) {
        int u=q.front(); q.pop();
        g[u]++;
        _graph(i,u) {
            f[e[i]]+=f[u]+g[u];
            g[e[i]]+=g[u];
            if (!--indeg[e[i]]) q.emplace(e[i]);
        }
    }
}

signed main() {
    memset(h,-1,sizeof(h));
    scanf("%lld",&n);
    _rep(i,1,n-1) {
        int a,b;
        scanf("%lld %lld",&a,&b);
        add(a,b);
        indeg[b]++;
    }
    topu();
    int ans=0;
    _rep(i,1,n) ans+=f[i];
    printf("%lld",ans);
    return 0;
}