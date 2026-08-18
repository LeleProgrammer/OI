#include <bits/stdc++.h>
using namespace std;

// ======== EXTRA DEFINITION ========
// ==================================

struct _custom_hash {
    static uint64_t process(uint64_t x) {
        x+=0x9e3779b97f4a7c15;
        x=(x^(x>>30))*0xbf58476d1ce4e5b9;
        x=(x^(x>>27))*0x94d049bb133111eb;
        return x^(x>>31);
    }

    size_t operator () (uint64_t x) const {
        static const uint64_t rnd=chrono::steady_clock::now().time_since_epoch().count();
        return process(x+rnd);
    }

    template<typename A,typename B>
    size_t operator () (const pair<A,B>& p) const {
        auto h1=operator()(p.first);
        auto h2=operator()(p.second);
        return h1^(h2<<1);
    }
};

#ifdef PBDS

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/hash_policy.hpp>
#include <ext/pb_ds/priority_queue.hpp>
#include <ext/pb_ds/trie_policy.hpp>

template<typename T> using _set=__gnu_pbds::tree<T,__gnu_pbds::null_type,less<T>,__gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update>;
template<typename T> using _multiset=__gnu_pbds::tree<T,__gnu_pbds::null_type,less_equal<T>,__gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update>;
template<typename Key,typename Value> using _map=__gnu_pbds::tree<Key,Value,less<Value>,__gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update>;
template<typename Key,typename Value> using _multimap=__gnu_pbds::tree<Key,Value,less_equal<Value>,__gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update>;
template<typename Key,typename Val> using _unordered_map=__gnu_pbds::gp_hash_table<Key,Val>;
template<typename Key,typename Val> using _hash=__gnu_pbds::gp_hash_table<Key,Val,_custom_hash>;

#endif

// ======== EXTRA DEFINITION ========
// ==================================

const int N=25;
const int M=2;
const int K=log2((long double)N)+2;
const int mod=998244353;
const int inf=2e9;
const double pi=acos(-1);
const double eps=1e-9;

#ifdef OPTIMIZE
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#endif

#define endl '\n'

#define FRR(file) freopen(file,"r",stdin)
#define FRW(file) freopen(file,"w",stdout)
#define FRE(file) freopen(file,"w",stderr)

#define TIMESTAMP cerr<<fixed<<setprecision(3)<<clock()*1.0/CLOCKS_PER_SEC<<"s"<<endl;

#define _rep(i,a,b) for (int i=(a);i<=(b);++i)
#define _reps(i,a,b,c) for (int i=(a);i<=(b);c)
#define _rrep(i,a,b) for (int i=(a);i>=(b);--i)
#define _rreps(i,a,b,c) for (int i=(a);i>=(b);c)
#define _repb(i,n) for (int i=0;i<(1<<(n));++i)
#define _rrepb(i,n) for (int i=(1<<(n))-1;~i;--i) 
#define _iter(i,a) for (auto i=a.begin();i!=a.end();++i)
#define _riter(i,a) for (auto i=a.rbegin();i!=a.rend();++i)
#define _graph(i,u) for (int i=h[u];~i;i=ne[i])
#define _dinic(i,u) for (int i=cur[u];~i && k<limit;i=ne[i])
#define _for(i,a) for (auto& i:a)
#define _all(x) (x).begin(),(x).end()
#define _rall(x) (x).rbegin(),(x).rend()
#define _per(x) next_permutation(_all(x))
#define _pera(x,fr,to) next_permutation((x)+(fr),(x)+(to)+1)
#define _rper(x) prev_permutation(_all(x))
#define _rpera(x,fr,to) prev_permutation((x)+(fr),(x)+(to)+1)
#define _rev(x) reverse(_all(x))
#define _reva(x,fr,to) reverse((x)+(fr),(x)+(to)+1)
#define _sort(x) sort(_all(x))
#define _sorta(x,fr,to) sort((x)+(fr),(x)+(to)+1)
#define _sortf(type) inline friend bool operator < (const type& a,const type& b)
#define _rsort(x) sort(_rall(x))
#define _rsorta(x,fr,to) do { _sorta(x,fr,to),_reva(x,fr,to); } while (0)
#define _unique(x) (x).erase(unique(_all(x)),x.end())

inline void _yes(const bool& a) { puts(a?"yes":"no"); }
inline void _Yes(const bool& a) { puts(a?"Yes":"No"); }
inline void _YES(const bool& a) { puts(a?"YES":"NO"); }
inline void _possible(const bool& a) { puts(a?"possible":"impossible"); }
inline void _Possible(const bool& a) { puts(a?"Possible":"Impossible"); }
inline void _POSSIBLE(const bool& a) { puts(a?"POSSIBLE":"IMPOSSIBLE"); }

#define rint register int
#define i8 int8_t
#define i16 int16_t
#define i32 int32_t
#define i64 int64_t
#define i128 __int128
#define u8 uint8_t
#define u16 uint16_t
#define u32 uint32_t
#define u64 uint64_t
#define u128 unsigned __int128
#define f128 __float128

#define _sqrt(x) __builtin_sqrt(x)

