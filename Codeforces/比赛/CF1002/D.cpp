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
    inline void readstr(string& x) {
        x.clear(); char c=getchar();
        while (isspace(c)) c=getchar();
        while (!isspace(c)) x.push_back(c),c=getchar();
    }
    inline void readstr(char* x) {
        int idx=0; char c=getchar();
        while (isspace(c)) c=getchar();
        while (!isspace(c)) x[idx++]=c,c=getchar();
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
    inline void writestr(char* x) { _rep(i,0,strlen(x)) putchar(x[i]); }
    inline void writestrsp(string& x) { _iter(it,x) putchar(*it); putchar(' '); }
    inline void writestrsp(char* x) { _rep(i,0,strlen(x)) putchar(x[i]); putchar(' '); }
    inline void writestrln(string& x) { _iter(it,x) putchar(*it); putchar(10); }
    inline void writestrln(char* x) { _rep(i,0,strlen(x)) putchar(x[i]); putchar(10); }
};

using namespace IO;

const int N=1005;
const int M=2005;
const int inf=2e9;

int T,n,m,s1,s2,ans;
set<pii> ha,hb;

struct Graph {
    int e[M],ne[M],h[N],tot;
    void add(int a,int b) {
        e[tot]=b,ne[tot]=h[a],h[a]=tot++;
    }
} g1,g2;

priority_queue<piii,vector<piii>,greater<piii>> q;
int dis[N][N];
bool flag[N][N];

void dijkstra() {
    _rep(i,1,n) _rep(j,1,n) dis[i][j]=inf,flag[i][j]=false;
    q.push(piii{dis[s1][s2]=0,pii{s1,s2}});
    while (!q.empty()) {
        auto tp=q.top(); q.pop();
        int u1=tp.second.first,u2=tp.second.second;
        if (flag[u1][u2]) continue;
        flag[u1][u2]=true;
        for (int i=g1.h[u1];~i;i=g1.ne[i]) {
            for (int j=g2.h[u2];~j;j=g2.ne[j]) {
                if (dis[g1.e[i]][g2.e[j]]>dis[u1][u2]+abs(g1.e[i]-g2.e[j])) q.emplace(piii{dis[g1.e[i]][g2.e[j]]=dis[u1][u2]+abs(g1.e[i]-g2.e[j]),pii{g1.e[i],g2.e[j]}});
                if (u1==u2 && g1.e[i]==g2.e[j]) ans=min(ans,dis[u1][u2]);
            }
        }
    }
}

int main() {
    read(T);
    while (T--) {
        memset(g1.h,-1,sizeof(g1.h)); g1.tot=0;
        memset(g2.h,-1,sizeof(g2.h)); g2.tot=0;
        read(n),read(s1),read(s2);
        read(m); ha.clear();
        while (m--) {
            int a,b;
            read(a),read(b);
            if (ha.count(pii{a,b})) continue;
            ha.emplace(pii{a,b});
            ha.emplace(pii{b,a});
            g1.add(a,b); g1.add(b,a);
        }
        read(m); hb.clear();
        while (m--) {
            int a,b;
            read(a),read(b);
            if (hb.count(pii{a,b})) continue;
            hb.emplace(pii{a,b});
            hb.emplace(pii{b,a});
            g2.add(a,b),g2.add(b,a);
        }
        bool ok=false;
        _iter(it,ha) {
            if (hb.count(pii{it->first,it->second})) {
                ok=true;
                break;
            }
        }
        if (!ok) {
            puts("-1");
            continue;
        }
        ans=inf;
        dijkstra();
        if (ans==inf) puts("-1");
        else writeln(ans);
    }
    return 0;
}