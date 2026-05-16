#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N=100005;
const int M=200005;

int n,m;
int a[N];
int e[M],ne[M],h[N],tot;
int id[M],w[M],cnt;
int sizes[N],fa[N],top[N],layer[N],son[N]; // 子树节点个数，父节点，所在重链起点，层，重儿子

struct SegmentTree {
    int l,r;
    int add,sum;
} tr[N*4];

void add(int a,int b) {
    e[tot]=b,ne[tot]=h[a],h[a]=tot++;
}

void dfs1(int u,int p,int dep) {
    layer[u]=dep;
    fa[u]=p;
    sizes[u]=1;
    for (int i=h[u];~i;i=ne[i]) {
        if (e[i]==p) continue;
        dfs1(e[i],u,dep+1);
        sizes[u]+=sizes[e[i]];
        if (sizes[son[u]]<sizes[e[i]]) son[u]=e[i];
    }
}

void dfs2(int u,int p) {
    id[u]=++cnt;
    w[id[u]]=a[u];
    top[u]=p;
    if (!son[u]) return;
    dfs2(son[u],p);
    for (int i=h[u];~i;i=ne[i]) {
        if (e[i]==fa[u] || e[i]==son[u]) continue;
        dfs2(e[i],e[i]);
    }
}

void pushup(int u) {
    tr[u].sum=tr[u<<1].sum+tr[u<<1|1].sum;
}

void pushdown(int u) {
    auto &root=tr[u],&left=tr[u<<1],&right=tr[u<<1|1];
    left.add+=root.add;
    left.sum+=root.add*(left.r-left.l+1);
    right.add+=root.add;
    right.sum+=root.add*(right.r-right.l+1);
    root.add=0;
}

void build(int u,int l,int r) {
    if (l==r) tr[u]={l,r,0,w[l]};
    else {
        tr[u]={l,r,0,0};
        int mid=l+r>>1;
        build(u<<1,l,mid);
        build(u<<1|1,mid+1,r);
        pushup(u);
    }
}

void modify(int u,int l,int r,int k) {
    if (tr[u].l>=l && tr[u].r<=r) {
        tr[u].add+=k;
        tr[u].sum+=k*(tr[u].r-tr[u].l+1);
    } else {
        pushdown(u);
        int mid=tr[u].l+tr[u].r>>1;
        if (l<=mid) modify(u<<1,l,r,k);
        if (r>mid) modify(u<<1|1,l,r,k);
        pushup(u);
    }
}

int query(int u,int l,int r) {
    if (tr[u].l>=l && tr[u].r<=r) return tr[u].sum;
    pushdown(u);
    int mid=tr[u].l+tr[u].r>>1;
    int res=0;
    if (l<=mid) res+=query(u<<1,l,r);
    if (r>mid) res+=query(u<<1|1,l,r);
    return res;
}

void modify_path(int u,int v,int k) {
    while (top[u]!=top[v]) {
        if (layer[top[v]]>layer[top[u]]) swap(u,v);
        modify(1,id[top[u]],id[u],k);
        u=fa[top[u]];
    }
    if (layer[v]>layer[u]) swap(u,v);
    modify(1,id[v],id[u],k);
}

int query_path(int u,int v) {
    int res=0;
    while (top[u]!=top[v]) {
        if (layer[top[v]]>layer[top[u]]) swap(u,v);
        res+=query(1,id[top[u]],id[u]);
        u=fa[top[u]];
    }
    if (layer[v]>layer[u]) swap(u,v);
    res+=query(1,id[v],id[u]);
    return res;
}

signed main() {
    memset(h,-1,sizeof(h));
    scanf("%lld",&n);
    for (int i=1;i<=n;++i) scanf("%lld",&a[i]);
    for (int i=1;i<=n-1;++i) {
        int x,y;
        scanf("%lld %lld",&x,&y);
        add(x,y);
        add(y,x);
    }
    dfs1(1,0,1);
    dfs2(1,1);
    build(1,1,cnt);
    scanf("%lld",&m);
    while (m--) {
        int op;
        scanf("%lld",&op);
        if (op==1) {
            int u,v,k;
            scanf("%lld %lld %lld",&u,&v,&k);
            modify_path(u,v,k);
        } else if (op==2) {
            int u,k;
            scanf("%lld %lld",&u,&k);
            modify(1,id[u],id[u]+sizes[u]-1,k);
        } else if (op==3) {
            int u,v;
            scanf("%lld %lld",&u,&v);
            printf("%lld\n",query_path(u,v));
        } else {
            int u;
            scanf("%lld",&u);
            printf("%lld\n",query(1,id[u],id[u]+sizes[u]-1));
        }
    }
    return 0;
}