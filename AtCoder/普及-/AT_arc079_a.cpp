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
    template<typename T> inline void write(T x) {
        if (x<0) putchar('-'),x=-x;
        if (x/10) write(x/10);
        putchar('0'+(x%10));
    }
    template<typename T> inline void writesp(T x) { write(x); putchar(' '); }
    template<typename T> inline void writeln(T x) { write(x); putchar(10); }
};

using namespace IO;

const int N=200005;
const int M=400005;
const int inf=1e9;

int n,m;
int e[M],ne[M],h[N],tot;
bool flag[N];
int dis[N];
priority_queue<pii,vector<pii>,greater<pii>> q;

void add(int a,int b) {
    e[tot]=b,ne[tot]=h[a],h[a]=tot++;
}

void dijkstra() {
    _rep(i,1,n) flag[i]=false,dis[i]=inf;
    q.push({dis[1]=0,1});
    while (!q.empty()) {
        auto tp=q.top(); q.pop();
        int u=tp.second;
        if (flag[u]) continue;
        _graph(i,u) if (dis[e[i]]>dis[u]+1) q.push({dis[e[i]]=dis[u]+1,e[i]});
    }
}

int main() {
    memset(h,-1,sizeof(h));
    read(n),read(m);
    while (m--) {
        int a,b;
        read(a),read(b);
        add(a,b),add(b,a);
    }
    dijkstra();
    if (dis[n]>2) puts("IMPOSSIBLE");
    else puts("POSSIBLE");
    return 0;
}