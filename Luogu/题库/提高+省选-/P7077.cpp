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
typedef pair<int,int> pii;

const int N=200005;
const int M=1200005;
const int mod=998244353;

int n,m,Q,S;
int arr[N];
int e[M],ne[M],h[N],tot;
int indeg[N];
int f[N],g[N];
int res[N];
queue<int> q;

struct Operation {
    int type;
    int pos,val;
} ops[N];

void add(int a,int b) {
    e[tot]=b,ne[tot]=h[a],h[a]=tot++;
}

int dfs(int u) {
    if (~f[u]) return f[u];
    f[u]=1;
    _graph(i,u) f[u]=f[u]*dfs(e[i])%mod;
    if (ops[u].type==2) f[u]=f[u]*ops[u].val%mod;
    return f[u];
}

void topu() {
    _rep(i,1,m+n) if (!indeg[i]) q.push(i);
    q.push(S);
    g[S]=1;
    while (!q.empty()) {
        int u=q.front(); q.pop();
        if (ops[u].type==1) {
            res[ops[u].pos]+=ops[u].val*g[u];
            res[ops[u].pos]%=mod;
            continue;
        }
        int mul=1;
        _graph(i,u) {
            g[e[i]]+=g[u]*mul;
            g[e[i]]%=mod;
            mul*=f[e[i]];
            mul%=mod;
            if (--indeg[e[i]]==0) q.push(e[i]);
        }
    }
}

signed main() {
    memset(h,-1,sizeof(h));
    memset(f,-1,sizeof(f));
    scanf("%lld",&n);
    _rep(i,1,n) scanf("%lld",&arr[i]);
    scanf("%lld",&m);
    S=N-1;
    _rep(i,1,n) {
        add(S,m+i);
        ops[m+i]={1,i,arr[i]};
        indeg[m+i]++;
    }
    _rep(i,1,m) {
        int t;
        scanf("%lld",&t);
        if (t==1) {
            int p,v;
            scanf("%lld %lld",&p,&v);
            ops[i]={1,p,v};
        } else if (t==2) {
            int v;
            scanf("%lld",&v);
            ops[i]={2,0,v};
        } else {
            int k;
            scanf("%lld",&k);
            _rep(j,1,k) {
                int g;
                scanf("%lld",&g);
                add(i,g);
                indeg[g]++;
            }
        }
    }
    scanf("%lld",&Q);
    _rep(i,1,Q) {
        int f;
        scanf("%lld",&f);
        add(S,f);
        indeg[f]++;
    }
    dfs(S);
    topu();
    _rep(i,1,n) printf("%lld ",res[i]);
    return 0;
}