template<typename T> T lowbit(T x) { return x&-x; }
template<typename T> T popc(T x) { return __builtin_popcountll(x); }
template<typename T,typename S> T kthbit(T x,S k) { return (x>>k)&1; }
template<typename T,typename S> T setbit(T x,S k) { return (x|(((T)1)<<k)); }
template<typename T,typename S> T clrbit(T x,S k) { return (x&~(((T)1)<<k)); }
template<typename T,typename S> T flpbit(T x,S k) { return (x^(((T)1)<<k)); }

template<typename A,typename B> inline size_t LB(const A& a,const B& b) { return lower_bound((a).begin(),(a).end(),(b))-(a).begin(); }
template<typename A,typename B> inline size_t UB(const A& a,const B& b) { return upper_bound((a).begin(),(a).end(),(b))-(a).begin(); }
template<typename A,typename B> inline auto LB2(const A& a,const B& b) { return (a).lower_bound(b); }
template<typename A,typename B> inline auto UB2(const A& a,const B& b) { return (a).upper_bound(b); }

template<typename A,typename B> inline void chmin(A& a,const B& b) { (a>b)?(a=b):a; }
template<typename A,typename B> inline void chmax(A& a,const B& b) { (a<b)?(a=b):a; }
template<typename T> inline T min3(const T& a,const T& b,const T& c) { return min(a,min(b,c)); }
template<typename T> inline T max3(const T& a,const T& b,const T& c) { return max(a,max(b,c)); }
template<typename T> inline T min4(const T& a,const T& b,const T& c,const T& d) { return min(a,min(b,min(c,d))); }
template<typename T> inline T max4(const T& a,const T& b,const T& c,const T& d) { return max(a,max(b,max(c,d))); }
template<typename T> inline T min5(const T& a,const T& b,const T& c,const T& d,const T& e) { return min(a,min(b,min(c,min(d,e)))); }
template<typename T> inline T max5(const T& a,const T& b,const T& c,const T& d,const T& e) { return max(a,max(b,max(c,max(d,e)))); }
template<typename T> inline T min6(const T& a,const T& b,const T& c,const T& d,const T& e,const T& f) { return min(a,min(b,min(c,min(d,min(e,f))))); }
template<typename T> inline T max6(const T& a,const T& b,const T& c,const T& d,const T& e,const T& f) { return max(a,max(b,max(c,max(d,max(e,f))))); }

const int dx4[4]={0,1,0,-1};
const int dy4[4]={-1,0,1,0};
const int dx8[8]={-1,-1,-1,0,0,1,1,1};
const int dy8[8]={-1,0,1,-1,1,-1,0,1};

using pii=pair<int,int>;
using pdd=pair<double,double>;

template<typename T> using priomx=priority_queue<T,vector<T>,less<T>>;
template<typename T> using priomn=priority_queue<T,vector<T>,greater<T>>;

constexpr i64 pw10[]={
    1LL,
    10LL,
    100LL,
    1000LL,
    10000LL,
    100000LL,
    1000000LL,
    10000000LL,
    100000000LL,
    1000000000LL,
    10000000000LL,
    100000000000LL,
    1000000000000LL,
    10000000000000LL,
    100000000000000LL,
    1000000000000000LL,
    10000000000000000LL,
    100000000000000000LL,
    1000000000000000000LL
};

class NullStream {
public:
    template<typename T> NullStream& operator << (const T&) { return *this; }
    inline NullStream& operator << (ostream& (*)(ostream&)) { return *this; }
    inline NullStream& operator << (ios_base& (*)(ios_base&)) { return *this; }
};

static NullStream null_stream;

#ifndef DEBUG
#define cerr null_stream
#define _debug(...) 42
#define __assert(c) 42
#else
inline void _debug_out() { cerr<<endl; }
template<typename A,typename... B> inline void _debug_out(A a,B... b) { cerr<<a<<" "; _debug_out(b...); }
#define _debug(...) cerr<<"["<<#__VA_ARGS__<<"]: ", _debug_out(__VA_ARGS__)
#define __assert(c) \
    do { \
        if (!(c)) { \
            cerr<<"Assertion failed: " #c<<" at "<<__FILE__<<":"<<__LINE__<<endl; \
            abort(); \
        } \
    } while (0)
#endif

mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());
i64 randint(i64 a,i64 b) {
    uniform_int_distribution<i64> dist(a,b);
    return dist(rnd);
}

