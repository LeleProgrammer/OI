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
    inline void writestr(char* x) { _rep(i,0,strlen(x)) putchar(x[i]); }
    inline void writestrsp(string x) { _iter(it,x) putchar(*it); putchar(' '); }
    inline void writestrsp(char* x) { _rep(i,0,strlen(x)) putchar(x[i]); putchar(' '); }
    inline void writestrln(string x) { _iter(it,x) putchar(*it); putchar(10); }
    inline void writestrln(char* x) { _rep(i,0,strlen(x)) putchar(x[i]); putchar(10); }
};

using namespace IO;

const int N=10005;
const int M=200005;
const int K=25;
const int inf=1e9;

int T,n,m,k,s,t;
int e[M],w[M],ne[M],h[N],tot;
int a[N];
int dis[N][K];
bool flag[N][K];
priority_queue<piii,vector<piii>,greater<piii>> q;

void add(int a,int b,int c) {
    e[tot]=b,w[tot]=c,ne[tot]=h[a],h[a]=tot++;
}

void dijkstra() {
    _rep(i,1,n) _rep(j,0,k<<1) dis[i][j]=inf,flag[i][j]=0;
    q.emplace(piii{dis[s][k+a[s]]=0,pii{s,k+a[s]}});
    while (!q.empty()) {
        auto tp=q.top(); q.pop();
        int u=tp.second.first,g=tp.second.second;
        if (flag[u][g]) continue;
        flag[u][g]=1;
        _graph(i,u) if (g+a[e[i]]>=0 && g+a[e[i]]<=2*k && dis[e[i]][g+a[e[i]]]>dis[u][g]+w[i]) q.emplace(piii{dis[e[i]][g+a[e[i]]]=dis[u][g]+w[i],pii{e[i],g+a[e[i]]}});
    }
}

int main() {
    read(T);
    while (T--) {
        read(n),read(m),read(k),tot=0;
        _rep(i,1,n) h[i]=-1;
        _rep(i,1,n) {
            read(a[i]);
            if (a[i]==2) a[i]=-1;
        }
        while (m--) {
            int a,b,c;
            read(a),read(b),read(c);
            add(a,b,c),add(b,a,c);
        }
        read(s),read(t);
        dijkstra();
        int ans=inf;
        _rep(i,0,k<<1) ans=min(ans,dis[t][i]);
        if (ans==inf) ans=-1;
        writeln(ans);
    }
    return 0;
}