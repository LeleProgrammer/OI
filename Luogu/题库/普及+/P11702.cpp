#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define FRR(file) freopen(file,"r",stdin)
#define FRW(file) freopen(file,"w",stdout)
#define TIMESTAMP cerr<<fixed<<setprecision(3)<<clock()*1.0/CLOCKS_PER_SEC<<"s"<<endl;
#define _rep(i,a,b) for (rint i=(a);i<=(b);++i)
#define _reps(i,a,b,c) for (int i=(a);i<=(b);c)
#define _rrep(i,a,b) for (rint i=(a);i>=(b);--i)
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

const int N=300005;
const int inf=2e9;

int k,n;
int a[N];
int mn[N];

int main() {
    read(n),read(k);
    i64 sum=0;
    _rep(i,1,n) read(a[i]),sum+=a[i];
    if (k==2) {
        i64 ans=0,suml=0,sumr=sum;
        _rep(i,1,n-1) {
            suml+=a[i],sumr-=a[i];
            ans=max(ans,abs(suml-sumr));
        }
        write(ans);
        return 0;
    }
    i64 ans=0,suml=0,sumr=0;
    _rep(i,1,n-k+1) {
        suml+=a[i];
        sumr+=a[n-i+1];
        ans=max(max(ans,suml-a[i+1]),sumr-a[n-i]);
    }
    rint l=1,r=n-k+1;
    suml=0;
    _rep(i,l,r) suml+=a[i];
    mn[n+1]=inf;
    _rrep(i,n,r+1) mn[i]=min(mn[i+1],a[i]);
    int cur=inf;
    while (r<=n) {
        ans=max(ans,suml-min(mn[r+1],cur));
        suml-=a[l++];
        suml+=a[++r];
        cur=min(cur,a[l-1]);
    }
    write(ans);
    return 0;
}