namespace IO {
    template<typename T> inline void read(T& x) { int s=1; char c=getchar(); x=0; while (!isdigit(c)) { if (c=='-') s=-1; c=getchar(); } while (isdigit(c) && c!=EOF) x=x*10+(c-'0'),c=getchar(); x*=s; }
    inline void readstr(string& x) { x.clear(); char c=getchar(); while (isspace(c)) c=getchar(); while (!isspace(c) && c!=EOF) x.push_back(c),c=getchar(); }
    inline void readstr(char* x) { int idx=0; char c=getchar(); while (isspace(c)) c=getchar(); while (!isspace(c) && c!=EOF) x[idx++]=c,c=getchar(); x[idx]='\0'; }
    template<typename T> inline void write(T x) { if (x<0) putchar('-'),x=-x; if (x/10) write(x/10); putchar('0'+(x%10)); }
    template<typename T> inline void writesp(T x) { write(x); putchar(' '); }
    template<typename T> inline void writeln(T x) { write(x); putchar(10); }
    inline void writestr(const string& x) { _iter(it,x) putchar(*it); }
    inline void writestr(char* x) { _rep(i,0,strlen(x)-1) putchar(x[i]); }
    inline void writestrsp(const string& x) { _iter(it,x) putchar(*it); putchar(' '); }
    inline void writestrsp(char* x) { _rep(i,0,strlen(x)-1) putchar(x[i]); putchar(' '); }
    inline void writestrln(const string& x) { _iter(it,x) putchar(*it); putchar(10); }
    inline void writestrln(char* x) { _rep(i,0,strlen(x)-1) putchar(x[i]); putchar(10); }
    template<typename T,typename... Args> inline void read(T& arg,Args&... args) { read(arg),read(args...); }
    template<typename T,typename... Args> inline void writesp(const T& arg,const Args&... args) { writesp(arg),writesp(args...); }
    template<typename T,typename... Args> inline void writeln(const T& arg,const Args&... args) { writeln(arg),writeln(args...); }
    template<typename T,typename... Args> inline void writespln(const T& arg,const Args&... args) { writesp(arg),writesp(args...),putchar(10); }
}

namespace Math {
    inline int gcd(int a,int b) { return (!b)?a:gcd(b,a%b); }
    inline int lcm(int a,int b) { return a/gcd(a,b)*b; }
    inline int exgcd(int a,int b,int& x,int& y) { if (!b) { x=1,y=0; return a; } int d=exgcd(b,a%b,y,x); y-=a/b*x; return d; }
    inline int inverse(int a) { int x,y; exgcd(a,mod,x,y); x=(x%mod+mod)%mod; return x; }
    inline int inverse(int a,int p) { int x,y; exgcd(a,p,x,y); x=(x%p+p)%p; return x; }
    inline int ksm(int a,int b) { if (!b) return 1; int k=ksm(a,b>>1); if (b&1) return (k*k%mod)*a%mod; else return k*k%mod; }
    inline int ksm2(int a,int b) { if (!b) return 1; int k=ksm2(a,b>>1); if (b&1) return k*k*a; else return k*k; }
    inline int ksm(int a,int b,int mod) { if (!b) return 1; int k=ksm(a,b>>1,mod); if (b&1) return (k*k%mod)*a%mod; else return k*k%mod; }

    int idx;
    int* pri=nullptr;
    bool* flag=nullptr;
    int* mu=nullptr;
    int* phi=nullptr;
    int _math_mul_n;

    inline void init_mul(size_t n=N,bool fmu=false,bool fphi=false) {
        _math_mul_n=n;
        if (pri!=nullptr) delete[] pri;
        if (flag!=nullptr) delete[] flag;
        if (mu!=nullptr) delete[] mu;
        if (phi!=nullptr) delete[] phi;
        pri=new int[n];
        flag=new bool[n];
        if (fmu) mu=new int[n],memset(mu,0,sizeof(int)*n);
        if (fphi) phi=new int[n],memset(phi,0,sizeof(int)*n);
        memset(pri,0,sizeof(int)*n);
        memset(flag,0,sizeof(bool)*n);
        idx=0;
        if (fmu) mu[1]=1;
        if (fphi) phi[1]=1;
        _rep(i,2,n-1) {
            if (!flag[i]) {
                pri[++idx]=i;
                if (fmu) mu[i]=-1;
                if (fphi) phi[i]=i-1;
            }
            _rep(j,1,idx) {
                if (i*pri[j]>=n) break;
                flag[i*pri[j]]=true;
                if (i%pri[j]==0) {
                    if (fphi) phi[i*pri[j]]=phi[i]*pri[j];
                    break;
                }
                if (fphi) phi[i*pri[j]]=phi[i]*phi[pri[j]];
                if (fmu) mu[i*pri[j]]=-mu[i];
            }
        }
    }

    int* f=nullptr;
    int* g=nullptr;
    int _math_fact_n;

    inline void init_fact(size_t n=N) {
        _math_fact_n=n;
        if (f!=nullptr) delete[] f;
        if (g!=nullptr) delete[] g;
        f=new int[n];
        g=new int[n];
        f[0]=g[0]=1;
        _rep(i,1,n-1) f[i]=f[i-1]*i%mod;
        g[n-1]=inverse(f[n-1]);
        _rrep(i,n-2,1) g[i]=g[i+1]*(i+1)%mod;
    }

    inline int C(int n,int m) { return (f[n]*g[m]%mod)*g[n-m]%mod; }
    inline int A(int n,int m) { return f[n]*g[n-m]%mod; }

    int _millar_rabin_base[]={2,325,9375,28178,450775,9780504,1795265022};

