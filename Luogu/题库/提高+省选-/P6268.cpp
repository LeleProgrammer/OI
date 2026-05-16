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

const int N=1005;
const int M=6005;
const int inf=1e9;

int n,m,S,T;
int e[M],ne[M],h[N],f[M],tot;
int sx[N];
int cur[N],dep[N];

void add(int a,int b,int c) {
    e[tot]=b,f[tot]=c,ne[tot]=h[a],h[a]=tot++;
    e[tot]=a,f[tot]=0,ne[tot]=h[b],h[b]=tot++;
}

struct Edge {
    int a,b;
} arr[M];

void init(int u) {
    _graph(i,u) if (!~sx[e[i]]) sx[e[i]]=(sx[u]^1),init(e[i]);
}

bool bfs() {
    memset(dep,0,sizeof(dep));
    memset(cur,0,sizeof(cur));
    queue<int> q;
    q.emplace(S),dep[S]=1,cur[S]=h[S];
    while (!q.empty()) {
        int u=q.front(); q.pop();
        _graph(i,u) {
            if (!dep[e[i]] && f[i]) {
                dep[e[i]]=dep[u]+1;
                cur[e[i]]=h[e[i]];
                if (e[i]==T) return true;
                q.emplace(e[i]);
            }
        }
    }
    return false;
}

int dfs(int u,int limit) {
    if (u==T) return limit;
    int k=0;
    _dinic(i,u) {
        if (dep[e[i]]==dep[u]+1 && f[i]) {
            int ret=dfs(e[i],min(limit-k,f[i]));
            if (!ret) dep[e[i]]=0;
            f[i]-=ret,f[i^1]+=ret,k+=ret;
        }
    }
    return k;
}

int dinic() {
    int ans=0,k;
    while (bfs()) while (k=dfs(S,inf)) ans+=k;
    return ans;
}

int main() {
    memset(h,-1,sizeof(h));
    memset(sx,-1,sizeof(sx));
    read(n),read(m),S=N-1,T=N-2;
    _rep(i,1,m) {
        int a,b;
        read(a),read(b);
        arr[i]={++a,++b};
        add(a,b,0);
    }
    _rep(i,1,n) if (!~sx[i]) sx[i]=0,init(i);
    memset(h,-1,sizeof(h)),tot=0;
    _rep(i,1,m) {
        int a=arr[i].a,b=arr[i].b;
        if (sx[a]==1) swap(a,b);
        add(a,b,1);
    }
    _rep(i,1,n) if (!sx[i]) add(S,i,1); else add(i,T,1);
    write(n-dinic());
    return 0;
}