#include <bits/stdc++.h>

#define int long long

using namespace std;

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

const int N=200005;
const int mod=998244353;

int n,q;
int a[N],b[N];

struct SegmentTree {
    int l,r;
    int suma,sumb;
    int mul;
    int adda,addb;
} tr[N*4];

void pushup(int u) {
    tr[u].suma=tr[u<<1].suma+tr[u<<1|1].suma; tr[u].suma%=mod;
    tr[u].sumb=tr[u<<1].sumb+tr[u<<1|1].sumb; tr[u].sumb%=mod;
    tr[u].mul=tr[u<<1].mul+tr[u<<1|1].mul; tr[u].mul%=mod;
}

void pushdown(int u) {
    auto &root=tr[u],&left=tr[u<<1],&right=tr[u<<1|1];
    if (root.adda) {
        left.suma+=(left.r-left.l+1)*root.adda; left.suma%=mod;
        right.suma+=(right.r-right.l+1)*root.adda; right.suma%=mod;
        left.mul+=left.sumb*root.adda; left.mul%=mod;
        right.mul+=right.sumb*root.adda; right.mul%=mod;
        left.adda+=root.adda; left.adda%=mod;
        right.adda+=root.adda; right.adda%=mod;
        root.adda=0;
    }
    if (root.addb) {
        left.sumb+=(left.r-left.l+1)*root.addb; left.sumb%=mod;
        right.sumb+=(right.r-right.l+1)*root.addb; right.sumb%=mod;
        left.mul+=left.suma*root.addb; left.mul%=mod;
        right.mul+=right.suma*root.addb; right.mul%=mod;
        left.addb+=root.addb; left.addb%=mod;
        right.addb+=root.addb; right.addb%=mod;
        root.addb=0;
    }
}

void build(int u,int l,int r) {
    tr[u]={l,r,a[l]%mod,b[l]%mod,a[l]*b[l]%mod,0,0};
    if (l==r) return;
    int mid=l+r>>1;
    build(u<<1,l,mid); build(u<<1|1,mid+1,r);
    pushup(u);
}

void modify_a(int u,int l,int r,int x) {
    if (tr[u].l!=tr[u].r) pushdown(u);
    if (tr[u].l>=l && tr[u].r<=r) {
        tr[u].adda+=x; tr[u].adda%=mod;
        tr[u].suma+=(tr[u].r-tr[u].l+1)*x; tr[u].suma%=mod;
        tr[u].mul+=tr[u].sumb*x; tr[u].mul%=mod;
    } else {
        int mid=tr[u].l+tr[u].r>>1;
        if (l<=mid) modify_a(u<<1,l,r,x);
        if (r>mid) modify_a(u<<1|1,l,r,x);
        pushup(u);
    }
}

void modify_b(int u,int l,int r,int x) {
    if (tr[u].l!=tr[u].r) pushdown(u);
    if (tr[u].l>=l && tr[u].r<=r) {
        tr[u].addb+=x; tr[u].addb%=mod;
        tr[u].sumb+=(tr[u].r-tr[u].l+1)*x; tr[u].sumb%=mod;
        tr[u].mul+=tr[u].suma*x; tr[u].mul%=mod;
    } else {
        int mid=tr[u].l+tr[u].r>>1;
        if (l<=mid) modify_b(u<<1,l,r,x);
        if (r>mid) modify_b(u<<1|1,l,r,x);
        pushup(u);
    }
}

int query(int u,int l,int r) {
    if (tr[u].l>=l && tr[u].r<=r) return tr[u].mul;
    pushdown(u);
    int mid=tr[u].l+tr[u].r>>1;
    int ans=0;
    if (l<=mid) ans+=query(u<<1,l,r);
    if (r>mid) ans+=query(u<<1|1,l,r);
    ans%=mod;
    return ans;
}

signed main() {
    scanf("%lld %lld",&n,&q);
    _rep(i,1,n) scanf("%lld",&a[i]);
    _rep(i,1,n) scanf("%lld",&b[i]);
    build(1,1,n);
    while (q--) {
        int op,l,r;
        scanf("%lld %lld %lld",&op,&l,&r);
        if (op==1) {
            int x;
            scanf("%lld",&x);
            modify_a(1,l,r,x);
        } else if (op==2) {
            int x;
            scanf("%lld",&x);
            modify_b(1,l,r,x);
        } else {
            printf("%lld\n",query(1,l,r)%mod);
        }
    }
    return 0;
}