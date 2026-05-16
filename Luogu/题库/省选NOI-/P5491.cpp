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

int T,n,p,I2;

int MOD(i64 x,int p) {
    return (x%p+p)%p;
}

struct Real {
    i64 x,y;
    friend Real operator + (const Real& a,const Real& b) {
        return {MOD((i64)a.x+b.x,p),MOD((i64)a.y+b.y,p)};
    }
    friend Real operator - (const Real& a,const Real& b) {
        return {MOD((i64)a.x-b.x,p),MOD((i64)a.y-b.y,p)};
    }
    friend Real operator * (const Real& a,const Real& b) {
        return {MOD((i64)a.x*b.x+(((i64)a.y*b.y%p)*I2),p),MOD((i64)a.y*b.x+(i64)a.x*b.y,p)};
    }
};

int ksm(int a,int b,int p) {
    if (!b) return 1;
    if (b==1) return a;
    int k=ksm(a,b>>1,p);
    if (b&1) return ((i64)k*k%p)*a%p;
    else return (i64)k*k%p;
}

Real ksm(Real a,int b,int p) {
    if (!b) return {1,0};
    if (b==1) return a;
    Real k=ksm(a,b>>1,p);
    if (b&1) return k*k*a;
    else return k*k;
}

bool euler_check(int n,int p) {
    return ksm(n,p-1>>1,p)==1;
}

pii cipolla(int n,int p) {
    int a=rand()%p;
    while (euler_check(MOD((i64)a*a-n,p),p)) a=rand()%p;
    I2=MOD((i64)a*a-n,p);
    int ans=MOD(ksm(Real{a,1},p+1>>1,p).x,p);
    return {ans,MOD(-ans,p)};
}

int main() {
    srand(time(0));
    read(T);
    while (T--) {
        read(n),read(p); n%=p;
        if (!n) {
            puts("0");
            continue;
        }
        if (!euler_check(n,p)) puts("Hola!");
        else {
            auto ans=cipolla(n,p);
            if (ans.first>ans.second) swap(ans.first,ans.second);
            if (ans.first==ans.second) writeln(ans.first);
            else writesp(ans.first),writeln(ans.second);
        }
    }
    return 0;
}