    inline bool millar_rabin(int n) {
        if (n==1) return false;
        else if (n%2==0) return n==2;
        else if (n%3==0) return n==3;
        int u=n-1,s=0;
        while (!(u&1)) u>>=1,s++;
        _rep(g,0,6) {
            int k=_millar_rabin_base[g]%n;
            if (!k) continue;
            k=ksm(k,u,n);
            if (k==1) continue;
            int t=0;
            while (t<s) {
                if (k==n-1) break;
                k=(i128)k*k%n;
                t++;
            }
            if (t==s) return false;
        }
        return true;
    }

    inline int pollard_rho(int n) {
        if (n%2==0) return 2;
        int x=0,y=0,c=randint(1,n-1);
        int t=1;
        while (true) {
            x=y;
            int prod=1;
            _rep(i,1,t) {
                y=(y*y+c)%n;
                prod=prod*labs(x-y)%n;
                if (i%127==0) {
                    int d=Math::gcd(prod,n);
                    if (d>1) return d;
                }
            }
            int d=Math::gcd(prod,n);
            if (d>1) return d;
            t<<=1;
        }
        return 42;
    }
}

template<typename BasicType,size_t n>
class BigInt {
public:
    BasicType* arr;

    BigInt(): arr(new BasicType[n]()) {}

    BigInt(const BigInt& oth): arr(new BasicType[n]) {
        copy(oth.arr,oth.arr+n,arr);
    }

    BigInt(BigInt&& oth) noexcept: arr(oth.arr) {
        oth.arr=nullptr;
    }

    BigInt& operator = (const BigInt& b) {
        if (this!=&b) copy(b.arr,b.arr+n,arr);
        return *this;
    }

    BigInt& operator = (BigInt&& b) noexcept {
        if (this!=&b) {
            delete[] arr;
            arr=b.arr;
            b.arr=nullptr;
        }
        return *this;
    }

    ~BigInt() {
        delete[] arr;
    }

    inline void swap(BigInt& oth) noexcept {
        swap(arr,oth.arr);
    }

    inline BasicType& operator [] (size_t pos) { return arr[pos]; }
    inline const BasicType& operator [] (size_t pos) const { return arr[pos]; }

    inline void print() const {
        bool st=false;
        _rrep(i,n-1,1) {
            if (!st && !arr[i]) continue;
            putchar('0'+arr[i]),st=true;
        }
        if (!st) putchar('0');
    }

    inline friend BigInt operator + (const BigInt& a,const BigInt& b) { BigInt<BasicType,n> c; int jw=0; _rep(i,1,n-1) c[i]=a[i]+b[i]+jw,jw=c[i]/10,c[i]%=10; return c; }
    inline friend BigInt operator + (const BigInt& a,int b) { BigInt<BasicType,n> c; int jw=b; _rep(i,1,n-1) c[i]=a[i]+jw,jw=c[i]/10,c[i]%=10; return c; }
    inline friend BigInt operator + (int b,const BigInt& a) { return a+b; }
    inline friend BigInt operator - (const BigInt& a,const BigInt& b) { BigInt<BasicType,n> c; int jw=0; _rep(i,1,n-1) { c[i]=a[i]-b[i]-jw; if (c[i]<0) c[i]+=10,jw=1; else jw=0; } return c; }
    inline friend BigInt operator - (const BigInt& a,int b) { BigInt<BasicType,n> c; int jw=b; _rep(i,1,n-1) { c[i]=a[i]-jw; if (c[i]<0) jw=(-c[i]/10+(bool)((-c[i])%10)),c[i]+=jw*10; else jw=0; } return c; }
    inline friend BigInt operator * (const BigInt& a,const BigInt& b) { BigInt<BasicType,n> c; _rep(i,1,n-1) _rep(j,1,n-i) c[i+j-1]+=a[i]*b[j]; int jw=0; _rep(i,1,n-1) c[i]+=jw,jw=c[i]/10,c[i]%=10; return c; }
    inline friend BigInt operator * (const BigInt& a,int b) { BigInt<BasicType,n> c; _rep(i,1,n-1) c[i]=a[i]*b; int jw=0; _rep(i,1,n-1) c[i]+=jw,jw=c[i]/10,c[i]%=10; return c; }
    inline friend BigInt operator * (int b,const BigInt& a) { return a*b; }
    inline friend BigInt operator / (const BigInt& a,int b) { BigInt<BasicType,n> c; int cur=0; _rrep(i,n-1,1) cur=cur*10+a[i],c[i]=cur/b,cur%=b; return c; }
    inline friend bool operator == (const BigInt& a,const BigInt& b) { _rrep(i,n-1,1) if (a[i]!=b[i]) return false; return true; }
    inline friend bool operator != (const BigInt& a,const BigInt& b) { return !(a==b); }
    inline friend bool operator < (const BigInt& a,const BigInt& b) { _rrep(i,n-1,1) { if (a[i]<b[i]) return true; else if (a[i]>b[i]) return false; } return false; }
    inline friend bool operator <= (const BigInt& a,const BigInt& b) { _rrep(i,n-1,1) { if (a[i]<b[i]) return true; else if (a[i]>b[i]) return false; } return true; }
    inline friend bool operator > (const BigInt& a,const BigInt& b) { _rrep(i,n-1,1) { if (a[i]<b[i]) return false; else if (a[i]>b[i]) return true; } return false; }
    inline friend bool operator >= (const BigInt& a,const BigInt& b) { _rrep(i,n-1,1) { if (a[i]<b[i]) return false; else if (a[i]>b[i]) return true; } return true; }
};

