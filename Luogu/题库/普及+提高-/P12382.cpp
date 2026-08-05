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

const int N=200005;
const int M=400005;

int n,ans;
int e[M],ne[M],h[N],fa[N],tot;
int v[N];
int mx[N],smx[N],p[N],q[N],mxdep;
vector<int> d[N];
int f[N];

void add(int a,int b) {
    e[tot]=b,ne[tot]=h[a],h[a]=tot++;
}

void dfs(int u,int dep) {
    mxdep=max(mxdep,dep),d[dep].emplace_back(u);
    _graph(i,u) {
        if (e[i]==fa[u]) continue;
        dfs(e[i],dep+1);
    }
}

bool cmp(const int& a,const int& b) {
    return f[a]>f[b];
}

int main() {
    memset(h,-1,sizeof(h));
    read(n);
    _rep(i,2,n) {
        int k;
        read(k);
        fa[i]=k;
        add(i,k),add(k,i);
    }
    _rep(i,1,n) read(v[i]);
    dfs(1,1);
    _rrep(i,mxdep,1) {
        mx[i+2]=max(mx[i+2],mx[i+3]);
        _iter(it,d[i]) {
            int j=*it;
            if (p[i+1]==j) f[j]=smx[i+1]+v[j];
            else f[j]=mx[i+1]+v[j];
            f[j]=max(f[j],mx[i+2]+v[j]);
            ans=max(ans,f[j]);
        }
        sort(d[i].begin(),d[i].end(),cmp);
        _iter(it,d[i]) {
            int j=*it;
            if (!mx[i]) mx[i]=f[j],p[i]=fa[j];
            else if (fa[j]!=p[i]) {
                smx[i]=f[j],q[i]=fa[j];
                break;
            }
        }
    }
    // _rep(i,1,n) printf("f[%d] = %d\n",i,f[i]);
    write(ans);
    return 0;
}

/*
HACK:

5
1 2 3 4
2 1 1 1000 1

ans: 1002
*/