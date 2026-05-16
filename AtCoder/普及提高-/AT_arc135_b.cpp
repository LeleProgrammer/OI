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

const int N=300005;
const int inf=2.1e9;

int n;
int s[N],c[N];
i64 a[N];

int main() {
    read(n);
    _rep(i,1,n) read(s[i]);
    _rep(i,1,n-1) c[i]=s[i+1]-s[i];
    _rep(i,1,3) {
        int cur=c[i];
        int mn=c[i];
        int j=i;
        while (j<=n) {
            j+=3;
            cur+=c[j];
            mn=min(mn,cur);
        }
        a[i]=max(-mn,0);
    }
    if (a[1]+a[2]+a[3]>s[1]) {
        puts("No");
        return 0;
    }
    puts("Yes");
    a[1]+=s[1]-(a[1]+a[2]+a[3]);
    _rep(i,1,n) {
        a[i+3]=a[i]+c[i];
        writesp(a[i]);
    }
    writesp(a[n+1]);
    writesp(a[n+2]);
    return 0;
}