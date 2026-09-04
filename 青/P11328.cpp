#include <bits/stdc++.h>
using namespace std;

// ======== EXTRA DEFINITION ========
#define int long long
// ==================================

const int N=500005;
const int M=2;
const int K=log2((long double)N)+2;
const int mod=998244353;
const int inf=2e9;
const double pi=acos(-1);
const double eps=1e-9;

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

using pii=pair<int,int>;
using pdd=pair<double,double>;

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

using namespace IO;

int n,ans;
multiset<int> q;

struct node {
    int x,l;
    _sortf(node) {
        return a.l+a.x<b.l+b.x;
    }
} arr[N];

i32 main() {
    read(n);
    _rep(i,1,n) read(arr[i].x);
    _rep(i,1,n) read(arr[i].l);
    _sorta(arr,1,n);
    int cur=0;
    _rep(i,1,n) {
        int x=arr[i].x,l=arr[i].l;
        if (cur<=l) cur+=x,q.emplace(x);
        else {
            auto it=LB2(q,x);
            if (it!=q.end()) {
                auto itt=prev(q.end());
                cur-=*itt;
                q.erase(itt);
                cur+=x;
                q.emplace(x);
            }
        }
        chmax(ans,(int)q.size());
    }
    write(ans);
    return 0;
}