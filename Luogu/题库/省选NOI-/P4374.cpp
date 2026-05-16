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
typedef pair<int,int> pii;

const int N=50005;
const int M=100005;
const int inf=2e9;

int n,m;
int e[M],ne[M],h[N],tot;
pii dest[N];
int layer[N],sz[N],top[N],son[N],fa[N],id[N],cnt;

struct Seg {
    int l,r;
    int min,tag;
} tr[N<<2];

void add(int a,int b) {
    e[tot]=b,ne[tot]=h[a],h[a]=tot++;
}

void dfs1(int u,int p,int dep) {
    sz[u]=1,fa[u]=p,layer[u]=dep;
    _graph(i,u) {
        if (e[i]==fa[u]) continue;
        dfs1(e[i],u,dep+1);
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

void pushup(int u) {
    tr[u].min=min(tr[u<<1].min,tr[u<<1|1].min);
}

void pushdown(int u) {
    auto &root=tr[u],&left=tr[u<<1],&right=tr[u<<1|1];
    left.min=min(left.min,root.tag);
    right.min=min(right.min,root.tag);
    left.tag=min(left.tag,root.tag);
    right.tag=min(right.tag,root.tag);
    root.tag=inf;
}

void build(int u,int l,int r) {
    tr[u]={l,r,inf,inf};
    if (l==r) return;
    int mid=l+r>>1;
    build(u<<1,l,mid); build(u<<1|1,mid+1,r);
    pushup(u);
}

void modify(int u,int l,int r,int k) {
    if (tr[u].l>=l && tr[u].r<=r) {
        tr[u].min=min(tr[u].min,k);
        tr[u].tag=min(tr[u].tag,k);
    } else {
        pushdown(u);
        int mid=tr[u].l+tr[u].r>>1;
        if (l<=mid) modify(u<<1,l,r,k);
        if (r>mid) modify(u<<1|1,l,r,k);
        pushup(u);
    }
}

int query(int u,int p) {
    if (tr[u].l==p && tr[u].r==p) return tr[u].min;
    pushdown(u);
    int mid=tr[u].l+tr[u].r>>1;
    if (p<=mid) return query(u<<1,p);
    else return query(u<<1|1,p);
}

void modify_path(int u,int v,int k) {
    while (top[u]!=top[v]) {
        if (layer[top[u]]<layer[top[v]]) swap(u,v);
        modify(1,id[top[u]],id[u],k);
        u=fa[top[u]];
    }
    if (layer[u]<layer[v]) swap(u,v);
    if (u!=v) modify(1,id[son[v]],id[u],k);
}

int main() {
    memset(h,-1,sizeof(h));
    scanf("%d %d",&n,&m);
    _rep(i,1,n-1) {
        int a,b;
        scanf("%d %d",&a,&b);
        dest[i]={a,b};
        add(a,b); add(b,a);
    }
    dfs1(1,0,1);
    dfs2(1,1);
    build(1,1,n);
    while (m--) {
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        modify_path(a,b,c);
    }
    _rep(i,1,n-1) {
        if (layer[dest[i].first]<layer[dest[i].second]) swap(dest[i].first,dest[i].second);
        int k=dest[i].first;
        int ans=query(1,id[k]);
        if (ans==inf) puts("-1");
        else printf("%d\n",ans);
    }
    return 0;
}