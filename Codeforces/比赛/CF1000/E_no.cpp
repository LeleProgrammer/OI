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

const int N=300005;
const int M=600005;

int T,n;
int e[M],ne[M],h[N],tot;
int f[N],g[N],sz[N];

void add(int a,int b) {
    e[tot]=b,ne[tot]=h[a],h[a]=tot++;
}

void dfs(int u,int fa) {
    sz[u]=1;
    _graph(i,u) {
        if (e[i]==fa) continue;
        dfs(e[i],u);
        sz[u]+=sz[e[i]];
        g[u]+=g[e[i]]+sz[e[i]];
    }
}

signed main() {
    scanf("%lld",&T);
    while (T--) {
        scanf("%lld",&n);
        _rep(i,1,n) h[i]=-1,f[i]=g[i]=0;
        tot=0;
        _rep(i,1,n-1) {
            int a,b;
            scanf("%lld %lld",&a,&b);
            add(a,b); add(b,a);
        }
        dfs(1,0);
        printf("g: "); _rep(i,1,n) printf("g[%lld] = %lld\n",i,g[i]);
    }
}

/*
1
11
2 1
2 3
2 4
4 5
6 5
5 7
4 8
8 9
7 10
10 11

ans: 29
*/