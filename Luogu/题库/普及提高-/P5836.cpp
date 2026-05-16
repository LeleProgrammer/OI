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

const int N=100005;
const int M=200005;
const int K=20;

int n,m;
char arr[N];
int e[M],ne[M],h[N],tot;
int dep[N],f[N][K];
int pre[N][2];

void add(int a,int b) {
    e[tot]=b,ne[tot]=h[a],h[a]=tot++;
}

void dfs(int u,int fa,int d) {
    if (arr[u]=='H') pre[u][1]++;
    else pre[u][0]++;
    dep[u]=d;
    _graph(i,u) {
        if (e[i]==fa) continue;
        f[e[i]][0]=u;
        _rep(j,1,K-1) f[e[i]][j]=f[f[e[i]][j-1]][j-1];
        pre[e[i]][0]=pre[u][0];
        pre[e[i]][1]=pre[u][1];
        dfs(e[i],u,d+1);
    }
}

int lca(int a,int b) {
    if (a==b) return a;
    if (dep[a]<dep[b]) swap(a,b);
    _rrep(i,K-1,0) if (dep[f[a][i]]>=dep[b]) a=f[a][i];
    if (a==b) return a;
    _rrep(i,K-1,0) if (f[a][i]!=f[b][i]) a=f[a][i],b=f[b][i];
    return f[a][0];
}

int main() {
    memset(h,-1,sizeof(h));
    read(n),read(m);
    readstr(arr+1);
    _rep(i,1,n-1) {
        int a,b;
        read(a),read(b);
        add(a,b),add(b,a);
    }
    dfs(1,0,1);
    while (m--) {
        int a,b;
        char c;
        read(a),read(b);
        scanf(" %c",&c);
        int sum;
        int p=lca(a,b);
        if (c=='H') sum=pre[a][1]+pre[b][1]-pre[p][1]-pre[f[p][0]][1];
        else sum=pre[a][0]+pre[b][0]-pre[p][0]-pre[f[p][0]][0];
        if (sum) putchar('1');
        else putchar('0');
    }
    return 0;
}