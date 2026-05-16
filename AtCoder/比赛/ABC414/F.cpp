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

const int N=1000005;
const int M=2000005;
const int inf=1e9;
const int K=25;

int T,n,k;
int e[M],ne[M],h[N],tot;
vector<int> vec[N];
bool flag[N];
int dis[N];
priority_queue<pii,vector<pii>,greater<pii>> q;
vector<int> g[N][K];

void add(int a,int b) {
    e[tot]=b,ne[tot]=h[a],h[a]=tot++;
}

void dfs(int u,int fa) {
    g[u][0].emplace_back(u);
    _graph(i,u) {
        if (e[i]==fa) continue;
        dfs(e[i],u);
        _rep(j,0,k-1) {
            _iter(it,g[u][j]) {
                _iter(itt,g[e[i]][k-j-1]) {
                    // cout<<"cur: "<<u<<" add: "<<*it<<" "<<*itt<<endl;
                    vec[*it].emplace_back(*itt);
                    vec[*itt].emplace_back(*it);
                }
            }
        }
        _rep(j,1,k) _iter(it,g[e[i]][j-1]) g[u][j].emplace_back(*it);
    }
    // cout<<"test: "<<u<<endl;
    // _rep(i,0,k) {
    //     printf("g[%d][%d]: ",u,i);
    //     _iter(it,g[u][i]) writesp(*it);
    //     putchar(10);
    // }
}

void dijkstra() {
    _rep(i,1,n) dis[i]=inf,flag[i]=0;
    q.emplace(pii{dis[1]=0,1});
    while (!q.empty()) {
        auto tp=q.top(); q.pop();
        int u=tp.second;
        if (flag[u]) continue;
        flag[u]=true;
        _graph(i,u) if (dis[e[i]]>dis[u]+1) q.emplace(pii{dis[e[i]]=dis[u]+1,e[i]});
    }
}

int main() {
    read(T);
    while (T--) {
        read(n),read(k);
        _rep(i,1,n) h[i]=-1; tot=0;
        _rep(i,1,n-1) {
            int a,b;
            read(a),read(b);
            add(a,b);
            add(b,a);
        }
        _rep(i,1,n) {
            vec[i].clear();
            _rep(j,0,k) g[i][j].clear();
        }
        dfs(1,0);
        _rep(i,1,n) h[i]=-1; tot=0;
        _rep(i,1,n) _iter(it,vec[i]) add(i,*it);
        dijkstra();
        _rep(i,2,n) writesp(dis[i]==inf?-1:dis[i]);
        putchar(10);
    }
    return 0;
}