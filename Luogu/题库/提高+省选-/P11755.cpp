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
typedef pair<pii,int> piii;
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
    inline void writestr(char* x) { _rep(i,0,strlen(x)) putchar(x[i]); }
    inline void writestrsp(string x) { _iter(it,x) putchar(*it); putchar(' '); }
    inline void writestrsp(char* x) { _rep(i,0,strlen(x)) putchar(x[i]); putchar(' '); }
    inline void writestrln(string x) { _iter(it,x) putchar(*it); putchar(10); }
    inline void writestrln(char* x) { _rep(i,0,strlen(x)) putchar(x[i]); putchar(10); }
};

using namespace IO;

const int N=1000005;
const int M=2000005;

int n,q;
int e[M],ne[M],h[N],tot;
int dep[N],fa[N],sz[N],son[N],top[N],id[N],cnt;
int des[M];
int ans[N];
vector<piii> vec;

struct Seg {
    int l,r;
    int v;
    int s;
} tr[N<<2];

void add(int a,int b) {
    e[tot]=b,ne[tot]=h[a],h[a]=tot++;
}

void dfs1(int u,int p,int d) {
    dep[u]=d,sz[u]=1,fa[u]=p;
    _graph(i,u) {
        if (e[i]==fa[u]) continue;
        des[i]=des[i^1]=e[i];
        dfs1(e[i],u,d+1);
        sz[u]+=sz[e[i]];
        if (sz[e[i]]>sz[son[u]]) son[u]=e[i];
    }
}

void dfs2(int u,int p) {
    id[u]=++cnt,top[u]=p;
    if (!son[u]) return;
    dfs2(son[u],p);
    _graph(i,u) {
        if (e[i]==fa[u] || e[i]==son[u]) continue;
        dfs2(e[i],e[i]);
    }
}

void pushdown(int u) {
    auto &root=tr[u],&left=tr[u<<1],&right=tr[u<<1|1];
    if (~root.v) {
        left.v=right.v=root.v;
        left.s=right.s=root.v;
        root.v=-1;
    }
}

void build(int u,int l,int r) {
    tr[u]={l,r,0,-1};
    if (l==r) return;
    int mid=l+r>>1;
    build(u<<1,l,mid); build(u<<1|1,mid+1,r);
}

void modify(int u,int l,int r,int k) {
    if (tr[u].l>=l && tr[u].r<=r) tr[u].s=tr[u].v=k;
    else {
        pushdown(u);
        int mid=tr[u].l+tr[u].r>>1;
        if (l<=mid) modify(u<<1,l,r,k);
        if (r>mid) modify(u<<1|1,l,r,k);
    }
}

void query(int u) {
    if (tr[u].l==tr[u].r) ans[tr[u].l]=tr[u].s;
    else {
        pushdown(u);
        query(u<<1),query(u<<1|1);
    }
}

void modify_path(int u,int v,int i) {
    while (top[u]!=top[v]) {
        if (dep[top[u]]<dep[top[v]]) swap(u,v);
        // modify(1,id[top[u]],id[u],i);
        vec.emplace_back(piii{{id[top[u]],id[u]},i});
        u=fa[top[u]];
    }
    if (u==v) return;
    if (dep[u]<dep[v]) swap(u,v);
    // modify(1,id[son[v]],id[u],i);
    vec.emplace_back(piii{{id[son[v]],id[u]},i});
}

int main() {
    memset(h,-1,sizeof(h));
    read(n),read(q);
    _rep(i,1,n-1) {
        int a,b;
        read(a),read(b);
        add(a,b),add(b,a);
    }
    dfs1(1,0,1);
    dfs2(1,1);
    build(1,1,n);
    _rep(i,1,q) {
        int a,b;
        read(a),read(b);
        modify_path(a,b,i);
    }
    _iter(it,vec) {
        int a=it->first.first;
        int b=it->first.second;
        int k=it->second;
        modify(1,a,b,k);
    }
    query(1);
    _reps(i,0,tot-1,i+=2) writesp(ans[id[des[i]]]);
    return 0;
}