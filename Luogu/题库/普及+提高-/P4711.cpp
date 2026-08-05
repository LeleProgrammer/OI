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

const int N=105;
double eps=1e-8;

int n;
double ans;
char s[N];
map<string,double> element;

void init() {
    element["H"]=1;
    element["C"]=12;
    element["N"]=14;
    element["O"]=16;
    element["F"]=19;
    element["Na"]=23;
    element["Mg"]=24;
    element["Al"]=27;
    element["Si"]=28;
    element["P"]=31;
    element["S"]=32;
    element["Cl"]=35.5;
    element["K"]=39;
    element["Ca"]=40;
    element["Mn"]=55;
    element["Fe"]=56;
    element["Cu"]=64;
    element["Zn"]=65;
    element["Ag"]=108;
    element["I"]=127;
    element["Ba"]=137;
    element["Hf"]=178.5;
    element["Pt"]=195;
    element["Au"]=197;
    element["Hg"]=201;
}

string substr(int l,int r) {
    string ans;
    _rep(i,l,r) ans.push_back(s[i]);
    return ans;
}

pair<int,double> readElement(int i) {
    if (i==n) return {i,element[substr(i,i)]};
    if (islower(s[i+1])) return {i+1,element[substr(i,i+1)]};
    return {i,element[substr(i,i)]};
}

pair<int,int> readNum(int pos) {
    int num=0;
    int endpos=n;
    _rep(i,pos,n) {
        if (s[i]=='}') {
            endpos=i;
            break;
        }
        if (isdigit(s[i])) num=num*10+(s[i]-'0');
    }
    return {endpos,num};
}

pair<int,double> readPart(int pos) {
    double ans=0;
    int endpos=n;
    _rep(i,pos,n) {
        if (s[i]==')') {
            endpos=i;
            break;
        }
        auto t=readElement(i);
        int j=t.first+1;
        if (j<=n && s[j]=='_') {
            auto p=readNum(j);
            ans+=t.second*p.second;
            j=p.first+1;
        } else ans+=t.second;
        i=j-1;
    }
    return {endpos,ans};
}

pair<int,int> readNum2(int pos) {
    int num=0;
    int endpos=n;
    _rep(i,pos,n) {
        if (!isdigit(s[i])) {
            endpos=i-1;
            break;
        }
        num=num*10+(s[i]-'0');
    }
    return {endpos,num};
}

pair<int,double> readWaterMixture(int pos) {
    auto t=readNum2(pos);
    if (!t.second) t.second=1;
    int j=t.first+6;
    return {j,(element["H"]*2.0+element["O"])*t.second};
}

int main() {
    init();
    scanf("%s",s+1); n=strlen(s+1);
    _rep(i,1,n) {
        pair<int,double> t;
        if (s[i]=='(') t=readPart(i+1);
        else if (s[i]=='~') t=readWaterMixture(i+1);
        else t=readElement(i);
        int j=t.first+1;
        if (j<=n && s[j]=='_') {
            auto p=readNum(j);
            ans+=t.second*p.second;
            j=p.first+1;
        } else ans+=t.second;
        i=j-1;
    }
    if (ans-floor(ans)<eps) printf("%d",(int)floor(ans));
    else printf("%.1lf",ans);
    return 0;
}