namespace Graph {
    int *e=nullptr,*ne=nullptr,*h=nullptr,*w=nullptr,*f=nullptr,*c=nullptr;
    int tot;
    int _graph_size,_edge_size;
    
    inline void init_graph(size_t n=N,size_t m=M,bool flow=false) {
        _graph_size=n,_edge_size=m;
        if (e!=nullptr) delete[] e;
        if (ne!=nullptr) delete[] ne;
        if (h!=nullptr) delete[] h;
        if (w!=nullptr) delete[] w;
        if (f!=nullptr) delete[] f;
        if (c!=nullptr) delete[] c;
        e=new int[m];
        ne=new int[m];
        h=new int[n];
        w=new int[m];
        if (flow) f=new int[m],c=new int[m];
        memset(h,-1,sizeof(int)*n),tot=0;
    }

    inline void restore_graph() { memset(h,-1,sizeof(int)*_graph_size),tot=0; }
    inline void restore_graph(size_t n) { _rep(i,0,n) h[i]=-1; tot=0; }

    inline void add(int a,int b) { e[tot]=b,ne[tot]=h[a],h[a]=tot++; };
    inline void add(int a,int b,int c) { e[tot]=b,w[tot]=c,ne[tot]=h[a],h[a]=tot++; }
    inline void add_flow(int a,int b,int c) { e[tot]=b,f[tot]=c,ne[tot]=h[a],h[a]=tot++; e[tot]=a,f[tot]=0,ne[tot]=h[b],h[b]=tot++; }
    inline void add_flow(int a,int b,int F,int C) { e[tot]=b,f[tot]=F,c[tot]=C,ne[tot]=h[a],h[a]=tot++; e[tot]=a,f[tot]=0,c[tot]=-C,ne[tot]=h[b],h[b]=tot++; }

    namespace LCA {
        int *dep=nullptr,**f=nullptr;
        int _lca_n,_lca_k;

        inline void init(size_t n=N,size_t k=K) { _lca_n=n,_lca_k=k; dep=new int[n]; f=new int*[n]; _rep(i,0,n-1) f[i]=new int[k],memset(f[i],0,sizeof(int)*k); memset(dep,0,sizeof(int)*n); }
        inline void restore() { memset(dep,0,sizeof(int)*_lca_n),memset(f,0,sizeof(int)*_lca_n); }
        inline void restore(size_t n) { _rep(i,0,n) { dep[i]=0; _rep(j,0,K-1) f[i][j]=0; } }

        inline void dfs(int u,int p,int d) {
            dep[u]=d;
            _graph(i,u) {
                if (e[i]==p) continue;
                f[e[i]][0]=u;
                _rep(j,1,K-1) f[e[i]][j]=f[f[e[i]][j-1]][j-1];
                dfs(e[i],u,d+1);
            }
        }

        inline int lca(int a,int b) {
            if (a==b) return a;
            if (dep[a]<dep[b]) swap(a,b);
            _rrep(i,K-1,0) if (dep[f[a][i]]>=dep[b]) a=f[a][i];
            if (a==b) return a;
            _rrep(i,K-1,0) if (f[a][i]!=f[b][i]) a=f[a][i],b=f[b][i];
            return f[a][0];
        }
    }

    namespace SP {
        int *dis=nullptr;
        bool *flag=nullptr;
        priority_queue<pii,vector<pii>,greater<pii>> q;
        int _sp_n;

        inline void init(size_t n=N) { _sp_n=n; dis=new int[n]; flag=new bool[n]; _rep(i,0,n-1) dis[i]=inf,flag[i]=false; }
        inline void restore() { _rep(i,0,_sp_n-1) dis[i]=inf,flag[i]=false; }
        inline void restore(size_t n) { _rep(i,0,n) dis[i]=inf,flag[i]=false; }

        inline void dijkstra(int s) {
            q.emplace(pii{dis[s]=0,s});
            while (!q.empty()) {
                auto tp=q.top(); q.pop();
                int u=tp.second;
                if (flag[u]) continue;
                flag[u]=true;
                _graph(i,u) if (dis[e[i]]>dis[u]+w[i]) q.emplace(pii{dis[e[i]]=dis[u]+w[i],e[i]});
            }
        }
    }

    namespace DINIC {
        int S,T;
        int *cur=nullptr,*dep=nullptr;
        int _dinic_n;

        inline void init(size_t n=N) { _dinic_n=n; S=T=0; cur=new int[n]; dep=new int[n]; memset(cur,0,sizeof(int)*n); memset(dep,0,sizeof(int)*n); }

        inline bool bfs() {
            queue<int> q;
            memset(dep,0,sizeof(int)*N);
            q.emplace(S),cur[S]=h[S],dep[S]=1;
            while (!q.empty()) {
                int u=q.front(); q.pop();
                _graph(i,u) {
                    if (!dep[e[i]] && f[i]) {
                        dep[e[i]]=dep[u]+1;
                        cur[e[i]]=h[e[i]];
                        if (e[i]==T) return true;
                        q.emplace(e[i]);
                    }
                }
            }
            return false;
        }

