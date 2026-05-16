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
const int M=400005;

int T,n;
int l[N],r[N];
int e[M],ne[M],h[N],tot;
int inc,f[N];

void add(int a,int b) {
    e[tot]=b,ne[tot]=h[a],h[a]=tot++;
}

void dfs(int u,int fa) {
    f[u]=-1;
    _graph(i,u) {
        if (e[i]==fa) continue;
        dfs(e[i],u);
        f[u]=max(f[u],f[e[i]]);
    }
    if (f[u]==-1) {
        f[u]=l[u];
        return;
    }
    f[u]=max(min(f[u],r[u]),l[u]);
    _graph(i,u) {
        if (e[i]==fa) continue;
        inc+=max(0LL,f[e[i]]-f[u]);
    }
}

signed main() {
    scanf("%lld",&T);
    while (T--) {
        scanf("%lld",&n); tot=inc=0;
        _rep(i,1,n) h[i]=-1;
        _rep(i,1,n) scanf("%lld %lld",&l[i],&r[i]);
        _rep(i,1,n-1) {
            int a,b;
            scanf("%lld %lld",&a,&b);
            add(a,b); add(b,a);
        }
        dfs(1,0);
        // printf("inc: %lld\n",inc);
        printf("%lld\n",f[1]+inc);
    }
    return 0;
}

/*
1
4
1 1
1 1
1 1
0 0
1 4
2 4
3 4

ans: 3
*/