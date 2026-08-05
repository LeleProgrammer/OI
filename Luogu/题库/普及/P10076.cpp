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
#define i32 signed
#define i64 long long
#define i128 __int128
#define u32 unsigned
#define u64 unsigned long long
typedef pair<int,int> pii;
typedef pair<int,pii> piii;
typedef pair<double,double> pdd;

namespace IO {
    template<typename T> inline void read(T& x) {
        int s=1; char c=getchar(); x=0;
        while (!isdigit(c)) { if (c=='-') s=-1; c=getchar(); }
        while (isdigit(c)) x=x*10+(c-'0'),c=getchar();
        x*=s;
    }
    inline void readstr(string& x) {
        x.clear(); char c=getchar();
        while (isspace(c)) c=getchar();
        while (!isspace(c)) x.push_back(c),c=getchar();
    }
    inline void readstr(char* x) {
        int idx=0; char c=getchar();
        while (isspace(c)) c=getchar();
        while (!isspace(c)) x[++idx]=c,c=getchar();
    }
    template<typename T> inline void write(T x) {
        if (x<0) putchar('-'),x=-x;
        if (x/10) write(x/10);
        putchar('0'+(x%10));
    }
    template<typename T> inline void writesp(T x) { write(x); putchar(' '); }
    template<typename T> inline void writeln(T x) { write(x); putchar(10); }
};

using namespace IO;

const int N=1000005;
const int M=2000005;
const int K=30;

int d,T,n,q;
int e[M],ne[M],h[N],tot;
int layer[N],f[N][K];

void add(int a,int b) {
    e[tot]=b,ne[tot]=h[a],h[a]=tot++;
}

void dfs(int u,int fa,int dep) {
    layer[u]=dep;
    _graph(i,u) {
        if (e[i]==fa) continue;
        f[e[i]][0]=u;
        _rep(j,1,K-1) f[e[i]][j]=f[f[e[i]][j-1]][j-1];
        dfs(e[i],u,dep+1);
    }
}

int lca(int a,int b) {
    if (a==b) return a;
    if (layer[a]<layer[b]) swap(a,b);
    _rrep(i,K-1,0) if (layer[f[a][i]]>=layer[b]) a=f[a][i];
    if (a==b) return a;
    _rrep(i,K-1,0) if (f[a][i]!=f[b][i]) a=f[a][i],b=f[b][i];
    return f[a][0];
}

int main() {
    read(d),read(T);
    while (T--) {
        read(n),read(q); tot=0;
        _rep(i,1,n) {
            h[i]=-1;
            layer[i]=0;
            _rep(j,0,K-1) f[i][j]=0;
        }
        _rep(i,1,n-1) {
            int a,b;
            read(a),read(b);
            add(a,b); add(b,a);
        }
        dfs(1,0,1);
        while (q--) {
            int a,b,da,db;
            read(a),read(b),read(da),read(db);
            int g=lca(a,b);
            int dis=layer[a]-layer[g]+layer[b]-layer[g];
            if (da>=dis) puts("Zayin");
            else if (da>db) puts("Zayin");
            else if (db>da) puts("Ziyin");
            else puts("Draw");
        }
    }
    return 0;
}