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

const int N=40005;
const double eps=1e-8;
const double pi=acos(-1);

int n,cnt;
double a,b,r;
int dx[4]={1,1,-1,-1};
int dy[4]={-1,1,-1,1};
int stk[N],hh;
bool flag[N];

int sign(double x) {
    if (fabs(x)<eps) return 0;
    else if (x>0) return 1;
    else return -1;
}

int cmp(double a,double b) {
    if (fabs(a-b)<eps) return 0;
    else if (a<b) return -1;
    else return 1;
}

struct Point {
    double x,y;
    bool operator < (const Point& a) const {
        if (cmp(x,a.x)) return cmp(x,a.x)<0;
        else return cmp(y,a.y)<0;
    }
    Point operator + (const Point& a) const {
        return {x+a.x,y+a.y};
    }
    Point operator - (const Point& a) const {
        return {x-a.x,y-a.y};
    }
    bool operator == (const Point& a) const {
        return !cmp(x,a.x) && !cmp(y,a.y);
    }
} arr[N];

Point rotate(Point a,double theta) {
    return {a.x*cos(theta)+a.y*sin(theta),-a.x*sin(theta)+a.y*cos(theta)};
}

double cross(Point a,Point b) {
    return a.x*b.y-a.y*b.x;
}

double area(Point a,Point b,Point c) {
    return cross(b-a,c-a);
}

double get_dis(Point a,Point b) {
    double x=a.x-b.x;
    double y=a.y-b.y;
    return sqrt(x*x+y*y);
}

double solve() {
    sort(arr+1,arr+1+cnt);
    _rep(i,1,cnt) {
        if (i!=1 && arr[i]==arr[i-1]) {
            flag[i]=true;
            continue;
        }
        while (hh>=2) {
            int s=sign(area(arr[stk[hh-1]],arr[stk[hh]],arr[i]));
            if (s>0) flag[stk[hh--]]=false;
            else if (!s) hh--;
            else break;
        }
        stk[++hh]=i,flag[i]=true;
    }
    flag[1]=false;
    _rrep(i,cnt-1,1) {
        if (flag[i]) continue;
        while (hh>=2 && sign(area(arr[stk[hh-1]],arr[stk[hh]],arr[i]))>=0) hh--;
        stk[++hh]=i;
    }
    double ans=0.0;
    _rep(i,1,hh-1) ans+=get_dis(arr[stk[i]],arr[stk[i+1]]);
    return ans;
}

double get_circle() {
    return 2.0*pi*r;
}

int main() {
    scanf("%d",&n);
    scanf("%lf %lf %lf",&a,&b,&r);
    a=a/2-r,b=b/2-r;
    _rep(i,1,n) {
        double x,y,theta;
        scanf("%lf %lf %lf",&x,&y,&theta);
        _rep(j,0,3) {
            Point p=rotate({b*dx[j],a*dy[j]},-theta);
            p=p+Point{x,y};
            arr[++cnt]=p;
        }
    }
    printf("%.2lf",solve()+get_circle());
    return 0;
}