        inline int dfs(int u,int limit) {
            if (u==T) return limit;
            int k=0;
            _dinic(i,u) {
                cur[u]=i;
                if (dep[e[i]]==dep[u]+1 && f[i]) {
                    int ret=dfs(e[i],min(f[i],limit-k));
                    f[i]-=ret,f[i^1]+=ret,k+=ret;
                    if (!ret) dep[e[i]]=0;
                }
            }
            return k;
        }

        inline int dinic() {
            int ans=0,k;
            while (bfs()) while (k=dfs(S,inf)) ans+=k;
            return ans; 
        }
    }

    namespace MCMF {
        int S,T;
        int *dis=nullptr,*flow=nullptr,*bk=nullptr;
        bool *flag=nullptr;
        int _mcmf_n;

        inline void init(size_t n=N) { _mcmf_n=n; S=T=0; dis=new int[n]; flow=new int[n]; bk=new int[n]; flag=new bool[n]; _rep(i,0,n-1) dis[i]=flow[i]=inf; memset(bk,0,sizeof(int)*n); memset(flag,0,sizeof(bool)*n); }
        inline void restore() { S=T=0; _rep(i,0,N-1) dis[i]=inf,flow[i]=inf,bk[i]=flag[i]=0; }
        inline void restore(size_t n) { S=T=0; _rep(i,0,n) dis[i]=inf,flow[i]=inf,bk[i]=flag[i]=0; }
    
        inline bool spfa() {
            _rep(i,0,N-1) dis[i]=inf,flow[i]=inf,bk[i]=flag[i]=0;
            queue<int> q;
            q.emplace(S),dis[S]=0,flag[S]=true;
            while (!q.empty()) {
                int u=q.front(); q.pop(),flag[u]=false;
                _graph(i,u) {
                    if (dis[e[i]]>dis[u]+c[i] && f[i]) {
                        dis[e[i]]=dis[u]+c[i];
                        flow[e[i]]=min(flow[u],f[i]);
                        bk[e[i]]=i;
                        if (!flag[e[i]]) q.emplace(e[i]),flag[e[i]]=true;
                    }
                }
            }
            return dis[T]!=inf;
        }

        inline pii solve() {
            int F=0,C=0;
            while (spfa()) {
                F+=flow[T];
                int u=T;
                while (u!=S) {
                    int i=bk[u];
                    f[i]-=flow[T],f[i^1]+=flow[T];
                    C+=c[i]*flow[T];
                    u=e[i^1];
                }
            }
            return pii{F,C};
        }
    }
}

template<
    class ValueType,
    void (*UP) (ValueType&,ValueType&,ValueType&),
    void (*DOWN) (ValueType&,ValueType&,ValueType&),
    class ModifyType,
    void (*MODIFY) (ValueType&,const ModifyType&),
    int base=1
>
class SEG {
public:
    ValueType *tr=nullptr; // must contain member 'l' and 'r'

    SEG() {}
    SEG(size_t N) { tr=new ValueType[N<<2](); build(1,base,N); }
    ~SEG() { delete[] tr; }
    SEG(const SEG&)=delete;
    SEG& operator=(const SEG&)=delete;

    inline void reserve(size_t N) {
        if (tr!=nullptr) delete[] tr;
        tr=new ValueType[N<<2]();
        build(1,base,N);
    }

    inline void pushup(int u) { if (UP!=nullptr) UP(tr[u],tr[u<<1],tr[u<<1|1]); }
    inline void pushdown(int u) { auto& root=tr[u],&left=tr[u<<1],&right=tr[u<<1|1]; if (DOWN!=nullptr) DOWN(root,left,right); }

    inline void build(int u,int l,int r) {
        tr[u].l=l,tr[u].r=r;
        if (l==r) return;
        int mid=l+r>>1;
        build(u<<1,l,mid); build(u<<1|1,mid+1,r);
        pushup(u);
    }

    inline void modify(int u,int l,int r,const ModifyType& k) {
        if (tr[u].l>=l && tr[u].r<=r) {
            if (MODIFY!=nullptr) MODIFY(tr[u],k);
        } else {
            pushdown(u);
            int mid=tr[u].l+tr[u].r>>1;
            if (l<=mid) modify(u<<1,l,r,k);
            if (r>mid) modify(u<<1|1,l,r,k);
            pushup(u);
        }
    }

    inline ValueType query(int u,int l,int r) {
        if (tr[u].l>=l && tr[u].r<=r) return tr[u];
        pushdown(u);
        int mid=tr[u].l+tr[u].r>>1;
        ValueType ans,L,R;
        if (l<=mid) L=query(u<<1,l,r);
        if (r>mid) R=query(u<<1|1,l,r);
        if (UP!=nullptr) UP(ans,L,R);
        return ans;
    }
};

template<class ValueType>
class BIT {
public:
    size_t n=0;
    ValueType *tr=nullptr;

