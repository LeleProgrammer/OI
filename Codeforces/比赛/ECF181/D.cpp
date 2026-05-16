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

const int N=200005;
const int mod=998244353;

int T,n,m;
int f[N];

struct node {
    int l,r,p,q;
    friend bool operator < (const node& a,const node& b) {
        return a.l<b.l;
    }
} arr[N];

int exgcd(int a,int b,int& x,int& y) {
    if (!b) {
        x=1,y=0;
        return a;
    }
    int d=exgcd(b,a%b,y,x);
    y-=a/b*x;
    return d;
}

int inverse(int a) {
    int x,y;
    exgcd(a,mod,x,y);
    x=(x%mod+mod)%mod;
    return x;
}

i32 main() {
    read(n),read(m);
    _rep(i,1,n) {
        int l,r,p,q;
        read(l),read(r),read(p),read(q);
        arr[i]={l,r,p,q};
    }
    sort(arr+1,arr+1+n);
    f[0]=1;
    _rep(i,1,n) f[0]=(f[0]*(arr[i].q-arr[i].p)%mod)*inverse(arr[i].q)%mod;
    // cout<<f[0]<<" "<<1*inverse(9)<<endl;
    _rep(i,1,n) {
        int las=f[arr[i].l-1];
        int p=arr[i].p*inverse(arr[i].q)%mod;
        int pp=(arr[i].q-arr[i].p)*inverse(arr[i].q)%mod;
        int k=(las*p%mod)*inverse(pp)%mod;
        // cout<<i<<": "<<k<<" "<<1*inverse(18)<<endl;
        f[arr[i].r]=(f[arr[i].r]+k)%mod;
    }
    writeln(f[m]);
    return 0;
}