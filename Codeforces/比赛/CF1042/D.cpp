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

const int N=200005;
const int M=400005;

int T,n;
int e[M],ne[M],h[N],tot;
int deg[N];
int dep[N];
int cnt[N];
int ans;

void add(int a,int b) {
    e[tot]=b,ne[tot]=h[a],h[a]=tot++;
}

int dfs(int u,int fa,int d) {
    dep[u]=d;
    int mx=d;
    _graph(i,u) {
        if (e[i]==fa) continue;
        mx=max(mx,dfs(e[i],u,d+1));
    }
    return mx;
}

void dfs2(int u,int fa) {
    bool flag=false;
    _graph(i,u) {
        if (e[i]==fa) continue;
        dfs2(e[i],u);
        flag=true;
        cnt[u]+=cnt[e[i]];
    }
    if (!flag) cnt[u]=1;
    else {
        ans=min(ans,-cnt[u]);
        cnt[u]=0;
    }
}

int main() {
    read(T);
    while (T--) {
        read(n);
        _rep(i,1,n) h[i]=-1,deg[i]=dep[i]=cnt[i]=0; tot=0;
        ans=0;
        _rep(i,1,n-1) {
            int a,b;
            read(a),read(b);
            add(a,b);
            add(b,a);
            deg[a]++,deg[b]++;
        }
        if (n==2) {
            puts("0");
            continue;
        }
        int mx=1;
        _rep(i,2,n) if (deg[i]>deg[mx]) mx=i;
        int mxdep=dfs(mx,0,1);
        if (mxdep==2) puts("0");
        else {
            dfs2(mx,0);
            // cout<<"test: "<<ans<<endl;
            _rep(i,1,n) if (deg[i]==1) ans++;
            writeln(ans);
        }
    }
    return 0;
}