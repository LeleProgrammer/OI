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

const int N=100005;
const double eps=1e-12;
const double pi=acos(-1);

int n;

int sign(double k) {
    if (fabs(k)<eps) return 0;
    else if (k>0) return 1;
    else return -1;
}

int cmp(double a,double b) {
    if (fabs(a-b)<eps) return 0;
    else if (a>b) return 1;
    else return -1;
}

struct Angle {
    double l,r;
    friend bool operator < (const Angle& a,const Angle& b) {
        if (cmp(a.l,b.l)) return cmp(a.l,b.l)<0;
        return cmp(a.r,b.r);
    }
} arr[N];

int main() {
    read(n);
    _rep(i,1,n) {
        double x,y,r;
        scanf("%lf %lf %lf",&x,&y,&r);
        double a=sqrt(x*x+y*y);
        double alpha=asin(r/a);
        if (sign(x-r)>=0 && sign(y-r)>=0) {
            double beta=atan(y/x)-alpha;
            arr[i]={beta,beta+2.0*alpha};
        } else if (sign(x-r)<0 && sign(y-r)<0) {
            arr[i]={0.0,pi/2.0};
        } else if (sign(x-r)<0) {
            double beta=atan(x/y);
            arr[i]={pi/2.0-alpha-beta,pi/2.0};
        } else {
            double beta=atan(y/x);
            arr[i]={0.0,alpha+beta};
        }
    }
    sort(arr+1,arr+1+n);
    double sum=0.0,l=arr[1].l,r=arr[1].r;
    _rep(i,2,n) {
        if (cmp(arr[i].l,r)>0) sum+=r-l,l=arr[i].l,r=arr[i].r;
        else r=max(r,arr[i].r);
    }
    sum+=r-l;
    double tot=pi/2.0;
    printf("%.3lf",(tot-sum)/tot);
    return 0;
}