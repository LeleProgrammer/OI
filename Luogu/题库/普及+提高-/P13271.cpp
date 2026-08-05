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

const int N=1000005;
const int M=2000005;
const int inf=1e18;

int c,n,m,k;
int in[N],de[N];
int pre[N];
int outdeg[N];
int pod[N];
vector<pii> vec[N];
int e[M],ne[M],w[M],h[N],tot;
int dis[N];
bool flag[N];
priority_queue<pii,vector<pii>,greater<pii>> q;

int get(int u,int k) {
    return pod[u-1]+k;
}

void add(int a,int b,int c) {
    e[tot]=b,w[tot]=c,ne[tot]=h[a],h[a]=tot++;
}

void dijkstra() {
    _rep(i,1,N-1) dis[i]=inf;
    q.emplace(pii{dis[get(1,1)]=0,get(1,1)});
    while (!q.empty()) {
        auto tp=q.top(); q.pop();
        int u=tp.second;
        if (flag[u]) continue;
        flag[u]=true;
        _graph(i,u) if (dis[e[i]]>dis[u]+w[i]) q.emplace(pii{dis[e[i]]=dis[u]+w[i],e[i]});
    }
}

i32 main() {
    memset(h,-1,sizeof(h));
    read(c),read(n),read(m),read(k);
    _rep(i,1,k-1) read(in[i]);
    _rep(i,2,k) read(de[i]);
    _rep(i,2,k) pre[i]=pre[i-1]+de[i];
    _rep(i,1,n) {
        int d;
        read(d);
        outdeg[i]=d;
        while (d--) {
            int y,z;
            read(y),read(z);
            vec[i].emplace_back(pii{y,z});
        }
    }
    _rep(i,1,n) pod[i]=pod[i-1]+outdeg[i]+1;
    _rep(i,1,n) {
        _rep(j,0,(int)vec[i].size()-1) {
            int t=min(j+1,outdeg[vec[i][j].first]);
            if (t) add(get(i,j+1),get(vec[i][j].first,t),vec[i][j].second+pre[j+1]-pre[t]);
            add(get(i,j+1),get(vec[i][j].first,outdeg[vec[i][j].first]+1),vec[i][j].second);
        }
        _rep(j,1,outdeg[i]-1) {
            add(get(i,j),get(i,j+1),in[j]);
            add(get(i,j+1),get(i,j),de[j+1]);
        }
    }
    dijkstra();
    _rep(i,1,n) {
        int ans=inf;
        _rep(j,1,outdeg[i]+1) ans=min(ans,dis[get(i,j)]);
        if (ans==inf) writesp(-1);
        else writesp(ans);
    }
    return 0;
}