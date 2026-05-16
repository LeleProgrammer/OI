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

const int N=30005;
const int K=15;
const int M=60005;

int n,q;
int e[M],ne[M],w[M],h[N],tot;
int dep[N],son[N],fa[N],top[N],sz[N],id[N],arr[N],s[N],g[N],idx;

struct Seg {
    int l,r;
    int k,sum,rev;
} tr[K][N<<2];

void add(int a,int b,int c) {
    e[tot]=b,w[tot]=c,ne[tot]=h[a],h[a]=tot++;
}

void dfs1(int u,int p,int d) {
    fa[u]=p,dep[u]=d,sz[u]=1;
    _graph(i,u) {
        if (e[i]==p) continue;
        dfs1(e[i],u,d+1);
        sz[u]+=sz[e[i]],g[e[i]]=w[i];
        if (sz[e[i]]>sz[son[u]]) son[u]=e[i];
    }
}

void dfs2(int u,int t,int v) {
    top[u]=t,id[u]=++idx,arr[id[u]]=v;
    if (!son[u]) return;
    dfs2(son[u],t,v^g[son[u]]);
    _graph(i,u) {
        if (e[i]==fa[u]) continue;
        if (e[i]==son[u]) continue;
        dfs2(e[i],e[i],v^w[i]);
    }
}

void pushup(int u,Seg* tr) {
    tr[u].sum=tr[u<<1].sum+tr[u<<1|1].sum;
}

void pushdown(int u,Seg* tr) {
    auto &root=tr[u],&left=tr[u<<1],&right=tr[u<<1|1];
    if (root.rev) {
        left.rev^=1,right.rev^=1;
        left.sum=left.r-left.l+1-left.sum;
        right.sum=right.r-right.l+1-right.sum;
        left.k^=1,right.k^=1;
        root.rev^=1;
    }
}

void build(int u,int l,int r,int k,Seg* tr) {
    tr[u]={l,r,(arr[l]>>k)&1,(arr[l]>>k)&1,0};
    if (l==r) return;
    int mid=l+r>>1;
    build(u<<1,l,mid,k,tr),build(u<<1|1,mid+1,r,k,tr);
    pushup(u,tr);
}

void modify(int u,int l,int r,Seg* tr) {
    if (tr[u].l>=l && tr[u].r<=r) tr[u].k^=1,tr[u].sum=tr[u].r-tr[u].l+1-tr[u].sum,tr[u].rev^=1;
    else {
        pushdown(u,tr);
        int mid=tr[u].l+tr[u].r>>1;
        if (l<=mid) modify(u<<1,l,r,tr);
        if (r>mid) modify(u<<1|1,l,r,tr);
        pushup(u,tr);
    }
}

int query(int u,int l,int r,Seg* tr) {
    if (tr[u].l>=l && tr[u].r<=r) return tr[u].sum;
    pushdown(u,tr);
    int ans=0;
    int mid=tr[u].l+tr[u].r>>1;
    if (l<=mid) ans+=query(u<<1,l,r,tr);
    if (r>mid) ans+=query(u<<1|1,l,r,tr);
    return ans;
}

int query_path(int u,int v,int k) {
    int sum=0,tot=0;
    while (top[u]!=top[v]) {
        if (dep[top[u]]<dep[top[v]]) swap(u,v);
        tot+=id[u]-id[top[u]]+1;
        sum+=query(1,id[top[u]],id[u],tr[k]);
        u=fa[top[u]];
    }
    if (dep[u]<dep[v]) swap(u,v);
    tot+=id[u]-id[v]+1;
    sum+=query(1,id[v],id[u],tr[k]);
    return sum*(tot-sum)*(1LL<<k);
}

int solve(int u,int v) {
    int ans=0;
    _rep(i,0,K-1) ans+=query_path(u,v,i);
    return ans;
}

i32 main() {
    memset(h,-1,sizeof(h));
    read(n),read(q);
    _rep(i,1,n-1) {
        int a,b,c;
        read(a),read(b),read(c);
        add(a,b,c),add(b,a,c);
    }
    dfs1(1,0,1);
    dfs2(1,1,0);
    _rep(i,0,K-1) build(1,1,n,i,tr[i]);
    while (q--) {
        int op,u,v;
        read(op),read(u),read(v);
        if (op==1) writeln(solve(u,v));
        else {
            int w;
            read(w);
            if (dep[u]<dep[v]) swap(u,v);
            _rep(i,0,K-1) if (((w>>i)&1)^((g[u]>>i)&1)) modify(1,id[u],id[u]+sz[u]-1,tr[i]);
            g[u]=w;
        }
    }
    return 0;
}