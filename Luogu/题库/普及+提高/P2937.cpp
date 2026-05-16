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
#define _riter(i,a) for (auto i=a.rbegin();i!=a.rend();++i)
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
    inline void writestr(string& x) { _iter(it,x) putchar(*it); }
    inline void writestr(char* x) { _rep(i,0,strlen(x)-1) putchar(x[i]); }
    inline void writestrsp(string& x) { _iter(it,x) putchar(*it); putchar(' '); }
    inline void writestrsp(char* x) { _rep(i,0,strlen(x)-1) putchar(x[i]); putchar(' '); }
    inline void writestrln(string& x) { _iter(it,x) putchar(*it); putchar(10); }
    inline void writestrln(char* x) { _rep(i,0,strlen(x)-1) putchar(x[i]); putchar(10); }
};

using namespace IO;

const int N=40005;
const int M=5000005;
const int inf=2e9;

int n,m;
char arr[N];
int e[M],ne[M],w[M],h[N],tot;
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
int dis[N];
bool flag[N];
deque<int> q;
vector<int> vec;

int get(int i,int j) {
    return (i-1)*m+j;
}

void add(int a,int b,int c) {
    e[tot]=b,w[tot]=c,ne[tot]=h[a],h[a]=tot++;
}

void bfs() {
    _rep(i,1,N-1) dis[i]=inf;
    _rep(p,0,3) q.emplace_front(vec[0]+p*n*m),dis[vec[0]+p*n*m]=0;
    while (!q.empty()) {
        int u=q.front(); q.pop_front();
        if (flag[u]) continue;
        flag[u]=true;
        _graph(i,u) {
            if (dis[e[i]]>dis[u]+w[i]) {
                dis[e[i]]=dis[u]+w[i];
                if (w[i]) q.emplace_back(e[i]);
                else q.emplace_front(e[i]);
            }
        }
    }
}

int main() {
    memset(h,-1,sizeof(h));
    read(m),read(n);
    _rep(i,1,n) _rep(j,1,m) {
        char c;
        scanf(" %c",&c);
        arr[get(i,j)]=c;
        if (c=='C') vec.emplace_back(get(i,j));
    }
    _rep(i,1,n) _rep(j,1,m) if (arr[get(i,j)]!='*') _rep(p,0,3) {
        int nx=i+dx[p],ny=j+dy[p];
        if (nx<=0 || ny<=0 || nx>n || ny>m || arr[get(nx,ny)]=='*') continue;
        add(p*n*m+get(i,j),p*n*m+get(nx,ny),0);
    }
    _rep(i,1,n) _rep(j,1,m) _rep(p,0,2) _rep(q,p+1,3) add(p*n*m+get(i,j),q*n*m+get(i,j),1),add(q*n*m+get(i,j),p*n*m+get(i,j),1);
    bfs();
    // _rep(i,1,n) {
    //     _rep(j,1,m) {
    //         int ans=inf;
    //         _rep(p,0,3) ans=min(ans,dis[p*n*m+get(i,j)]);
    //         if (ans==inf) putchar('-'),putchar(' ');
    //         else writesp(ans);
    //     }
    //     putchar(10);
    // }
    int ans=inf;
    _rep(p,0,3) ans=min(ans,dis[p*n*m+vec[1]]);
    write(ans);
    return 0;
}