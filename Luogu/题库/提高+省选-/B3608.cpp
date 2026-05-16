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

const int N=5005;
const int M=100005;
const int inf=1e18;

int n,m,S,T;
int e[M],f[M],c[M],ne[M],h[N],tot;
int dis[N],flow[N],bk[N];
bool flag[N];
queue<int> q;

void add(int a,int b,int F,int C) {
    e[tot]=b,f[tot]=F,c[tot]=C,ne[tot]=h[a],h[a]=tot++;
    e[tot]=a,f[tot]=0,c[tot]=-C,ne[tot]=h[b],h[b]=tot++;
}

bool spfa() {
    _rep(i,1,n) dis[i]=flow[i]=inf;
    q.emplace(S),dis[S]=0,flag[S]=true;
    while (!q.empty()) {
        int u=q.front(); q.pop();
        flag[u]=false;
        _graph(i,u) {
            if (dis[e[i]]>dis[u]+c[i] && f[i]) {
                dis[e[i]]=dis[u]+c[i];
                flow[e[i]]=min(flow[u],f[i]);
                bk[e[i]]=i;
                if (!flag[e[i]]) {
                    flag[e[i]]=true;
                    q.emplace(e[i]);
                }
            }
        }
    }
    return dis[T]!=inf;
}

pii mcmf() {
    int mf=0,mc=0;
    while (spfa()) {
        mf+=flow[T];
        int u=T;
        while (u!=S) {
            f[bk[u]]-=flow[T],f[bk[u]^1]+=flow[T];
            mc+=c[bk[u]]*flow[T];
            u=e[bk[u]^1];
        }
    }
    return pii{mf,mc};
}

i32 main() {
    memset(h,-1,sizeof(h));
    read(n),read(m),S=1,T=n;
    while (m--) {
        int a,b,c,d;
        read(a),read(b),read(c),read(d);
        add(a,b,c,d);
    }
    auto ans=mcmf();
    writesp(ans.first),write(ans.second);
    return 0;
}