#include <bits/stdc++.h>
using namespace std;

#define int long long

#define endl '\n'
#define FRR(file) freopen(file,"r",stdin)
#define FRW(file) freopen(file,"w",stdout)
#define _rep(i,a,b) for (int i=(a);i<=(b);++i)
#define _reps(i,a,b,c) for (int i=(a);i<=(b);c)
#define _rrep(i,a,b) for (int i=(a);i>=(b);--i)
#define _rreps(i,a,b,c) for (int i=(a);i>=(b);c)
#define _iter(i,a) for (auto i=a.begin();i!=a.end();++i)
#define _graph(i,u) for (int i=h[u];~i;i=ne[i])
#define rint register int
#define LL long long
typedef pair<int,int> pii;

const int N=200005;
const int M=400005;

int n,q;
int e[M],ne[M],w[M],h[N],tot;
int layer[N],fa[N],top[N],son[N],sz[N],idx;
int id[N],arr[N],tmp[N];
int from[N],to[N];

void add(int a,int b,int c) {
    e[tot]=b,ne[tot]=h[a],w[tot]=c,h[a]=tot++;
}

struct Seg {
    int l,r;
    int sum;
} tr[N<<2];

void dfs(int u,int p,int dep) {
    fa[u]=p;
    layer[u]=dep;
    sz[u]=1;
    _graph(i,u) {
        if (e[i]==p) continue;
        tmp[e[i]]=w[i];
        dfs(e[i],u,dep+1);
        sz[u]+=sz[e[i]];
        if (sz[e[i]]>sz[son[u]]) son[u]=e[i];
    }
}

void dfs2(int u,int p) {
    top[u]=p;
    id[u]=++idx;
    arr[id[u]]=tmp[u];
    if (!son[u]) return;
    dfs2(son[u],p);
    _graph(i,u) {
        if (e[i]==fa[u] || e[i]==son[u]) continue;
        dfs2(e[i],e[i]);
    }
}

void pushup(int u) {
    tr[u].sum=tr[u<<1].sum+tr[u<<1|1].sum;
}

void build(int u,int l,int r) {
    tr[u]={l,r,arr[l]};
    if (l==r) return;
    int mid=l+r>>1;
    build(u<<1,l,mid); build(u<<1|1,mid+1,r);
    pushup(u);
}

void modify(int u,int p,int k) {
    if (tr[u].l==p && tr[u].r==p) {
        tr[u].sum=k;
    } else {
        int mid=tr[u].l+tr[u].r>>1;
        if (p<=mid) modify(u<<1,p,k);
        else modify(u<<1|1,p,k);
        pushup(u);
    }
}

int query(int u,int l,int r) {
    if (tr[u].l>=l && tr[u].r<=r) return tr[u].sum;
    int mid=tr[u].l+tr[u].r>>1;
    int ans=0;
    if (l<=mid) ans+=query(u<<1,l,r);
    if (r>mid) ans+=query(u<<1|1,l,r);
    return ans;
}

int query_path(int u,int v) {
    int ans=0;
    while (top[u]!=top[v]) {
        if (layer[top[u]]<layer[top[v]]) swap(u,v);
        ans+=query(1,id[top[u]],id[u]);
        u=fa[top[u]];
    }
    if (layer[u]<layer[v]) swap(u,v);
    ans+=query(1,id[v],id[u]);
    ans-=query(1,id[v],id[v]);
    return ans;
}

signed main() {
    memset(h,-1,sizeof(h));
    scanf("%lld",&n);
    _rep(i,1,n-1) {
        int a,b,c;
        scanf("%lld %lld %lld",&a,&b,&c);
        from[i]=a,to[i]=b;
        add(a,b,c);
        add(b,a,c);
    }
    dfs(1,0,1);
    dfs2(1,1);
    build(1,1,n);
    scanf("%lld",&q);
    while (q--) {
        int op,a,b;
        scanf("%lld %lld %lld",&op,&a,&b);
        if (op==1) modify(1,layer[from[a]]>layer[to[a]]?id[from[a]]:id[to[a]],b);
        else printf("%lld\n",query_path(a,b));
    }
    return 0;
}