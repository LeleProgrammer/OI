#include <bits/stdc++.h>
using namespace std;

#define BETTER

#ifdef BETTER

#define endl '\n'
#define FRR(file) freopen(file,"r",stdin)
#define FRW(file) freopen(file,"w",stdout)
#define _rep(i,a,b) for (int i=(a);i<=(b);++i)
#define _reps(i,a,b,c) for (int i=(a);i<=(b);c)
#define _rrep(i,a,b) for (int i=(a);i>=(b);--i)
#define _rreps(i,a,b,c) for (int i=(a);i>=(b);c)
#define _iter(i,a) for (auto i=a.begin();i!=a.end();++i)
#define _graph(i,u) for (int i=h[u];~i;i=ne[i])
#define rint register int
#define LL long long

#endif

#ifdef DEBUG

#define TIMESTAMP cerr<<fixed<<setprecision(3)<<clock()*1.0/CLOCKS_PER_SEC<<"s"<<endl;

namespace PRINT {
    template<typename T> inline void PVAL(T x) { cerr<<x; }
    template<typename T> inline void PVALS(T x) { cerr<<x<<' '; }
    template<typename T> inline void PVALLN(T x) { cerr<<x<<endl; }
    template<typename T> inline void PVEC(vector<T> vec) { for (int i=0;i<vec.size();++i) PVALS(vec[i]); putchar(10); }
    template<typename T> inline void PQUE(queue<T> q) { while (!q.empty()) PVALS(q.front()),q.pop(); putchar(10); }
    template<typename T> inline void PDQU(deque<T> q) { while (!q.empty()) PVALS(q.front()),q.pop_front(); putchar(10); }
    template<typename T> inline void PSET(set<T> s) { for (typename set<T>::iterator it=s.begin();it!=s.end();++it) PVALS(*it); putchar(10); }
    template<typename T> inline void PUSET(unordered_set<T> s) { for (typename unordered_set<T>::iterator it=s.begin();it!=s.end();++it) PVALS(*it); putchar(10); }
    template<typename T,typename T2> inline void PMAP(map<T,T2> s) { for (typename map<T,T2>::iterator it=s.begin();it!=s.end();++it) PVAL(it->first),PVAL(": "),PVALLN(it->second); }
    template<typename T,typename T2> inline void PUMAP(unordered_map<T,T2> s) { for (typename unordered_map<T,T2>::iterator it=s.begin();it!=s.end();++it) PVAL(it->first),PVAL(": "),PVALLN(it->second); }
    template<typename T> inline void PARR(T* arr,int n) { for (int i=1;i<=n;++i) PVALS(arr[i]); putchar(10); }
    template<typename T> inline void PARR(T* arr,int l,int r) { for (int i=l;i<=r;++i) PVALS(arr[i]); putchar(10); }
    template<typename T> inline void PARR(T* arr,int n,string name) { for (int i=1;i<=n;++i) PVAL(name),PVAL("["),PVAL(i),PVAL("] = "),PVALLN(arr[i]); }
    template<typename T> inline void PARR0(T* arr,int n) { for (int i=0;i<=n;++i) PVALS(arr[i]); putchar(10); }
    template<typename T> inline void PARR0(T* arr,int n,string name) { for (int i=0;i<=n;++i) PVAL(name),PVAL("["),PVAL(i),PVAL("] = "),PVALLN(arr[i]); }
    template<typename T> inline void PARR2D(T** arr,int n,int m) { for (int i=1;i<=n;++i) { for (int j=1;j<=m;++j) PVALS(arr[i][j]); putchar(10); } }
}

using namespace PRINT;

#else

#define TIMESTAMP

namespace PRINT {
    template<typename T> inline void PVAL(T x) { ; }
    template<typename T> inline void PVALS(T x) { ; }
    template<typename T> inline void PVALLN(T x) { ; }
    template<typename T> inline void PVEC(vector<T> vec) { ; }
    template<typename T> inline void PQUE(queue<T> q) { ; }
    template<typename T> inline void PDQU(deque<T> q) { ; }
    template<typename T> inline void PSET(set<T> s) { ; }
    template<typename T> inline void PUSET(unordered_set<T> s) { ; }
    template<typename T,typename T2> inline void PMAP(map<T,T2> s) { ; }
    template<typename T,typename T2> inline void PUMAP(unordered_map<T,T2> s) { ; }
    template<typename T> inline void PARR(T* arr,int n) { ; }
    template<typename T> inline void PARR(T* arr,int l,int r) { ; }
    template<typename T> inline void PARR(T* arr,int n,string name) { ; }
    template<typename T> inline void PARR0(T* arr,int n) { ; }
    template<typename T> inline void PARR0(T* arr,int n,string name) { ; }
    template<typename T> inline void PARR2D(T** arr,int n,int m) { ; }
}

using namespace PRINT;

#endif

#ifdef FASTIO

namespace IO {
    inline void read(int &a) {
        int sym=1,num=0;
        char c=getchar();
        while (c<'0' || c>'9') {
            if (c=='-') {
                sym=-1;
            }
            c=getchar();
        }
        while (c>='0' && c<='9') {
            num=num*10+c-'0';
            c=getchar();
        }
        a=sym*num;
    }
    inline void write(int a) {
        if (a<0) {
            putchar('-');
            a*=-1;
        }
        if (a>=10) {
            write(a/10);
        }
        putchar(a%10+'0');
    }
}

using namespace IO;

#endif

const int N=1000005;
const int M=4000005;
const int K=1005;
const int mod=1e9+7;

int n,m;
int arr[K][K];
int e[M],ne[M],h[N],tot;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int in[N],f[N];
queue<int> q;

void add(int a,int b) {
    e[tot]=b,ne[tot]=h[a],h[a]=tot++;
}

int get(int i,int j) {
    return (i-1)*m+j;
}

bool check(int i,int j) {
    return i>=1 && i<=n && j>=1 && j<=m;
}

void topu() {
    _rep(i,1,n) _rep(j,1,m) f[get(i,j)]=1;
    _rep(i,1,n) _rep(j,1,m) if (!in[get(i,j)]) q.push(get(i,j));
    while (!q.empty()) {
        int u=q.front(); q.pop();
        _graph(i,u) {
            f[e[i]]=(f[e[i]]+f[u])%mod;
            if (!--in[e[i]]) q.push(e[i]);
        }
    }
}

int main() {
    memset(h,-1,sizeof(h));
    scanf("%d %d",&n,&m);
    _rep(i,1,n) _rep(j,1,m) scanf("%d",&arr[i][j]);
    _rep(i,1,n) _rep(j,1,m) _rep(k,0,3) if (check(i+dx[k],j+dy[k]) && arr[i+dx[k]][j+dy[k]]>arr[i][j]) add(get(i,j),get(i+dx[k],j+dy[k])),in[get(i+dx[k],j+dy[k])]++;
    topu();
    int ans=0;
    _rep(i,1,n) _rep(j,1,m) ans=(ans+f[get(i,j)])%mod;
    printf("%d",ans);
    return 0;
}