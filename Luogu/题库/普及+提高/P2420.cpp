#include <bits/stdc++.h>
using namespace std;

const int N=100005;
const int M=200005;

int n,m;
int e[M],t[M],ne[M],h[N],tot;
int arr[N];
int id[N],w[N],cnt;
int sz[N],top[N],fa[N],layer[N],son[N];

struct SegmentTree {
    int l,r;
    int sum;
} tr[N*4];

void add(int a,int b,int c) {
    e[tot]=b,t[tot]=c,ne[tot]=h[a],h[a]=tot++;
}

void dfs1(int u,int p,int dep) {
    fa[u]=p;
    layer[u]=dep;
    sz[u]=1;
    for (int i=h[u];~i;i=ne[i]) {
        if (e[i]==fa[u]) continue;
        arr[e[i]]=t[i];
        dfs1(e[i],u,dep+1);
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
    tr[u].sum=tr[u<<1].sum^tr[u<<1|1].sum;
}

void build(int u,int l,int r) {
    tr[u]={l,r,w[l]};
    if (l==r) return;
    int mid=l+r>>1;
    build(u<<1,l,mid);
    build(u<<1|1,mid+1,r);
    pushup(u);
}

int query(int u,int l,int r) {
    if (tr[u].l>=l && tr[u].r<=r) return tr[u].sum;
    int mid=tr[u].l+tr[u].r>>1;
    int ans=0;
    if (l<=mid) ans^=query(u<<1,l,r);
    if (r>mid) ans^=query(u<<1|1,l,r);
    return ans;
}

int query_path(int u,int v) {
    int ans=0;
    while (top[u]!=top[v]) {
        if (layer[top[u]]<layer[top[v]]) swap(u,v);
        ans^=query(1,id[top[u]],id[u]);
        u=fa[top[u]];
    }
    if (u!=v) {
        if (layer[u]<layer[v]) swap(u,v);
        ans=ans^query(1,id[v],id[u])^query(1,id[v],id[v]);
    }
    return ans;
}

int main() {
    memset(h,-1,sizeof(h));
    scanf("%d",&n);
    for (int i=1;i<=n-1;++i) {
        int x,y,z;
        scanf("%d %d %d",&x,&y,&z);
        add(x,y,z);
        add(y,x,z);
    }
    dfs1(1,0,1);
    dfs2(1,1);
    build(1,1,n);
    scanf("%d",&m);
    while (m--) {
        int u,v;
        scanf("%d %d",&u,&v);
        printf("%d\n",query_path(u,v));
    }
    return 0;
}