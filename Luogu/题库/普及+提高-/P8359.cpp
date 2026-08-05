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
    inline void writestr(char* x) { _rep(i,0,strlen(x)) putchar(x[i]); }
    inline void writestrsp(string x) { _iter(it,x) putchar(*it); putchar(' '); }
    inline void writestrsp(char* x) { _rep(i,0,strlen(x)) putchar(x[i]); putchar(' '); }
    inline void writestrln(string x) { _iter(it,x) putchar(*it); putchar(10); }
    inline void writestrln(char* x) { _rep(i,0,strlen(x)) putchar(x[i]); putchar(10); }
};

using namespace IO;

const int N=400005;

int n,m,q;
int a[N],p[N],pp[N];
bool flag[N];
int alive[N];

struct Edge {
    int x,y;
} arr[N];

struct Query {
    char op[10];
    int k;
} qs[N];

int find(int x) {
    if (p[x]==x) return p[x];
    else return p[x]=find(p[x]);
}

int find2(int x) {
    if (pp[x]==x) return pp[x];
    else return pp[x]=find2(pp[x]);
}

int main() {
    FRR("P8359_20.in");
    read(n),read(m),read(q);
    _rep(i,1,m) read(arr[i].x),read(arr[i].y);
    _rep(i,1,q) {
        readstr(qs[i].op);
        if (*(qs[i].op)=='D') read(qs[i].k),flag[qs[i].k]=true;
    }
    _rep(i,1,n) read(a[i]);
    int las=q+1;
    _rep(i,1,n) p[i]=i,pp[i]=i;
    alive[1]=q+1;
    _rep(i,1,m) if (!flag[i]) {
        if (find2(arr[i].x)!=find2(1)) alive[find(arr[i].x)]=las;
        if (find2(arr[i].y)!=find2(1)) alive[find(arr[i].y)]=las;
        if (find2(arr[i].x)!=find2(1) && find2(arr[i].y)!=find2(1)) p[find(arr[i].x)]=find(arr[i].y);
        pp[find2(arr[i].x)]=find2(arr[i].y);
    }
    _rrep(i,q,1) {
        if (*(qs[i].op)=='D') {
            int j=qs[i].k;
            if (find2(arr[j].x)!=find2(1)) alive[find(arr[j].x)]=las;
            if (find2(arr[j].y)!=find2(1)) alive[find(arr[j].y)]=las;
            if (find2(arr[j].x)!=find2(1) && find2(arr[j].y)!=find2(1)) p[find(arr[j].x)]=find(arr[j].y);
            pp[find2(arr[j].x)]=find2(arr[j].y);
        } else las=i;
        // cout<<"==="<<i<<" "<<qs[i].op<<" ===\n";
        // _rep(i,1,n) printf("test %d: %d %d\n",i,a[i],alive[find(i)]);
    }
    _rep(i,1,n) if (find2(i)!=find2(1)) alive[find(i)]=las;
    i64 ans=0;
    _rep(i,1,n) ans+=(i64)a[i]*alive[find(i)];
    // _rep(i,1,n) printf("test %d: %d %d\n",i,a[i],alive[find(i)]);
    write(ans);
    return 0;
}