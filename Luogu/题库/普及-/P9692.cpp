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
    template<typename T> inline void write(T x) {
        if (x<0) putchar('-'),x=-x;
        if (x/10) write(x/10);
        putchar('0'+(x%10));
    }
    template<typename T> inline void writesp(T x) { write(x); putchar(' '); }
    template<typename T> inline void writeln(T x) { write(x); putchar(10); }
};

using namespace IO;

const int N=100005;

int T,n;
pii arr[N];
deque<pii> q;

bool cmp(const pii& a,const pii& b) {
    return a.first<b.first;
}

int main() {
    read(T);
    while (T--) {
        read(n);
        _rep(i,1,n) read(arr[i].first),read(arr[i].second);
        sort(arr+1,arr+1+n,cmp);
        q.clear();
        _rep(i,1,n) q.emplace_back(arr[i]);
        i64 ans=0;
        while ((int)q.size()>=2) {
            if ((int)q.size()>=2) {
                int t=min(q.front().second,q.back().second);
                ans+=(i64)(q.back().first-q.front().first)*t;
                q.back().second-=t;
                q.front().second-=t;
                if (!q.back().second) q.pop_back();
                if (!q.front().second) q.pop_front();
            }
        }
        writeln(ans);
    }
    return 0;
}