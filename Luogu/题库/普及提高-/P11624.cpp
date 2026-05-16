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

const int N=1000005;
const int M=1000005;

int n,root;
int e[M],ne[M],h[N],tot;
int sz[N];
unordered_map<int,int> layer;
i64 ans;

void add(int a,int b) {
    e[tot]=b,ne[tot]=h[a],h[a]=tot++;
}

void dfs(int u,int dep) {
    sz[u]=1;
    layer[dep]++;
    _graph(i,u) {
        dfs(e[i],dep+1);
        sz[u]+=sz[e[i]];
    }
}

int main() {
    memset(h,-1,sizeof(h));
    read(n);
    _rep(i,1,n) {
        int fa;
        read(fa);
        if (fa==i) root=i;
        else add(fa,i);
    }
    sz[root]=1;
    _graph(i,root) {
        layer.clear();
        dfs(e[i],1);
        sz[root]+=sz[e[i]];
        _iter(it,layer) ans+=(i64)it->second*it->second;
    }
    _graph(i,root) ans+=(i64)sz[e[i]]*(sz[root]-sz[e[i]]-1);
    ans+=(i64)(sz[root]-1)*2;
    ans++;
    write(ans);
    return 0;
}