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

const int N=505;
const int M=1005;
const int inf=1e9;

int n,m;
int a[N];
int b[N];
int f[N][M];

int main() {
    read(n),read(m);
    _rep(i,1,n) read(a[i]);
    _rep(i,1,m) read(b[i]);
    _rep(i,2,N-1) _rep(j,0,M-1) f[i][j]=inf;
    _rep(j,0,M-1) {
        if (j==a[1]) f[1][j]=0;
        else if (j<a[1]) f[1][j]=1;
        else f[1][j]=inf;
    }
    _rep(i,2,n) _rep(j,0,a[i]) _rep(k,1,m) {
        if (j==a[i]) {
            if (j+b[k]<M) f[i][j]=min(f[i][j],f[i-1][j+b[k]]);
            if (j-b[k]>=0) f[i][j]=min(f[i][j],f[i-1][j-b[k]]);
        } else {
            if (j+b[k]<M) f[i][j]=min(f[i][j],f[i-1][j+b[k]]+1);
            if (j-b[k]>=0) f[i][j]=min(f[i][j],f[i-1][j-b[k]]+1);
        }
    }
    int ans=inf;
    _rep(j,0,M-1) ans=min(ans,f[n][j]);
    if (ans==inf) ans=-1;
    write(ans);
    return 0;
}