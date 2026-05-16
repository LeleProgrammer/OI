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
    inline void writestr(string& x) { _iter(it,x) putchar(*it); }
    inline void writestr(char* x) { _rep(i,0,strlen(x)-1) putchar(x[i]); }
    inline void writestrsp(string& x) { _iter(it,x) putchar(*it); putchar(' '); }
    inline void writestrsp(char* x) { _rep(i,0,strlen(x)-1) putchar(x[i]); putchar(' '); }
    inline void writestrln(string& x) { _iter(it,x) putchar(*it); putchar(10); }
    inline void writestrln(char* x) { _rep(i,0,strlen(x)-1) putchar(x[i]); putchar(10); }
};

using namespace IO;

const int N=505;
const int M=700005;
const int inf=1e18;

int n,m,k,t,qq;
int e[M],w[M],ne[M],h[N],tot;
int dis[N][N];
int d[N];
bool flag[N];
priority_queue<pii,vector<pii>,greater<pii>> q;

void add(int a,int b,int c) {
    e[tot]=b,w[tot]=c,ne[tot]=h[a],h[a]=tot++;
}

void dijkstra(int s) {
    _rep(i,1,n) flag[i]=false,dis[s][i]=inf;
    q.emplace(pii{dis[s][s]=0,s});
    while (!q.empty()) {
        auto tp=q.top(); q.pop();
        int u=tp.second;
        if (flag[u]) continue;
        flag[u]=true;
        _graph(i,u) if (dis[s][e[i]]>dis[s][u]+w[i]) q.emplace(pii{dis[s][e[i]]=dis[s][u]+w[i],e[i]});
    }
}

i32 main() {
    memset(h,-1,sizeof(h));
    read(n),read(m);
    while (m--) {
        int a,b,c;
        read(a),read(b),read(c);
        add(a,b,c),add(b,a,c);
    }
    read(k),read(t);
    _rep(i,1,k) read(d[i]);
    _rep(i,1,k) _rep(j,i+1,k) add(d[i],d[j],t),add(d[j],d[i],t);
    _rep(i,1,n) dijkstra(i);
    read(qq);
    int cur=0;
    _rep(i,1,n) _rep(j,1,n) if (dis[i][j]!=inf) cur+=dis[i][j];
    while (qq--) {
        int op;
        read(op);
        if (op==1) {
            int x,y,t;
            read(x),read(y),read(t);
            _rep(i,1,n) {
                _rep(j,1,n) {
                    if (dis[x][y]!=inf) cur-=dis[x][y]*2;
                    dis[x][y]=dis[y][x]=min(dis[x][y],t);
                    if (dis[x][y]!=inf) cur+=dis[x][y]*2;
                    if (dis[i][j]>dis[i][x]+t+dis[y][j]) {
                        if (dis[i][j]!=inf) cur-=dis[i][j]*2;
                        dis[i][j]=dis[i][x]+t+dis[y][j];
                        dis[j][i]=dis[i][j];
                        if (dis[i][j]!=inf) cur+=dis[i][j]*2;
                    }
                }
            }
        } else if (op==2) {
            int x;
            read(x);
            _rep(i,1,k) { // x & d
                if (dis[x][d[i]]!=inf) cur-=dis[d[i]][x]*2;
                dis[d[i]][x]=dis[x][d[i]]=min(dis[d[i]][x],t);
                if (dis[x][d[i]]!=inf) cur+=dis[d[i]][x]*2;
            }
            d[++k]=x;
            _rep(i,1,n) _rep(j,1,k) { // x & all
                if (dis[i][x]!=inf) cur-=dis[i][x]*2;
                dis[x][i]=dis[i][x]=min(dis[i][x],dis[x][d[j]]+dis[d[j]][i]);
                if (dis[x][i]!=inf) cur+=dis[i][x]*2;
            }
            _rep(i,1,n) _rep(j,1,k) { // d & all
                if (dis[d[j]][i]!=inf) cur-=dis[d[j]][i]*2;
                dis[d[j]][i]=dis[i][d[j]]=min(dis[d[j]][i],dis[d[j]][x]+dis[x][i]);
                if (dis[d[j]][i]!=inf) cur+=dis[d[j]][i]*2;
            }
            _rep(i,1,n) _rep(j,1,n) { // all & all
                if (dis[i][j]>dis[i][x]+dis[x][j]) {
                    if (dis[i][j]!=inf) cur-=dis[i][j]*2;
                    dis[i][j]=dis[i][x]+dis[x][j];
                    dis[j][i]=dis[i][j];
                    if (dis[j][i]!=inf) cur+=dis[i][j]*2;
                }
            }
        } else {
            writeln(cur);
        }
    }
    return 0;
}