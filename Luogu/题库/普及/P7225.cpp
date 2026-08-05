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

const int N=505;

int n;
int arr[N][N];
bool vis[N][N];
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
char dc[]={'W','D','S','A'};
char rdc[]={'S','A','W','D'};

extern "C" bool move_to(char position);

bool check(int x,int y) {
    if (x<=0 || y<=0 || x>n || y>n) return false;
    if (vis[x][y]) return false;
    return true;
}

void dfs(int x,int y,char las) {
    vis[x][y]=true;
    arr[x][y]=1;
    _rep(i,0,3) {
        int nx=x+dx[i];
        int ny=y+dy[i];
        if (las=='W' && dc[i]=='S') continue;
        if (las=='S' && dc[i]=='W') continue;
        if (las=='D' && dc[i]=='A') continue;
        if (las=='A' && dc[i]=='D') continue;
        if (!check(nx,ny)) continue;
        if (!move_to(dc[i])) {
            vis[nx][ny]=true;
            continue;
        }
        dfs(nx,ny,dc[i]);
        move_to(rdc[i]);
    }
}

extern "C" string find_out_map(int x,int y,int nn) {
    memset(arr,0,sizeof(arr));
    memset(vis,0,sizeof(vis));
    n=nn;
    dfs(x,y,' ');
    string ans;
    _rep(i,1,n) _rep(j,1,n) ans.push_back((char)(arr[i][j]^1)+'0');
    return ans;
}