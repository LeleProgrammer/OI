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

const int N=1200005;
const double pi=acos(-1);
const int mod=998244353;

int n,a,b,c;
int f[N],g[N];

int exgcd(int a,int b,int& x,int& y) {
    if (!b) {
        x=1,y=0;
        return a;
    }
    int d=exgcd(b,a%b,y,x);
    y-=a/b*x;
    return d;
}

int ksm(int a,int b) {
    if (!b) return 1;
    int k=ksm(a,b>>1);
    if (b&1) return (k*k%mod)*a%mod;
    else return k*k%mod;
}

int inverse(int a) {
    int x,y;
    exgcd(a,mod,x,y);
    x=(x%mod+mod)%mod;
    return x;
}

namespace FFT {
    int n,m,g,tt,rev[N];
    int ans[N];

    struct Complex {
        double x,y;
        friend Complex operator + (const Complex& a,const Complex& b) {
            return {a.x+b.x,a.y+b.y};
        }
        friend Complex operator - (const Complex& a,const Complex& b) {
            return {a.x-b.x,a.y-b.y};
        }
        friend Complex operator * (const Complex& a,const Complex& b) {
            return {a.x*b.x-a.y*b.y,a.x*b.y+a.y*b.x};
        }
    } a[N],b[N];

    void fft(Complex* a,int inv) {
        _rep(i,0,tt-1) if (i<rev[i]) swap(a[i],a[rev[i]]);
        _reps(mid,1,tt-1,mid<<=1) {
            Complex w={cos(pi/mid),sin(pi/mid)*inv};
            _reps(i,0,tt-1,i+=(mid<<1)) {
                Complex res={1.0,0.0};
                _rep(j,0,mid-1) {
                    auto L=a[i+j],R=a[i+j+mid]*res;
                    a[i+j]=L+R,a[i+j+mid]=L-R;
                    res=res*w;
                }
            }
        }
    }

    void solve() {
        while ((1<<g)<n+m+1) g++;
        tt=(1<<g);
        _rep(i,1,tt-1) rev[i]=(rev[i>>1]>>1)|((i&1)<<(g-1));
        fft(a,1),fft(b,1);
        _rep(i,0,tt-1) a[i]=a[i]*b[i];
        fft(a,-1);
        _rep(i,0,n+m) ans[i]=round(a[i].x/tt);
    }
    void init() {
        FFT::n=FFT::m=0;
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
    }
}

namespace NTT {
    const int G=3;

    void ntt(vector<int> &a,int inv) {
        int n=a.size();
        int j=0;
        _rep(i,0,n-1) {
            if (i<j) swap(a[i],a[j]);
            int k=n>>1;
            while ((j^=k)<k) k>>=1;
        }
        _reps(len,2,n,len<<=1) {
            int l=ksm(G,(mod-1)/len);
            if (inv) l=inverse(l);
            _reps(i,0,n-1,i+=len) {
                int w=1;
                _rep(j,0,(len>>1)-1) {
                    int L=a[i+j],R=a[i+j+len/2]*w%mod;
                    a[i+j]=(L+R)%mod;
                    a[i+j+len/2]=(L-R+mod)%mod;
                    w=w*l%mod;
                }
            }
        }
        if (inv) {
            int v=inverse(n);
            _rep(i,0,n-1) a[i]=a[i]*v%mod;
        }
    }

    vector<int> mul(vector<int> a,vector<int> b) {
        int n=1;
        int sz=a.size()+b.size()-1;
        while (n<sz) n<<=1;
        a.resize(n);
        b.resize(n);
        ntt(a,false);
        ntt(b,false);
        _rep(i,0,n-1) a[i]=a[i]*b[i]%mod;
        ntt(a,true);
        a.resize(sz);
        return a;
    }
}

void init() {
    f[0]=g[0]=1;
    _rep(i,1,N-1) f[i]=f[i-1]*i%mod,g[i]=inverse(f[i]);
}

int solve1() {
    FFT::init();
    FFT::n=FFT::m=n;
    _reps(i,0,n,i+=a) FFT::a[i]={1,0};
    _reps(i,0,n,i+=b) FFT::b[i]={1,0};
    FFT::solve();
    FFT::init();
    FFT::n=FFT::m=n;
    _rep(i,0,n) FFT::a[i]={(double)FFT::ans[i],0};
    _reps(i,0,n,i+=c) FFT::b[i]={1,0};
    FFT::solve();
    return FFT::ans[n]%mod;
}

int solve2() {
    vector<int> A(n+1,0),B(n+1,0),C(n+1,0);
    _reps(i,0,n,i+=a) A[i]=g[i];
    _reps(i,0,n,i+=b) B[i]=g[i];
    _reps(i,0,n,i+=c) C[i]=g[i];
    vector<int> S=NTT::mul(A,B);
    S.resize(n+1);
    vector<int> ans=NTT::mul(S,C);
    return f[n]*ans[n]%mod;
}

void test() {
    vector<int> A(2,0),B(2,0);
    A[0]=2,A[1]=1;
    B[0]=1,B[1]=1;
    vector<int> C=NTT::mul(A,B);
}

i32 main() {
    init();
    read(n),read(a),read(b),read(c);
    test();
    writeln(solve1());
    write(solve2());
    return 0;
}