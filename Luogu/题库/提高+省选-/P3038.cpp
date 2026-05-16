#include <bits/stdc++.h>
using namespace std;

const int N=100005;
const int M=200005;

int n,m;
int e[M],ne[M],h[N],tot;
int id[N],cnt;
int son[N],fa[N],layer[N],sz[N],top[N];

struct SegmentTree {
    int l,r;
    int add,sum;
} tr[N*4];

void add(int a,int b) {
    e[tot]=b,ne[tot]=h[a],h[a]=tot++;
}

void dfs1(int u,int p,int depth) {
    fa[u]=p;
    layer[u]=depth;
    sz[u]=1;
    for (int i=h[u];~i;i=ne[i]) {
        if (e[i]==p) continue;
        dfs1(e[i],u,depth+1);
        sz[u]+=sz[e[i]];
        if (sz[e[i]]>sz[son[u]]) son[u]=e[i];
    }
}

void dfs2(int u,int p) {
    id[u]=++cnt;
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
    if (root.add) {
        left.add+=root.add;
        right.add+=root.add;
        left.sum+=(left.r-left.l+1)*root.add;
        right.sum+=(right.r-right.l+1)*root.add;
        root.add=0;
    }
}

void build(int u,int l,int r) {
    tr[u]={l,r,0,0};
    if (l==r) return;
    int mid=l+r>>1;
    build(u<<1,l,mid);
    build(u<<1|1,mid+1,r);
    pushup(u);
}

void modify(int u,int l,int r,int k) {
    if (tr[u].l>=l && tr[u].r<=r) {
        tr[u].add+=k;
        tr[u].sum+=(tr[u].r-tr[u].l+1)*k;
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
        if (layer[top[u]]<layer[top[v]]) swap(u,v);
        modify(1,id[top[u]],id[u],k);
        u=fa[top[u]];
    }
    if (layer[u]<layer[v]) swap(u,v);
    if (u!=v) modify(1,id[v]+1,id[u],k);
}

int query_path(int u,int v) {
    int res=0;
    while (top[u]!=top[v]) {
        if (layer[top[u]]<layer[top[v]]) swap(u,v);
        res+=query(1,id[top[u]],id[u]);
        u=fa[top[u]];
    }
    if (layer[u]<layer[v]) swap(u,v);
    if (u!=v) res+=query(1,id[v]+1,id[u]);
    return res;
}

int main() {
    memset(h,-1,sizeof(h));
    scanf("%d %d",&n,&m);
    for (int i=1;i<=n-1;++i) {
        int u,v;
        scanf("%d %d",&u,&v);
        add(u,v);
        add(v,u);
    }
    dfs1(1,0,1);
    dfs2(1,1);
    build(1,1,cnt);
    while (m--) {
        char op[2];
        int u,v;
        scanf("%s %d %d",op,&u,&v);
        if (*op=='P') {
            modify_path(u,v,1);
        } else {
            printf("%d\n",query_path(u,v));
        }
    }
    return 0;
}