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
#define _dinic(i,u) for (int i=cur[u];~i && k<limit;i=ne[i])
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
        while (isdigit(c) && c!=EOF) x=x*10+(c-'0'),c=getchar();
        x*=s;
    }
    inline void readstr(string& x) {
        x.clear(); char c=getchar();
        while (isspace(c)) c=getchar();
        while (!isspace(c) && c!=EOF) x.push_back(c),c=getchar();
    }
    inline void readstr(char* x) {
        int idx=0; char c=getchar();
        while (isspace(c)) c=getchar();
        while (!isspace(c) && c!=EOF) x[idx++]=c,c=getchar();
        x[idx]='\0';
    }
    template<typename T> inline void write(T x) {
        if (x<0) putchar('-'),x=-x;
        if (x/10) write(x/10);
        putchar('0'+(x%10));
    }
    template<typename T> inline void writesp(T x) { write(x); putchar(' '); }
    template<typename T> inline void writeln(T x) { write(x); putchar(10); }
    inline void writestr(string x) { _iter(it,x) putchar(*it); }
    inline void writestr(char* x) { _rep(i,0,strlen(x)-1) putchar(x[i]); }
    inline void writestrsp(string x) { _iter(it,x) putchar(*it); putchar(' '); }
    inline void writestrsp(char* x) { _rep(i,0,strlen(x)-1) putchar(x[i]); putchar(' '); }
    inline void writestrln(string x) { _iter(it,x) putchar(*it); putchar(10); }
    inline void writestrln(char* x) { _rep(i,0,strlen(x)-1) putchar(x[i]); putchar(10); }
};

using namespace IO;

const int N=1005;

int n;
vector<pii> ans;
bool flag[N][N];

int main() {
    read(n);
    if (n&1) {
        int x=0,y=0,xx=1,yy=1;
        while (x!=n || y!=n) {
            int nx=x+xx,ny=y+yy;
            if (nx>n || nx<0) {
                xx*=-1,yy*=-1;
                continue;
            }
            ans.emplace_back(pii{nx,ny});
            x=nx,y=ny;
            yy*=-1;
        }
    } else {
        int x=0,y=0,xx=1,yy=1;
        flag[0][n]=flag[n][0]=true;
        while (x!=n || y!=n) {
            int nx=x+xx,ny=y+yy;
            if (flag[x+1][y-1]) {
                yy*=-1,flag[x][y]=true;
                ny=y+yy;
                ans.emplace_back(pii{nx,ny}),x=nx,y=ny,yy*=-1;
            } else if (nx>n || nx<0) xx*=-1,yy*=-1;
            else ans.emplace_back(pii{nx,ny}),x=nx,y=ny,yy*=-1;
        }
    }
    writeln(ans.size());
    _rep(i,0,(int)ans.size()-1) writesp(ans[i].first),writeln(ans[i].second);
    return 0;
}