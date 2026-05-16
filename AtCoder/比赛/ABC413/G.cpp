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

const int N=5000005;
const int M=50000005;

int n,m,k,idx;
vector<pii> vec[N];
vector<int> g[N];
int p[N];
int e[M],ne[M],h[N],tot;
queue<int> q;
bool vis[N];

void add(int a,int b) {
    e[tot]=b,ne[tot]=h[a],h[a]=tot++;
}

void bfs() {
    q.emplace(1);
    vis[1]=true;
    while (!q.empty()) {
        int u=q.front(); q.pop();
        _graph(i,u) if (!vis[e[i]]) q.emplace(e[i]),vis[e[i]]=true;
    }
}

struct node {
    int a,b;
    friend bool operator < (const node& a,const node& b) {
        if (a.a!=b.a) return a.a<b.a;
        else return a.b<b.b;
    }
} arr[N];

int main() {
    memset(h,-1,sizeof(h));
    read(n),read(m),read(k);
    _rep(i,1,k) {
        int a,b;
        read(a),read(b);
        arr[i]={a,b};
    }
    sort(arr+1,arr+1+k);
    _rep(i,1,n) vec[i].emplace_back(pii{1,m});
    _rep(i,1,k) {
        int a=arr[i].a,b=arr[i].b;
        if (b==vec[a].back().first) vec[a].back().first++;
        else if (b==vec[a].back().second) vec[a].back().second--;
        else {
            auto t=vec[a].back();
            vec[a].pop_back();
            vec[a].emplace_back(pii{t.first,b-1});
            vec[a].emplace_back(pii{b+1,t.second});
        }
        if (vec[a].back().first>vec[a].back().second) vec[a].pop_back();
    }
    _rep(i,1,n) _rep(j,0,(int)vec[i].size()-1) g[i].emplace_back(++idx);
    _rep(i,2,n) {
        _rep(j,0,(int)vec[i].size()-1) {
            while (p[i-1]<=(int)vec[i-1].size()-1 && vec[i-1][p[i-1]].second<vec[i][j].first) p[i-1]++;
            while (p[i-1]<=(int)vec[i-1].size()-1 && vec[i-1][p[i-1]].first<=vec[i][j].second) add(g[i-1][p[i-1]],g[i][j]),add(g[i][j],g[i-1][p[i-1]]),p[i-1]++;
            p[i-1]--;
            if (p[i-1]<0) p[i-1]++;
        }
    }
    bfs();
    if (vis[idx]) puts("Yes");
    else puts("No");
    return 0;
}