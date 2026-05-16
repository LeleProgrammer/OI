#include <bits/stdc++.h>
using namespace std;

const int N=300005;
const int M=600005;

int n;
int a[N];
int e[M],ne[M],h[N],tot;
int id[N],cnt;
int sz[N],top[N],fa[N],son[N],layer[N];

struct SegmentTree {
    int l,r;
    int sum;
    int tag;
} tr[N*4];

void add(int a,int b) {
    e[tot]=b,ne[tot]=h[a],h[a]=tot++;
}

void dfs1(int u,int p,int dep) {
    fa[u]=p;
    layer[u]=dep;
    sz[u]=1;
    for (int i=h[u];~i;i=ne[i]) {
        if (e[i]==fa[u]) continue;
        dfs1(e[i],u,dep+1);
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
        if (e[i]==son[u] || e[i]==fa[u]) continue;
        dfs2(e[i],e[i]);
    }
}

void pushup(int u) {
    tr[u].sum=tr[u<<1].sum+tr[u<<1|1].sum;
}

void pushdown(int u) {
    auto &root=tr[u],&left=tr[u<<1],&right=tr[u<<1|1];
    if (root.tag) {
        left.tag+=root.tag;
        right.tag+=root.tag;
        left.sum+=(left.r-left.l+1)*root.tag;
        right.sum+=(right.r-right.l+1)*root.tag;
        root.tag=0;
    }
}

void build(int u,int l,int r) {
    tr[u]={l,r,0,0};
    if (l==r) return;
    int mid=l+r>>1;
    build(u<<1,l,mid);
    build(u<<1|1,mid+1,r);
}

void modify(int u,int l,int r,int k) {
    if (tr[u].l>=l && tr[u].r<=r) {
        tr[u].tag+=k;
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
    int ans=0;
    if (l<=mid) ans+=query(u<<1,l,r);
    if (r>mid) ans+=query(u<<1|1,l,r);
    return ans;
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
    for (int i=1;i<=n;++i) {
        scanf("%d",&a[i]);
    }
    for (int i=1;i<=n-1;++i) {
        int u,v;
        scanf("%d %d",&u,&v);
        add(u,v);
        add(v,u);
    }
    dfs1(1,0,1);
    dfs2(1,1);
    build(1,1,n);
    int last=a[1];
    for (int i=1;i<=n;++i) {
        modify_path(last,a[i],1);
        last=a[i];
    }
    for (int i=1;i<=n;++i) {
        printf("%d\n",query(1,id[i],id[i])-1);
    }
    return 0;
}