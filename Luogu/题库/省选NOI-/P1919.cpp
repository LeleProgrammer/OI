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

const int N=2097157;
const double pi=acos(-1);

int n,m;

struct Complex {
    double x,y;
    Complex() {
        x=y=0;
    }
    Complex(double x,double y) {
        this->x=x;
        this->y=y;
    }
    Complex operator + (const Complex& a) const {
        return {x+a.x,y+a.y};
    }
    Complex operator - (const Complex& a) const {
        return {x-a.x,y-a.y};
    }
    Complex operator * (const Complex& a) const {
        return {x*a.x-y*a.y,x*a.y+y*a.x};
    }
};

Complex a[N],b[N];

int rev[N],bit,tot;
char in[N];
int ans[N];

void readin(Complex* a,int& n) {
    scanf("%s",in);
    n=strlen(in)-1;
    reverse(in,in+n+1);
    _rep(i,0,n) a[i].x=(double)(in[i]-'0');
}

void fft(Complex* a,int inv) {
    _rep(i,0,tot-1) if (i<rev[i]) swap(a[i],a[rev[i]]);
    _reps(mid,1,tot-1,mid<<=1) {
        Complex w1={cos(pi/mid),sin(pi/mid)*inv};
        _reps(i,0,tot-1,i+=(mid<<1)) {
            Complex wk={1,0};
            _rep(j,0,mid-1) {
                auto L=a[i+j],R=a[i+j+mid]*wk;
                a[i+j]=L+R,a[i+j+mid]=L-R;
                wk=wk*w1;
            }
        }
    }
}

int main() {
    readin(a,n);
    readin(b,m);
    while ((1<<bit)<n+m+1) bit++;
    tot=(1<<bit);
    _rep(i,1,tot-1) rev[i]=(rev[i>>1]>>1)|((i&1)<<(bit-1));
    fft(a,1); fft(b,1);
    _rep(i,0,tot-1) a[i]=a[i]*b[i];
    fft(a,-1);
    _rep(i,0,n+m) ans[i]=(int)(a[i].x/tot+0.1);
    int i=0,jw=0,mx=0;
    while (i<=n+m || jw) {
        mx=max(i,n+m);
        ans[i]+=jw;
        jw=ans[i]/10;
        ans[i]%=10;
        ++i;
    }
    while (!ans[mx]) mx--;
    _rrep(i,mx,0) printf("%d",ans[i]);
    return 0;
}