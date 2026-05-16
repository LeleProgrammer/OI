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
#define _riter(i,a) for (auto i=a.rbegin();i!=a.rend();++i)
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
    inline void writestr(string& x) { _iter(it,x) putchar(*it); }
    inline void writestr(char* x) { _rep(i,0,strlen(x)-1) putchar(x[i]); }
    inline void writestrsp(string& x) { _iter(it,x) putchar(*it); putchar(' '); }
    inline void writestrsp(char* x) { _rep(i,0,strlen(x)-1) putchar(x[i]); putchar(' '); }
    inline void writestrln(string& x) { _iter(it,x) putchar(*it); putchar(10); }
    inline void writestrln(char* x) { _rep(i,0,strlen(x)-1) putchar(x[i]); putchar(10); }
};

using namespace IO;

const int N=1005;
const int M=1000005;
const int inf=1e18;

int n,m,S,T;
int e[M],ne[M],h[N],f[M],c[M],tot;
int dis[N],flow[N],bk[N];
bool flag[N];

void add(int a,int b,int F,int C) {
    e[tot]=b,f[tot]=F,c[tot]=C,ne[tot]=h[a],h[a]=tot++;
    e[tot]=a,f[tot]=0,c[tot]=-C,ne[tot]=h[b],h[b]=tot++;
}

bool spfa() {
    _rep(i,1,N-1) dis[i]=flow[i]=inf,flag[i]=0;
    queue<int> q;
    q.emplace(S),dis[S]=0,flag[S]=true;
    while (!q.empty()) {
        int u=q.front(); q.pop(),flag[u]=false;
        _graph(i,u) {
            if (dis[e[i]]>dis[u]+c[i] && f[i]) {
                dis[e[i]]=dis[u]+c[i];
                flow[e[i]]=min(flow[u],f[i]);
                bk[e[i]]=i;
                if (!flag[e[i]]) q.emplace(e[i]),flag[e[i]]=true;
            }
        }
    }
    return dis[T]!=inf;
}

pii solve() {
    int F=0,C=0;
    while (spfa()) {
        F+=flow[T];
        int u=T;
        while (u!=S) {
            int i=bk[u];
            f[i]-=flow[T],f[i^1]+=flow[T];
            C+=c[i]*flow[T];
            u=e[i^1];
        }
    }
    return pii{F,C};
}

i32 main() {
    memset(h,-1,sizeof(h));
    read(n),read(m),S=N-1,T=N-2;
    _rep(i,1,n) {
        int a;
        read(a);
        add(S,i,a,0);
    }
    int tt=0;
    _rep(i,1,m) {
        int b,c;
        read(b),read(c);
        add(n+i,T,inf,-c);
        add(n+m+i,n+i,b,-inf/1e4);
        add(S,n+m+i,b,0);
        tt+=b;
    }
    _rep(i,1,n) _rep(j,1,m) add(i,n+j,1,0);
    auto g=solve();
    write(-(g.second+inf/(int)1e4*tt));
    return 0;
}