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

const int N=200005;
const int M=400005;

int n,m;
int e[M],ne[M],h[N],tot;
int p[N];
bool vis[N];
bool flag[N];
queue<int> s;
vector<piii> ans;
unordered_set<int> rem;

void add(int a,int b) {
    e[tot]=b,ne[tot]=h[a],h[a]=tot++;
}

int find(int x) {
    if (p[x]==x) return p[x];
    else return p[x]=find(p[x]);
}

void dfs(int u,int las) {
    vis[u]=true;
    _graph(i,u) {
        if ((i^1)==las) continue;
        if (find(e[i])==find(u)) s.emplace(i);
        else p[find(e[i])]=find(u),dfs(e[i],i);
    }
}

int main() {
    memset(h,-1,sizeof(h));
    read(n),read(m);
    _rep(i,1,n) p[i]=i;
    while (m--) {
        int a,b;
        read(a),read(b);
        add(a,b); add(b,a);
    }
    _rep(i,1,n) if (!vis[i]) dfs(i,-1),rem.emplace(i);
    while ((int)rem.size()>1) {
        int i=s.front(); s.pop();
        if (flag[i/2+1]) continue;
        flag[i/2+1]=true;
        int from=e[i^1],to=e[i];
        int cur;
        _iter(it,rem) {
            if (find(*it)!=find(to)) {
                cur=*it;
                break;
            }
        }
        p[find(from)]=find(cur);
        rem.erase(cur);
        ans.emplace_back(piii{i/2+1,pii{to,cur}});
    }
    writeln(ans.size());
    _iter(it,ans) writesp(it->first),writesp(it->second.first),writeln(it->second.second);
    return 0;
}