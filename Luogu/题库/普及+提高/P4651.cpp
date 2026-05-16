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
    inline void writestr(string& x) { _iter(it,x) putchar(*it); }
    inline void writestr(char* x) { _rep(i,0,strlen(x)-1) putchar(x[i]); }
    inline void writestrsp(string& x) { _iter(it,x) putchar(*it); putchar(' '); }
    inline void writestrsp(char* x) { _rep(i,0,strlen(x)-1) putchar(x[i]); putchar(' '); }
    inline void writestrln(string& x) { _iter(it,x) putchar(*it); putchar(10); }
    inline void writestrln(char* x) { _rep(i,0,strlen(x)-1) putchar(x[i]); putchar(10); }
};

using namespace IO;

const int N=255005;
const int M=1550005;
const int inf=1e9;

int n,m;
int sx,sy,tx,ty;
int e[M],w[M],ne[M],h[N],tot;
int dis[N][2];
bool flag[N][2];
priority_queue<piii,vector<piii>,greater<piii>> q;

void add(int a,int b,int c) {
    e[tot]=b,w[tot]=c,ne[tot]=h[a],h[a]=tot++;
    e[tot]=a,w[tot]=c,ne[tot]=h[b],h[b]=tot++;
}

int get(int i,int j) {
    return (i-1)*m+j;
}

void dijkstra() {
    _rep(i,1,N-1) dis[i][0]=dis[i][1]=inf;
    q.emplace(piii{dis[get(sx,sy)][0]=0,pii{get(sx,sy),0}});
    q.emplace(piii{dis[get(sx,sy)][1]=0,pii{get(sx,sy),1}});
    while (!q.empty()) {
        auto tp=q.top(); q.pop();
        auto cur=tp.second;
        int u=cur.first,k=cur.second;
        if (flag[u][k]) continue;
        flag[u][k]=true;
        _graph(i,u) if (w[i]==(k^1) && dis[e[i]][k^1]>dis[u][k]+1) q.emplace(piii{dis[e[i]][k^1]=dis[u][k]+1,pii{e[i],k^1}});
    }
}

int main() {
    memset(h,-1,sizeof(h));
    read(m),read(n),m++,n++;
    read(sy),read(sx),read(ty),read(tx);
    sx++,sy++,tx++,ty++;
    _rep(i,1,n*2-1) {
        int cur=0;
        _rep(j,1,(i&1)?(m-1):(m*2-1)) {
            if (j&1) cur++;
            char c;
            scanf(" %c",&c);
            if (c=='n') continue;
            else if (c=='b') {
                if (i&1) add(get((i+1)>>1,j),get((i+1)>>1,j+1),0);
                else if (j&1) add(get(i>>1,cur),get((i>>1)+1,cur),0);
                else add(get(i>>1,cur+1),get((i>>1)+1,cur),0);
            } else {
                if (i&1) add(get((i+1)>>1,j),get((i+1)>>1,j+1),1);
                else if (j&1) add(get(i>>1,cur),get((i>>1)+1,cur),1);
                else add(get(i>>1,cur+1),get((i>>1)+1,cur),1);
            }
        }
    }
    dijkstra();
    write(min(dis[get(tx,ty)][0],dis[get(tx,ty)][1]));
    return 0;
}