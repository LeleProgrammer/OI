#include <bits/stdc++.h>

#define inf 1000000000

using namespace std;

const int N=30005;
const int M=60005;

int n,q;
int arr[N],w[N];
int e[M],ne[M],h[N],tot;
int id[N],cnt;
int son[N],fa[N],layer[N],sz[N],top[N];

struct SegmentTree {
    int l,r;
    int tag,sum,max;
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
    w[id[u]]=arr[u];
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
    tr[u].max=max(tr[u<<1].max,tr[u<<1|1].max);
}

void pushdown(int u) {
    auto &root=tr[u],&left=tr[u<<1],&right=tr[u<<1|1];
    if (root.tag!=inf) {
        left.tag=right.tag=root.tag;
        left.sum=(left.r-left.l+1)*root.tag;
        right.sum=(right.r-right.l+1)*root.tag;
        left.max=root.tag;
        right.max=root.tag;
        root.tag=inf;
    }
}

void build(int u,int l,int r) {
    tr[u]={l,r,inf,w[l],w[l]};
    if (l==r) return;
    int mid=l+r>>1;
    build(u<<1,l,mid);
    build(u<<1|1,mid+1,r);
    pushup(u);
}

void modify(int u,int l,int r,int k) {
    if (tr[u].l>=l && tr[u].r<=r) {
        tr[u].tag=k;
        tr[u].max=k;
        tr[u].sum=(tr[u].r-tr[u].l+1)*k;
    } else {
        pushdown(u);
        int mid=tr[u].l+tr[u].r>>1;
        if (l<=mid) modify(u<<1,l,r,k);
        if (r>mid) modify(u<<1|1,l,r,k);
        pushup(u);
    }
}

int query_sum(int u,int l,int r) {
    if (tr[u].l>=l && tr[u].r<=r) return tr[u].sum;
    pushdown(u);
    int mid=tr[u].l+tr[u].r>>1;
    int res=0;
    if (l<=mid) res+=query_sum(u<<1,l,r);
    if (r>mid) res+=query_sum(u<<1|1,l,r);
    return res;
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

void modify_point(int u,int k) {
    modify(1,id[u],id[u],k);
}

int query_max_path(int u,int v) {
    int ans=-inf;
    while (top[u]!=top[v]) {
        if (layer[top[u]]<layer[top[v]]) swap(u,v);
        ans=max(ans,query_max(1,id[top[u]],id[u]));
        u=fa[top[u]];
    }
    if (layer[u]<layer[v]) swap(u,v);
    ans=max(ans,query_max(1,id[v],id[u]));
    return ans;
}

int query_sum_path(int u,int v) {
    int ans=0;
    while (top[u]!=top[v]) {
        if (layer[top[u]]<layer[top[v]]) swap(u,v);
        ans+=query_sum(1,id[top[u]],id[u]);
        u=fa[top[u]];
    }
    if (layer[u]<layer[v]) swap(u,v);
    ans+=query_sum(1,id[v],id[u]);
    return ans;
}

int main() {
    memset(h,-1,sizeof(h));
    scanf("%d",&n);
    for (int i=1;i<=n-1;++i) {
        int a,b;
        scanf("%d %d",&a,&b);
        add(a,b);
        add(b,a);
    }
    for (int i=1;i<=n;++i) {
        scanf("%d",&arr[i]);
    }
    dfs1(1,0,1);
    dfs2(1,1);
    build(1,1,cnt);
    scanf("%d",&q);
    while (q--) {
        char op[25];
        scanf("%s",op);
        if (!strcmp(op,"CHANGE")) {
            int u,t;
            scanf("%d %d",&u,&t);
            modify_point(u,t);
        } else if (!strcmp(op,"QMAX")) {
            int u,v;
            scanf("%d %d",&u,&v);
            printf("%d\n",query_max_path(u,v));
        } else {
            int u,v;
            scanf("%d %d",&u,&v);
            printf("%d\n",query_sum_path(u,v));
        }
    }
    return 0;
}