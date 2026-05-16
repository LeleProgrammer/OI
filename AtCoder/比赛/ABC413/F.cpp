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

const int N=3005;

int n,m,k;
int arr[N][N];
queue<pii> q;
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
map<pii,int> cnt;

bool check(int x,int y) {
    return x>=1 && x<=n && y>=1 && y<=m && !~arr[x][y];
}

void process() {
    int cur=arr[q.front().first][q.front().second];
    while (!q.empty()) {
        auto u=q.front(); q.pop();
        _rep(i,0,3) {
            int nx=u.first+dx[i],ny=u.second+dy[i];
            if (check(nx,ny)) cnt[pii{nx,ny}]++;
        }
    }
    vector<pii> del;
    _iter(it,cnt) {
        auto pos=it->first;
        int k=it->second;
        if (k>=2) arr[pos.first][pos.second]=cur+1,q.emplace(pos),del.emplace_back(pos);
    }
    _iter(it,del) cnt.erase(*it);
}

i32 main() {
    memset(arr,-1,sizeof(arr));
    read(n),read(m),read(k);
    while (k--) {
        int a,b;
        read(a),read(b);
        arr[a][b]=0;
        q.emplace(pii{a,b});
    }
    while (!q.empty()) process();
    int ans=0;
    // _rep(i,1,n) {
    //     _rep(j,1,m) writesp(arr[i][j]);
    //     putchar(10);
    // }
    _rep(i,1,n) _rep(j,1,m) if (~arr[i][j]) ans+=arr[i][j];
    write(ans);
    return 0;
}