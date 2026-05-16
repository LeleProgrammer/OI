#include <bits/stdc++.h>

#define inf 2147483647

using namespace std;

const int N=100005;
const int M=200005;

int n;
int e[M],f[N],ne[M],h[N],tot;
int id[N],cnt;
int sz[N],son[N],fa[N],top[N],layer[N];
int w[N],arr[N];

struct SegmentTree {
    int l,r;
    int mod,add;
    int max;
} tr[N*4];

void add(int a,int b,int c) {
    e[tot]=b,f[tot]=c,ne[tot]=h[a],h[a]=tot++;
}

void dfs1(int u,int p,int depth) {
    fa[u]=p;
    layer[u]=depth;
    sz[u]=1;
    for (int i=h[u];~i;i=ne[i]) {
        if (e[i]==p) continue;
        arr[e[i]]=f[i];
        dfs1(e[i],u,depth+1);
        sz[u]+=sz[e[i]];
        if (sz[e[i]]>sz[son[u]]) son[u]=e[i];
    }
}

void dfs2(int u,int p) {
    id[u]=++cnt;
    top[u]=p;
    w[id[u]]=arr[u];
    if (!son[u]) return;
    dfs2(son[u],p);
    for (int i=h[u];~i;i=ne[i]) {
        if (e[i]==fa[u] || e[i]==son[u]) continue;
        dfs2(e[i],e[i]);
    }
}

void pushup(int u) {
    tr[u].max=max(tr[u<<1].max,tr[u<<1|1].max);
}

void pushdown(int u) {
    auto &root=tr[u],&left=tr[u<<1],&right=tr[u<<1|1];
    if (root.mod!=inf) {
        left.mod=right.mod=root.mod;
        left.max=right.max=root.mod;
        root.mod=inf;
        left.add=right.add=0;
    }
    if (root.add) {
        left.add+=root.add;
        right.add+=root.add;
        left.max+=root.add;
        right.max+=root.add;
        root.add=0;
    }
}

void build(int u,int l,int r) {
    tr[u]={l,r,inf,0,w[l]};
    if (l==r) return;
    int mid=l+r>>1;
    build(u<<1,l,mid);
    build(u<<1|1,mid+1,r);
    pushup(u);
}

void modify_change(int u,int l,int r,int k) {
    if (tr[u].l>=l && tr[u].r<=r) {
        tr[u].add=0;
        tr[u].mod=k;
        tr[u].max=k;
    } else {
        pushdown(u);
        int mid=tr[u].l+tr[u].r>>1;
        if (l<=mid) modify_change(u<<1,l,r,k);
        if (r>mid) modify_change(u<<1|1,l,r,k);
        pushup(u);
    }
}

void modify_add(int u,int l,int r,int k) {
    if (tr[u].l>=l && tr[u].r<=r) {
        tr[u].add+=k;
        tr[u].max+=k;
    } else {
        pushdown(u);
        int mid=tr[u].l+tr[u].r>>1;
        if (l<=mid) modify_add(u<<1,l,r,k);
        if (r>mid) modify_add(u<<1|1,l,r,k);
        pushup(u);
    }
}

int query_max(int u,int l,int r) {
    if (tr[u].l>=l && tr[u].r<=r) return tr[u].max;
    pushdown(u);
    int mid=tr[u].l+tr[u].r>>1;
    int res=-inf;
    if (l<=mid) res=max(res,query_max(u<<1,l,r));
    if (r>mid) res=max(res,query_max(u<<1|1,l,r));
    return res;
}

void modify_path_change(int u,int v,int k) {
    while (top[u]!=top[v]) {
        if (layer[top[u]]<layer[top[v]]) swap(u,v);
        modify_change(1,id[top[u]],id[u],k);
        u=fa[top[u]];
    }
    if (layer[u]<layer[v]) swap(u,v);
    if (u!=v) modify_change(1,id[v]+1,id[u],k);
}

void modify_path_add(int u,int v,int k) {
    while (top[u]!=top[v]) {
        if (layer[top[u]]<layer[top[v]]) swap(u,v);
        modify_add(1,id[top[u]],id[u],k);
        u=fa[top[u]];
    }
    if (layer[u]<layer[v]) swap(u,v);
    if (u!=v) modify_add(1,id[v]+1,id[u],k);
}

int query_path_max(int u,int v) {
    int ans=-inf;
    while (top[u]!=top[v]) {
        if (layer[top[u]]<layer[top[v]]) swap(u,v);
        ans=max(ans,query_max(1,id[top[u]],id[u]));
        u=fa[top[u]];
    }
    if (layer[u]<layer[v]) swap(u,v);
    if (u!=v) ans=max(ans,query_max(1,id[v]+1,id[u]));
    return ans;
}

int main() {
    memset(h,-1,sizeof(h));
    scanf("%d",&n);
    for (int i=1;i<=n-1;++i) {
        int u,v,w;
        scanf("%d %d %d",&u,&v,&w);
        add(u,v,w);
        add(v,u,w);
    }
    dfs1(1,0,1);
    dfs2(1,1);
    build(1,1,cnt);
    while (true) {
        char op[15];
        scanf("%s",op);
        if (!strcmp(op,"Stop")) break;
        else if (!strcmp(op,"Change")) {
            int k,w;
            scanf("%d %d",&k,&w);
            modify_path_change(e[k*2-2],e[(k*2-2)^1],w);
        } else if (!strcmp(op,"Cover")) {
            int u,v,w;
            scanf("%d %d %d",&u,&v,&w);
            modify_path_change(u,v,w);
        } else if (!strcmp(op,"Add")) {
            int u,v,w;
            scanf("%d %d %d",&u,&v,&w);
            modify_path_add(u,v,w);
        } else {
            int u,v;
            scanf("%d %d",&u,&v);
            printf("%d\n",query_path_max(u,v));
        }
    }
    return 0;
}