    BIT() {}
    BIT(size_t n) { tr=new ValueType[n]; memset(tr,0,sizeof(ValueType)*n); this->n=n; }
    ~BIT() { delete[] tr; }
    BIT(const BIT&)=delete;
    BIT& operator=(const BIT&)=delete;

    inline void reserve(size_t n) { if (tr!=nullptr) delete[] tr; tr=new ValueType[n]; memset(tr,0,sizeof(ValueType)*n); this->n=n; }
    inline void modify(int x,ValueType k) { while (x<=n) tr[x]=tr[x]+k,x+=lowbit(x); }
    inline ValueType query(int x) { ValueType ans=0; while (x) ans=ans+tr[x],x-=lowbit(x); return ans; }

    inline void modify_xor(int x,ValueType k) { while (x<=n) tr[x]=(tr[x]^k),x+=lowbit(x); }
    inline ValueType query_xor(int x) { ValueType ans=0; while (x) ans=(ans^tr[x]),x-=lowbit(x); return ans; }
};

class DSU {
public:
    size_t n=0;
    int *p=nullptr;
    void (*MERGE)(int,int)=nullptr; // x <- y

    DSU() {}
    DSU(size_t n) { p=new int[n]; _rep(i,0,n-1) p[i]=i; this->n=n; }
    DSU(void (*fp)(int,int)=nullptr): MERGE(fp) {}
    DSU(size_t n,void (*fp)(int,int)=nullptr): MERGE(fp) { p=new int[n]; _rep(i,0,n-1) p[i]=i; this->n=n; }
    ~DSU() { delete[] p; }
    DSU(const DSU&)=delete;
    DSU& operator=(const DSU&)=delete;

    inline void reserve(size_t n) { if (p!=nullptr) delete[] p; p=new int[n]; _rep(i,0,n-1) p[i]=i; this->n=n; }
    inline int find(int x) { return (p[x]==x)?p[x]:(p[x]=find(p[x])); }
    inline bool connected(int x,int y) { return find(x)==find(y); }
    inline void merge(int x,int y) {
        x=find(x),y=find(y);
        if (MERGE!=nullptr) MERGE(x,y);
        p[find(y)]=find(x);
    }
};

namespace Convolution {
    const int G=3;

    int *inv_num=nullptr;

    inline void init_inv(size_t k=N) {
        inv_num=new int[k];
        _rep(i,1,k-1) inv_num[i]=Math::inverse(i);
    }

    inline void ntt(vector<int>& a,bool inv) {
        int n=a.size();
        int j=0;
        _rep(i,0,n-1) {
            if (i<j) swap(a[i],a[j]);
            int k=n>>1;
            while ((j^=k)<k) k>>=1;
        }
        _reps(len,2,n,len<<=1) {
            int l=Math::ksm(G,(mod-1)/len);
            if (inv) l=Math::inverse(l);
            _reps(i,0,n-1,i+=len) {
                int w=1;
                _rep(j,0,(len>>1)-1) {
                    int L=a[i+j]%mod,R=a[i+j+(len>>1)]*w%mod;
                    a[i+j]=(L+R)%mod;
                    a[i+j+(len>>1)]=(L-R+mod)%mod;
                    w=w*l%mod;
                }
            }
        }
        if (inv) {
            int v=Math::inverse(n);
            _rep(i,0,n-1) a[i]=a[i]*v%mod;
        }
    }

    inline vector<int> polymul(vector<int> a,vector<int> b) {
        int sz=a.size()+b.size()-1;
        int n=1;
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

    inline vector<int> polyinv(vector<int> a) {
        vector<int> b;
        b.emplace_back(Math::inverse(a[0]));
        int m=1;
        while (b.size()<a.size()) {
            m<<=1;
            int len=min(m,(int)a.size());
            vector<int> a1;
            _rep(i,0,len-1) a1.emplace_back(a[i]);
            vector<int> c=polymul(a1,b);
            c.resize(len);
            _for(t,c) t=((-t)%mod+mod)%mod;
            (c[0]+=2)%=mod;
            b=polymul(b,c);
            b.resize(len);
        }
        return b;
    }

    inline vector<int> polyint(vector<int> a,int c) {
        vector<int> b(a.size()+1);
        _rep(i,0,(int)a.size()-1) b[i+1]=a[i]*inv_num[i+1]%mod;
        b[0]=c%mod;
        return b;
    }

    inline vector<int> polyder(vector<int> a) {
        if (a.size()==1) return {0};
        vector<int> b(a.size()-1);
        _rep(i,1,(int)a.size()-1) b[i-1]=i*a[i]%mod;
        return b;
    }

    inline vector<int> polyln(vector<int> a) {
        if (a.size()==1) return {0};
        auto der=polyder(a);
        auto inv=polyinv(a);
        inv.resize(der.size());
        auto b=polymul(der,inv);
        b=polyint(b,0);
        b.resize(a.size());
        return b;
    }

    inline vector<int> polyexp(vector<int> a) {
        vector<int> b;
        b.emplace_back(1);
        int m=1;
        while (b.size()<a.size()) {
            m<<=1;
            int len=min(m,(int)a.size());
            b.resize(len);
            vector<int> ln=polyln(b);
            _for(t,ln) t=((-t)%mod+mod)%mod;
            (++ln[0])%=mod;
            _rep(i,0,len-1) (ln[i]+=a[i])%=mod;
            b=polymul(b,ln);
            b.resize(len);
        }
        return b;
    }
}

template<typename T>
class Deque {
private:
    struct node {
        T value;
        node *prev;
        node *next;
    } *head,*tail;
    int length;

public:
    Deque(): head(nullptr),tail(nullptr),length(0) {}
    ~Deque() { clear(); }

