#include <bits/stdc++.h>
using namespace std;

#define int long long

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

const int N=200005;
const int inf=1e9;

int n,q,x=1,y=1,ans;
vector<int> vx[N],vy[N];
vector<int> px[N],py[N];

struct node {
    int x,y,w;
    friend bool operator < (const node& a,const node& b) {
        if (a.x!=b.x) return a.x<b.x;
        else return a.y<b.y;
    }
} arr[N];

i32 main() {
    read(n),read(q);
    _rep(i,1,n) {
        int x,y,w;
        read(x),read(y),read(w);
        arr[i]={x,y,w};
    }
    sort(arr+1,arr+1+n);
    _rep(i,1,N-1) vx[i].emplace_back(-1),vy[i].emplace_back(-1),px[i].emplace_back(-1),py[i].emplace_back(-1);
    _rep(i,1,n) {
        int x=arr[i].x,y=arr[i].y,w=arr[i].w;
        vx[x].emplace_back(y);
        px[x].emplace_back(w);
        vy[y].emplace_back(x);
        py[y].emplace_back(w);
    }
    _rep(i,1,N-1) vx[i].emplace_back(inf),vy[i].emplace_back(inf),px[i].emplace_back(inf),py[i].emplace_back(inf);
    _rep(i,1,N-1) {
        _rep(j,1,(int)px[i].size()-1) px[i][j]+=px[i][j-1];
        _rep(j,1,(int)py[i].size()-1) py[i][j]+=py[i][j-1];
    }
    while (q--) {
        int d,v;
        read(d),read(v);
        if (!d) {
            int nx=x+v,ny=y;
            int l=upper_bound(vy[y].begin(),vy[y].end(),x)-vy[y].begin()-1;
            int r=upper_bound(vy[y].begin(),vy[y].end(),nx)-vy[y].begin()-1;
            ans+=py[y][r];
            ans-=py[y][l];
            x=nx,y=ny;
        } else if (d==1) {
            int nx=x,ny=y+v;
            int l=upper_bound(vx[x].begin(),vx[x].end(),y)-vx[x].begin()-1;
            int r=upper_bound(vx[x].begin(),vx[x].end(),ny)-vx[x].begin()-1;
            ans+=px[x][r];
            ans-=px[x][l];
            x=nx,y=ny;
        } else if (d==2) {
            int nx=x-v,ny=y;
            int l=lower_bound(vy[y].begin(),vy[y].end(),nx)-vy[y].begin()-1;
            int r=lower_bound(vy[y].begin(),vy[y].end(),x)-vy[y].begin()-1;
            ans+=py[y][r];
            ans-=py[y][l];
            x=nx,y=ny;
        } else {
            int nx=x,ny=y-v;
            int l=lower_bound(vx[x].begin(),vx[x].end(),ny)-vx[x].begin()-1;
            int r=lower_bound(vx[x].begin(),vx[x].end(),y)-vx[x].begin()-1;
            ans+=px[x][r];
            ans-=px[x][l];
            x=nx,y=ny;
        }
    }
    write(ans);
    return 0;
}