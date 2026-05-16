#include <bits/stdc++.h>
using namespace std;

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
        while (isdigit(c)) x=x*10+(c-'0'),c=getchar();
        x*=s;
    }
    inline void readstr(string& x) {
        x.clear(); char c=getchar();
        while (isspace(c)) c=getchar();
        while (!isspace(c)) x.push_back(c),c=getchar();
    }
    inline void readstr(char* x) {
        int idx=0; char c=getchar();
        while (isspace(c)) c=getchar();
        while (!isspace(c)) x[++idx]=c,c=getchar();
    }
    template<typename T> inline void write(T x) {
        if (x<0) putchar('-'),x=-x;
        if (x/10) write(x/10);
        putchar('0'+(x%10));
    }
    template<typename T> inline void writesp(T x) { write(x); putchar(' '); }
    template<typename T> inline void writeln(T x) { write(x); putchar(10); }
};

using namespace IO;

const int N=500005;

int T,n,m;

struct node {
    int a,b;
    friend bool operator < (const node& a,const node& b) {
        return a.b-a.a>b.b-b.a;
    }
} arr[N];

int main() {
    read(T);
    while (T--) {
        read(n),read(m);
        i64 ans=0;
        _rep(i,1,n) read(arr[i].a),read(arr[i].b),ans+=arr[i].a;
        if (n==1) {
            writeln(arr[1].b);
            continue;
        }
        sort(arr+1,arr+1+n);
        int cur=1;
        _rep(i,1,n-1) {
            if (arr[i].b-arr[i].a<=0) break;
            if (i==n-1) {
                if (cur+1+n-i<=m) ans=max(ans,ans+arr[i].b-arr[i].a+arr[n].b-arr[n].a);
                break;
            }
            if (cur+1+n-i<=m) ans+=arr[i].b-arr[i].a,cur+=2;
            else break;
        }
        writeln(ans);
    }
    return 0;
}