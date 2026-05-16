#include <bits/stdc++.h>
using namespace std;

const int N=500005;
const int M=1000005;

int n,m;
int e[M],ne[M],h[N],tot;
int id[N],cnt;
int sz[N],fa[N],top[N],layer[N],son[N];

struct SegmentTree {
    int l,r;
    int val;
    int tag;
} tr[N*4];

void add(int a,int b) {
    e[tot]=b,ne[tot]=h[a],h[a]=tot++;
}

void dfs1(int u,int p,int dep) {
    fa[u]=p;
    sz[u]=1;
    layer[u]=dep;
    for (int i=h[u];~i;i=ne[i]) {
        if (e[i]==p) continue;
        dfs1(e[i],u,dep+1);
        sz[u]+=sz[e[i]];
        if (sz[e[i]]>sz[son[u]]) son[u]=e[i];
    }
}

void dfs2(int u,int p) {
    top[u]=p;
    id[u]=++cnt;
    if (!son[u]) return;
    dfs2(son[u],p);
    for (int i=h[u];~i;i=ne[i]) {
        if (e[i]==fa[u] || e[i]==son[u]) continue;
        dfs2(e[i],e[i]);
    }
}

void pushdown(int u) {
    auto &root=tr[u],&left=tr[u<<1],&right=tr[u<<1|1];
    if (~root.tag) {
        left.tag=right.tag=root.tag;
        left.val=right.val=root.tag;
        root.tag=-1;
    }
}

void build(int u,int l,int r) {
    tr[u]={l,r,0,-1};
    if (l==r) return;
    int mid=l+r>>1;
    build(u<<1,l,mid);
    build(u<<1|1,mid+1,r);
}

void modify(int u,int l,int r,int k) {
    if (tr[u].l>=l && tr[u].r<=r) {
        tr[u].val=k;
        tr[u].tag=k;
    } else {
        pushdown(u);
        int mid=tr[u].l+tr[u].r>>1;
        if (l<=mid) modify(u<<1,l,r,k);
        if (r>mid) modify(u<<1|1,l,r,k);
    }
}

int query(int u,int l,int r) {
    if (tr[u].l>=l && tr[u].r<=r) return tr[u].val;
    pushdown(u);
    int mid=tr[u].l+tr[u].r>>1;
    if (l<=mid) return query(u<<1,l,r);
    else return query(u<<1|1,l,r);
}

void modify_path(int u,int v,int k) {
    while (top[u]!=top[v]) {
        if (layer[top[u]]<layer[top[v]]) swap(u,v);
        modify(1,id[top[u]],id[u],k);
        u=fa[top[u]];
    }
    if (layer[u]<layer[v]) swap(u,v);
    modify(1,id[v],id[u],k);
}

int main() {
    memset(h,-1,sizeof(h));
    scanf("%d",&n);
    for (int i=1;i<=n-1;++i) {
        int u,v;
        scanf("%d %d",&u,&v);
        add(u,v);
        add(v,u);
    }
    dfs1(1,0,1);
    dfs2(1,1);
    build(1,1,cnt);
    scanf("%d",&m);
    while (m--) {
        int op,x;
        scanf("%d %d",&op,&x);
        if (op==1) {
            modify(1,id[x],id[x]+sz[x]-1,1);
        } else if (op==2) {
            modify_path(1,x,0);
        } else {
            printf("%d\n",query(1,id[x],id[x]));
        }
    }
    return 0;
}