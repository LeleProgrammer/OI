#include <bits/stdc++.h>
using namespace std;

#define double long double

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

const double eps=1e-10;

int T;
double a,b,c,d,e,f,g,h;

double dis(double x1,double y1,double x2,double y2) {
    double dx=x1-x2;
    double dy=y1-y2;
    return sqrt(dx*dx+dy*dy);
}

pdd solveA(double x) {
    x=min(x,dis(a,b,c,d));
    double D=dis(a,b,c,d);
    return {a+(x*(c-a)/D),b+(x*(d-b)/D)};
}

pdd solveB(double x) {
    x=min(x,dis(e,f,g,h));
    double D=dis(e,f,g,h);
    return {e+(x*(g-e)/D),f+(x*(h-f)/D)};
}

double solve(double x) {
    auto a=solveA(x);
    auto b=solveB(x);
    return dis(a.first,a.second,b.first,b.second);
}

int main() {
    read(T);
    while (T--) {
        scanf("%Lf %Lf %Lf %Lf %Lf %Lf %Lf %Lf",&a,&b,&c,&d,&e,&f,&g,&h);
        double l=0.0,r=max(dis(a,b,c,d),dis(e,f,g,h));
        double ans=min(solve(l),solve(r));
        while (r-l>eps) {
            double len=(r-l)/3;
            double lmid=l+len,rmid=r-len;
            double L=solve(lmid),R=solve(rmid);
            ans=min(ans,L);
            ans=min(ans,R);
            if (L<R) r=rmid;
            else l=lmid;
        }
        ans=min(ans,solve(l));
        ans=min(ans,solve(r));
        printf("%.18Lf\n",ans);
    }
    return 0;
}