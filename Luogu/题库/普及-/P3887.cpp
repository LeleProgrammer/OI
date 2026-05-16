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

const int N=100005;

int K,D,M,F,q;
i64 k[N],d[N],m[N],f[N];
int lask,lasa,lasb,lasc;

bool cmp(const int& a,const int& b) {
    return a>b;
}

int main() {
    read(K),read(D),read(M),read(F);
    _rep(i,1,K) read(k[i]); sort(k+1,k+1+K,cmp);
    _rep(i,1,D) read(d[i]); sort(d+1,d+1+D,cmp);
    _rep(i,1,M) read(m[i]); sort(m+1,m+1+M,cmp);
    _rep(i,1,F) read(f[i]); sort(f+1,f+1+F,cmp);
    _rep(i,1,K) k[i]+=k[i-1];
    _rep(i,1,D) d[i]+=d[i-1];
    _rep(i,1,M) m[i]+=m[i-1];
    _rep(i,1,F) f[i]+=f[i-1];
    read(q);
    while (q--) {
        int a,b,c;
        read(a),read(b),read(c);
        printf("%.2lf\n",(double)(k[lask+1]+d[lasa+a]+m[lasb+b]+f[lasc+c]-k[lask]-d[lasa]-m[lasb]-f[lasc])/11.0);
        lask++,lasa+=a,lasb+=b,lasc+=c;
    }
    return 0;
}