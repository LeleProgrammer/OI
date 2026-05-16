#include <bits/stdc++.h>
using namespace std;

const int N=100005;
const int M=200005;

int n,q;
int e[M],ne[M],h[N],tot;
int id[N],cnt;
int fa[N],top[N],sz[N],son[N],layer[N];
int k[N];

struct SegmentTree {
    int l,r;
    int v;
} tr[N*4];

void add(int a,int b) {
    e[tot]=b,ne[tot]=h[a],h[a]=tot++;
}

void dfs1(int u,int p,int depth) {
    fa[u]=p;
    layer[u]=depth;
    sz[u]=1;
    for (int i=h[u];~i;i=ne[i]) {
        if (e[i]==fa[u]) continue;
        dfs1(e[i],u,depth+1);
        sz[u]+=sz[e[i]];
        if (sz[e[i]]>sz[son[u]]) son[u]=e[i];
    }
}

void dfs2(int u,int p) {
    top[u]=p;
    id[u]=++cnt;
    k[id[u]]=u;
    if (!son[u]) return;
    dfs2(son[u],p);
    for (int i=h[u];~i;i=ne[i]) {
        if (e[i]==son[u] || e[i]==fa[u]) continue;
        dfs2(e[i],e[i]);
    }
}

void pushup(int u) {
    tr[u].v=max(tr[u<<1].v,tr[u<<1|1].v);
}

void build(int u,int l,int r) {
    tr[u]={l,r,0};
    if (l==id[1] && r==id[1]) tr[u].v=id[1];
    if (l==r) return;
    int mid=l+r>>1;
    build(u<<1,l,mid);
    build(u<<1|1,mid+1,r);
    pushup(u);
}

void modify(int u,int l,int r,int k) {
    if (tr[u].l>=l && tr[u].r<=r) {
        tr[u].v=max(tr[u].v,k);
    } else {
        int mid=tr[u].l+tr[u].r>>1;
        if (l<=mid) modify(u<<1,l,r,k);
        if (r>mid) modify(u<<1|1,l,r,k);
        pushup(u);
    }
}

int query(int u,int l,int r) {
    if (tr[u].l>=l && tr[u].r<=r) return tr[u].v;
    int mid=tr[u].l+tr[u].r>>1;
    int res=0;
    if (l<=mid) res=max(res,query(u<<1,l,r));
    if (r>mid) res=max(res,query(u<<1|1,l,r));
    return res;
}

int query_path(int u) {
    while (u) {
        int ret=query(1,id[top[u]],id[u]);
        if (ret && k[ret]) return k[ret];
        u=fa[top[u]];
    }
    return 0;
}

int main() {
    memset(h,-1,sizeof(h));
    scanf("%d %d",&n,&q);
    for (int i=1;i<=n-1;++i) {
        int a,b;
        scanf("%d %d",&a,&b);
        add(a,b);
        add(b,a);
    }
    dfs1(1,0,1);
    dfs2(1,1);
    build(1,1,n);
    while (q--) {
        char op[2];
        int a;
        scanf("%s %d",op,&a);
        if (*op=='Q') {
            printf("%d\n",query_path(a));
        } else {
            modify(1,id[a],id[a],id[a]);
        }
    }
    return 0;
}