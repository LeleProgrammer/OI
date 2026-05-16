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
#define _dinic(i,u) for (int i=cur[u];~i && k<limit;i=ne[i])
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
        while (isdigit(c) && c!=EOF) x=x*10+(c-'0'),c=getchar();
        x*=s;
    }
    inline void readstr(string& x) {
        x.clear(); char c=getchar();
        while (isspace(c)) c=getchar();
        while (!isspace(c) && c!=EOF) x.push_back(c),c=getchar();
    }
    inline void readstr(char* x) {
        int idx=0; char c=getchar();
        while (isspace(c)) c=getchar();
        while (!isspace(c) && c!=EOF) x[idx++]=c,c=getchar();
        x[idx]='\0';
    }
    template<typename T> inline void write(T x) {
        if (x<0) putchar('-'),x=-x;
        if (x/10) write(x/10);
        putchar('0'+(x%10));
    }
    template<typename T> inline void writesp(T x) { write(x); putchar(' '); }
    template<typename T> inline void writeln(T x) { write(x); putchar(10); }
    inline void writestr(string x) { _iter(it,x) putchar(*it); }
    inline void writestr(char* x) { _rep(i,0,strlen(x)-1) putchar(x[i]); }
    inline void writestrsp(string x) { _iter(it,x) putchar(*it); putchar(' '); }
    inline void writestrsp(char* x) { _rep(i,0,strlen(x)-1) putchar(x[i]); putchar(' '); }
    inline void writestrln(string x) { _iter(it,x) putchar(*it); putchar(10); }
    inline void writestrln(char* x) { _rep(i,0,strlen(x)-1) putchar(x[i]); putchar(10); }
};

using namespace IO;

const int N=80005;
const int M=160005;
const int K=19;
const i64 inf=1e18;

int n,m,s;
int e[M],ne[M],h[N],tot;
int dep[N];
int f[M][K];
i64 g[N];
int vec[M],dvec[M],idx;
int fst[N];

struct node {
    int w,t,p;
    friend bool operator < (const node& a,const node& b) {
        return a.t<b.t;
    }
} arr[N];

void add(int a,int b) {
    e[tot]=b,ne[tot]=h[a],h[a]=tot++;
}

void dfs(int u,int fa,int d) {
    vec[++idx]=u;
    dvec[idx]=d;
    fst[u]=idx;
    dep[u]=d;
    _graph(i,u) {
        if (e[i]==fa) continue;
        dfs(e[i],u,d+1);
        vec[++idx]=u;
        dvec[idx]=d;
    }
}

void init() {
    _rep(i,1,idx) f[i][0]=i;
    _rep(i,1,K-1) _rep(j,1,idx) {
        if (j+(1<<(i-1))>=M || dvec[f[j][i-1]]<dvec[f[j+(1<<(i-1))][i-1]]) f[j][i]=f[j][i-1];
        else f[j][i]=f[j+(1<<(i-1))][i-1];
    }
}

int lca(int a,int b) {
    a=fst[a],b=fst[b];
    if (a>b) swap(a,b);
    int k=log2(b-a+1);
    if (dvec[f[a][k]]<dvec[f[b-(1<<k)+1][k]]) return vec[f[a][k]];
    else return vec[f[b-(1<<k)+1][k]];
}

int dis(int a,int b) {
    return dep[a]+dep[b]-2*dep[lca(a,b)];
}

int main() {
    memset(h,-1,sizeof(h));
    read(n),read(m),read(s);
    _rep(i,1,n-1) {
        int a,b;
        read(a),read(b);
        add(a,b),add(b,a);
    }
    _rep(i,1,m) {
        int w,t,p;
        read(w),read(t),read(p);
        arr[i]={w,t,p};
    }
    sort(arr+1,arr+1+m);
    dfs(1,0,1);
    init();
    _rep(i,1,m) g[i]=-inf;
    g[0]=0,arr[0]={1,0,-1};
    _rep(i,1,m) _rep(j,max(0,i-s),i-1) if (dis(arr[i].w,arr[j].w)<=arr[i].t-arr[j].t) g[i]=max(g[i],g[j]+arr[i].p);
    i64 ans=0;
    _rep(i,1,m) ans=max(ans,g[i]);
    write(ans);
    return 0;
}