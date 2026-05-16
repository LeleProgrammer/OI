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
        while (!isspace(c)) x[idx++]=c,c=getchar();
        x[idx]='\0';
    }
    template<typename T> inline void write(T x) {
        if (x<0) putchar('-'),x=-x;
        if (x/10) write(x/10);
        putchar('0'+(x%10));
    }
    template<typename T> inline void writesp(T x) { write(x); putchar(' '); }
    template<typename T> inline void writeln(T x) { write(x); putchar(10); }
    inline void writestr(string& x) { _iter(it,x) putchar(*it); }
    inline void writestr(char* x) { _rep(i,0,strlen(x)) putchar(x[i]); }
    inline void writestrsp(string& x) { _iter(it,x) putchar(*it); putchar(' '); }
    inline void writestrsp(char* x) { _rep(i,0,strlen(x)) putchar(x[i]); putchar(' '); }
    inline void writestrln(string& x) { _iter(it,x) putchar(*it); putchar(10); }
    inline void writestrln(char* x) { _rep(i,0,strlen(x)) putchar(x[i]); putchar(10); }
};

using namespace IO;

const int N=200005;
const int inf=2e9;

int n,w,q,cur;
int flag[N];

struct node {
    int y,i;
};

vector<node> vec[N];

bool cmp(const node& a,const node& b) {
    return a.y>b.y;
}

int main() {
    read(n),read(w);
    _rep(i,1,n) {
        int x,y;
        read(x),read(y);
        vec[x].emplace_back(node{y,i});
    }
    _rep(i,1,w) sort(vec[i].begin(),vec[i].end(),cmp);
    _rep(i,1,n) flag[i]=inf;
    _rep(i,1,n) {
        bool ok=true;
        int mx=1;
        _rep(j,1,w) {
            if (vec[j].empty()) {
                ok=false;
                break;
            }
            mx=max(mx,max(1,vec[j].back().y-cur));
        }
        if (!ok) break;
        _rep(j,1,w) flag[vec[j].back().i]=cur+mx,vec[j].pop_back();
        cur+=mx;
    }
    // printf("flag: "); _rep(i,1,n) printf("%d ",flag[i]); putchar(10);
    read(q);
    while (q--) {
        int t,a;
        read(t),read(a);
        if (flag[a]<=t) puts("No");
        else puts("Yes");
    }
    return 0;
}