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
const int M=10005;

int n,m;
int e[M],ne[M],w[M],h[N],tot;
int f[N],arr[N];
int indeg[N],outdeg[N];
bool inp[N];
queue<int> q;

void add(int a,int b,int c) {
    e[tot]=b,w[tot]=c,ne[tot]=h[a],h[a]=tot++;
}

void topu() {
    _rep(i,1,n) if (!indeg[i]) q.push(i),inp[i]=true;
    while (!q.empty()) {
        int u=q.front(); q.pop();
        if (!inp[u]) f[u]-=arr[u];
        if (f[u]<=0) continue;
        _graph(i,u) {
            f[e[i]]+=f[u]*w[i];
            if (--indeg[e[i]]==0) q.emplace(e[i]);
        }
    }
}

signed main() {
    memset(h,-1,sizeof(h));
    scanf("%lld %lld",&n,&m);
    _rep(i,1,n) scanf("%lld %lld",&f[i],&arr[i]);
    while (m--) {
        int a,b,c;
        scanf("%lld %lld %lld",&a,&b,&c);
        indeg[b]++,outdeg[a]++;
        add(a,b,c);
    }
    topu();
    bool ok=false;
    _rep(i,1,n) {
        if (f[i]<=0 || outdeg[i]) continue;
        ok=true;
        printf("%lld %lld\n",i,f[i]);
    }
    if (!ok) puts("NULL");
    return 0;
}