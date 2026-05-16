#include <bits/stdc++.h>
using namespace std;

#define int long long

#define BETTER

#ifdef BETTER

#define endl '\n'
#define FRR(file) freopen(file,"r",stdin)
#define FRW(file) freopen(file,"w",stdout)
#define _rep(i,a,b) for (int i=(a);i<=(b);++i)
#define _rrep(i,a,b) for (int i=(a);i>=(b);--i)
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

const int inf=1e18;

int a,b,p,ans;

int exgcd(int a,int b,int& x,int& y) {
    if (!b) {
        x=1,y=0;
        return a;
    }
    int d=exgcd(b,a%b,y,x);
    y-=a/b*x;
    return d;
}

int bsgs(int a,int b,int p) {
    a%=p,b%=p;
    if (1%p==b%p) return 0;
    int k=sqrt(p)+1;
    unordered_map<int,int> hash;
    int ak=1;
    int j=b;
    _rep(y,0,k-1) hash[j]=y,j=j*a%p;
    _rep(i,1,k) ak=ak*a%p;
    j=ak;
    _rep(x,1,k) {
        if (hash.count(j)) return k*x-hash[j];
        j=j*ak%p;
    }
    return -inf;
}

int exbsgs(int a,int b,int p) {
    a=(a%p+p)%p,b=(b%p+p)%p;
    if (1%p==b%p) return 0;
    int x,y;
    int d=exgcd(a,p,x,y);
    if (d>=2) {
        if (b%d) return -inf;
        exgcd(a/d,p/d,x,y);
        b/=d,p/=d;
        return exbsgs(a,b*((x%p+p)%p),p)+1;
    }
    return bsgs(a,b,p);
}

signed main() {
    while (scanf("%lld %lld %lld",&a,&p,&b),a || p || b) {
        if ((ans=exbsgs(a,b,p))<0) puts("No Solution");
        else printf("%lld\n",ans);
    }
    return 0;
}