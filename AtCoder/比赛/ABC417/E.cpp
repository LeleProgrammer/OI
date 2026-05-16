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
    inline void writestr(string& x) { _iter(it,x) putchar(*it); }
    inline void writestr(char* x) { _rep(i,0,strlen(x)-1) putchar(x[i]); }
    inline void writestrsp(string& x) { _iter(it,x) putchar(*it); putchar(' '); }
    inline void writestrsp(char* x) { _rep(i,0,strlen(x)-1) putchar(x[i]); putchar(' '); }
    inline void writestrln(string& x) { _iter(it,x) putchar(*it); putchar(10); }
    inline void writestrln(char* x) { _rep(i,0,strlen(x)-1) putchar(x[i]); putchar(10); }
};

using namespace IO;

const int N=1005;
const int M=100005;

int T,n,m,x,y;
int e[M],ne[M],h[N],tot;
int dep[N];
bool flag[N];
vector<int> ans;

void add(int a,int b) {
    e[tot]=b,ne[tot]=h[a],h[a]=tot++;
}

void dfs(int u,int d) {
    // cout<<"test: "<<u<<" "<<d<<endl;
    dep[u]=d;
    bool ok=false;
    vector<int> vec;
    _graph(i,u) {
        if (e[i]==y) ok=true;
        if (dep[e[i]] || e[i]==y) continue;
        vec.emplace_back(e[i]);
    }
    sort(vec.begin(),vec.end());
    _iter(it,vec) {
        if (!dep[*it]) dfs(*it,d+1);
    }
    if (ok && !dep[y]) dfs(y,d+1);
    // cout<<"back"<<endl;
}

void dfs2(int u) {
    if (u==y) flag[u]=true;
    else {
        _graph(i,u) {
            if (dep[e[i]]!=dep[u]+1) continue;
            dfs2(e[i]);
            if (flag[e[i]]) flag[u]=true;
        }
    }
    // cout<<"flag: "<<u<<" "<<flag[u]<<endl;
}

void dfs3(int u) {
    ans.emplace_back(u);
    if (u==y) return;
    vector<int> vec;
    _graph(i,u) {
        if (dep[e[i]]<dep[u]) continue;
        vec.emplace_back(e[i]);
    }
    sort(vec.begin(),vec.end());
    _iter(it,vec) {
        if (!flag[*it]) continue;
        dfs3(*it);
        break;
    }
}

int main() {
    read(T);
    while (T--) {
        tot=0;
        ans.clear();
        read(n),read(m),read(x),read(y);
        _rep(i,1,n) dep[i]=0,h[i]=-1,flag[i]=0;
        while (m--) {
            int a,b;
            read(a),read(b);
            add(a,b),add(b,a);
        }
        dfs(x,1);
        dfs2(x);
        dfs3(x);
        _iter(it,ans) writesp(*it);
        putchar(10);
    }
    return 0;
}