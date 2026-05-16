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

const int N=1000005;
const int inf=1e9;

int T,n;
int a[N];
int l[N],r[N];
int rr[N],rrr[N];

int main() {
    read(T);
    while (T--) {
        read(n);
        _rep(i,1,n) read(a[i]);
        // if (n==2) writeln(abs(a[1]-a[2])+2);
        // else if (n==3) writeln(abs(a[1]-a[3])+3);
        // else {
        int ans=abs(a[1]-a[n])+n;
        l[2]=abs(a[1]-a[2]);
        _rep(i,3,n) l[i]=min(l[i-1],abs(a[1]-a[i]));
        r[n-1]=abs(a[n-1]-a[n]);
        _rrep(i,n-2,1) r[i]=min(r[i+1],abs(a[n]-a[i]));
        _rep(i,2,n-2) ans=min(ans,l[i]+r[i+1]+n+2);
        _rep(i,2,n-2) ans=min(ans,abs(a[1]-a[i])+abs(a[i+1]-a[n])+n);
        rr[n]=inf;
        _rrep(i,n-1,1) rr[i]=min(rr[i+1],abs(a[i]-a[n]));
        _rrep(i,n-1,1) if (rr[i]!=rr[i+1]) rrr[i]=i; else rrr[i]=rrr[i+1];
        _rep(i,2,n-2) if (i+3<=rrr[i+1]) ans=min(ans,abs(a[i]-a[1])+rr[i+1]+abs(a[rrr[i+1]-1]-a[i+1])+n);
        writeln(ans);
        // }
    }
    return 0;
}