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

const int N=2005;
const int M=4000005;
const int inf=1e9;

int n;
int c[N],a[N];
int e[M],ne[M],h[N],tot;
int dis[N][N];
bool flag[N];
priority_queue<pii,vector<pii>,greater<pii>> q;
vector<int> vec;

void add(int a,int b) {
    e[tot]=b,ne[tot]=h[a],h[a]=tot++;
}

void dijkstra(int s,int g) {
    _rep(i,0,n-1) dis[s][i]=inf,flag[i]=false;
    q.emplace(pii{dis[s][s]=0,s});
    while (!q.empty()) {
        auto tp=q.top(); q.pop();
        int u=tp.second;
        if (flag[u]) continue;
        flag[u]=true;
        _graph(i,u) if (e[i]<=g && dis[s][e[i]]>dis[s][u]+1) q.emplace(pii{dis[s][e[i]]=dis[s][u]+1,e[i]});
    }
}

int main() {
    memset(h,-1,sizeof(h));
    read(n);
    _rep(i,1,n-1) read(c[i]);
    _rep(i,1,n-1) read(a[i]);
    vec.emplace_back(0);
    _rep(i,1,n-1) if (a[i]) vec.emplace_back(i);
    _rep(i,1,n-1) _rep(j,i-c[i],i-1) add(j,i);
    _rep(i,0,(int)vec.size()-2) dijkstra(vec[i],vec[i+1]);
    int ans=0;
    _rep(i,0,(int)vec.size()-2) ans+=dis[vec[i]][vec[i+1]]; // cout<<vec[i]<<" "<<vec[i+1]<<": "<<dis[vec[i]][vec[i+1]]<<endl;
    write(ans);
    return 0;
}