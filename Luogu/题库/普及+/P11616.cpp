#include <bits/stdc++.h>
using namespace std;

#define int long long

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

const int N=10000005;
const int mod=998244353;

int T,n,m;
int a[N];
int fac[N],inv[N];

void init() {
    inv[0]=inv[1]=1;
    _rep(i,2,N-1) inv[i]=((mod-mod/i)*inv[mod%i])%mod;
    fac[0]=fac[1]=1;
    _rep(i,2,N-1) {
        fac[i]=fac[i-1]*i%mod;
        inv[i]=inv[i-1]*inv[i]%mod;
    }
}

int C(int n,int m) {
    if (n<m) return 0;
    return (fac[n]*inv[m]%mod)*inv[n-m]%mod;
}

signed main() {
    init();
    read(T);
    while (T--) {
        read(n),read(m);
        _rep(i,1,n) read(a[i]);
        int dec=0;
        _rep(i,2,n) if (a[i]<=a[i-1]) dec++;
        m-=dec,n-=dec; n--,m--;
        if (m<0) {
            puts("0");
            continue;
        }
        int ans=0;
        _rep(i,0,m) ans=(ans+C(n,i))%mod;
        writeln(ans);
    }
    return 0;
}