    Deque(const Deque& oth): head(nullptr),tail(nullptr),length(0) {
        node* curr=oth.head;
        while (curr) {
            emplace(curr->value);
            curr=curr->next;
        }
    }

    Deque& operator = (const Deque& oth) {
        if (this!=&oth) {
            clear();
            node* curr=oth.head;
            while (curr) {
                emplace(curr->value);
                curr=curr->next;
            }
        }
        return *this;
    }

    Deque(Deque&& oth) noexcept: head(oth.head),tail(oth.tail),length(oth.length) {
        oth.head=nullptr;
        oth.tail=nullptr;
        oth.length=0;
    }

    Deque& operator = (Deque&& oth) noexcept {
        if (this!=&oth) {
            clear();
            head=oth.head;
            tail=oth.tail;
            length=oth.length;
            oth.head=nullptr;
            oth.tail=nullptr;
            oth.length=0;
        }
        return *this;
    }

    inline void swap(Deque& oth) noexcept {
        swap(head,oth.head);
        swap(tail,oth.tail);
        swap(length,oth.length);
    }

    inline bool empty() const { return head==nullptr; }
    inline void clear() { while (!empty()) { node* tmp=head; head=head->next; delete tmp; } tail=nullptr; length=0; }
    inline size_t size() const { return length; }
    inline T& front() { if (empty()) __assert(false); return head->value; }
    inline T& back() { if (empty()) __assert(false); return tail->value; }

    inline void emplace_front(const T& value) {
        node* u=new node{value,nullptr,head};
        if (empty()) tail=u;
        else head->prev=u;
        head=u;
        ++length;
    }

    inline void emplace_back(const T& value) {
        node* u=new node{value,tail,nullptr};
        if (empty()) head=u;
        else tail->next=u;
        tail=u;
        ++length;
    }

    template<typename... S> inline void emplace_front(const T& v1,const S&... v2) { emplace_front(v1),emplace_front(v2...); }
    template<typename... S> inline void emplace_back(const T& v1,const S&... v2) { emplace_back(v1),emplace_back(v2...); }

    inline T pop_front() {
        if (empty()) __assert(false);
        T value=head->value;
        node* tmp=head;
        head=head->next;
        delete tmp;
        if (head==nullptr) tail=nullptr;
        else head->prev=nullptr;
        --length;
        return value;
    }

    inline T pop_back() {
        if (empty()) __assert(false);
        T value=tail->value;
        node* tmp=tail;
        tail=tail->prev;
        delete tmp;
        if (tail==nullptr) head=nullptr;
        else tail->next=nullptr;
        --length;
        return value;
    }

    class Iterator {
    private:
        node* curr;

    public:
        Iterator(node* u): curr(u) {}

        T& operator * () { return curr->value; }
        Iterator& operator ++ () { if (curr) curr=curr->next; return *this; }
        Iterator operator ++ (signed) { Iterator tmp=*this; ++(*this); return tmp; }
        bool operator == (const Iterator& oth) const { return curr==oth.curr; }
        bool operator != (const Iterator& oth) const { return curr!=oth.curr; }
    };

    class ConstIterator { 
    private:
        const node* curr;

    public:
        ConstIterator(const node* u): curr(u) {}

        const T& operator * () const { return curr->value; }
        ConstIterator& operator ++ () { if (curr) curr=curr->next; return *this; }
        ConstIterator operator ++ (signed) { ConstIterator tmp=*this; ++(*this); return tmp; }
        bool operator == (const ConstIterator& oth) const { return curr==oth.curr; }
        bool operator != (const ConstIterator& oth) const { return curr!=oth.curr; }
    };

    Iterator begin() { return Iterator(head); }
    Iterator end() { return Iterator(nullptr); }
    ConstIterator cbegin() const { return ConstIterator(head); }
    ConstIterator cend() const { return ConstIterator(nullptr); }
};

using namespace IO;

int T,r,c;
char s[N][N];

int main() {
    read(T);
    _rep(tt,1,T) {
        read(r,c);
        _reps(i,1,r*2+1,i+=2) _rep(j,1,c*2+1) if (j&1) s[i][j]='+'; else s[i][j]='-';
        _reps(i,2,r*2+1,i+=2) _rep(j,1,c*2+1) if (j&1) s[i][j]='|'; else s[i][j]='.';
        s[1][1]=s[1][2]=s[2][1]='.';
        printf("Case #%d:\n",tt);
        _rep(i,1,r*2+1) {
            _rep(j,1,c*2+1) putchar(s[i][j]);
            putchar(10);
        }
    }
    return 0;
}