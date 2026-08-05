#include <bits/stdc++.h>
using namespace std;

const int N=500005;
const int M=1000005;

int n,m;
int e[M],ne[M],h[N],tot;
int a[N];
int id[N],w[N],cnt;
int son[N],fa[N],top[N],sz[N],layer[N];

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
    top[u]=p;
    id[u]=++cnt;
    w[id[u]]=a[u];
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
    if (root.tag) {
        left.tag+=root.tag;
        right.tag+=root.tag;
        left.sum+=(left.r-left.l+1)*root.tag;
        right.sum+=(right.r-right.l+1)*root.tag;
        root.tag=0;
    }
}

void build(int u,int l,int r) {
    tr[u]={l,r,w[l],0};
    if (l==r) return;
    int mid=l+r>>1;
    build(u<<1,l,mid);
    build(u<<1|1,mid+1,r);
    pushup(u);
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

int query(int u,int p,int k) {
    if (tr[u].l==p && tr[u].r==p) return tr[u].sum;
    pushdown(u);
    int mid=tr[u].l+tr[u].r>>1;
    if (p<=mid) return query(u<<1,p,k);
    else return query(u<<1|1,p,k);
}

int main() {
    memset(h,-1,sizeof(h));
    scanf("%d %d",&n,&m);
    scanf("%d",&a[1]);
    for (int i=2;i<=n;++i) {
        int u;
        scanf("%d %d",&a[i],&u);
        add(i,u);
        add(u,i);
    }
    dfs1(1,0,1);
    dfs2(1,1);
    build(1,1,n);
    while (m--) {
        char op[2];
        scanf("%s",op);
        if (*op=='p') {
            int a,x;
            scanf("%d %d",&a,&x);
            modify(1,id[a],id[a]+sz[a]-1,x);
            modify(1,id[a],id[a],-x);
        } else {
            int a;
            scanf("%d",&a);
            printf("%d\n",query(1,id[a],id[a]));
        }
    }
    return 0;
}