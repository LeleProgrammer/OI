#include <bits/stdc++.h>
using namespace std;

const int N=200005;
const int M=200005;

int n,m;
int e[M],ne[M],h[N],tot;
int arr[N];
int id[N],w[N],cnt;
int son[N],sz[N],top[N],fa[N],layer[N];

struct SegmentTree {
    int l,r;
    int x;
    int rev;
} tr[N*4];

void add(int a,int b) {
    e[tot]=b,ne[tot]=h[a],h[a]=tot++;
}

void dfs1(int u,int p) {
    sz[u]=1;
    fa[u]=p;
    for (int i=h[u];~i;i=ne[i]) {
        layer[e[i]]=layer[u]+1;
        dfs1(e[i],u);
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
        if (e[i]==son[u]) continue;
        dfs2(e[i],e[i]);
    }
}

void pushup(int u) {
    tr[u].x=tr[u<<1].x+tr[u<<1|1].x;
}

void pushdown(int u) {
    auto &root=tr[u],&left=tr[u<<1],&right=tr[u<<1|1];
    if (root.rev) {
        left.rev^=1;
        right.rev^=1;
        root.rev=0;
        left.x=left.r-left.l+1-left.x;
        right.x=right.r-right.l+1-right.x;
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

void modify(int u,int l,int r) {
    if (tr[u].l>=l && tr[u].r<=r) {
        tr[u].rev^=1;
        tr[u].x=tr[u].r-tr[u].l+1-tr[u].x;
    } else {
        pushdown(u);
        int mid=tr[u].l+tr[u].r>>1;
        if (l<=mid) modify(u<<1,l,r);
        if (r>mid) modify(u<<1|1,l,r);
        pushup(u);
    }
}

int query(int u,int l,int r) {
    if (tr[u].l>=l && tr[u].r<=r) return tr[u].x;
    pushdown(u);
    int mid=tr[u].l+tr[u].r>>1;
    int ans=0;
    if (l<=mid) ans+=query(u<<1,l,r);
    if (r>mid) ans+=query(u<<1|1,l,r);
    return ans;
}

void modify_tree(int x) {
    modify(1,id[x],id[x]+sz[x]-1);
}

int query_tree(int x) {
    return query(1,id[x],id[x]+sz[x]-1);
}

int main() {
    memset(h,-1,sizeof(h));
    scanf("%d",&n);
    for (int i=1;i<=n-1;++i) {
        int v;
        scanf("%d",&v);
        add(v,i+1);
    }
    for (int i=1;i<=n;++i) {
        scanf("%d",&arr[i]);
    }
    dfs1(1,0);
    dfs2(1,0);
    build(1,1,n);
    scanf("%d",&m);
    while (m--) {
        char op[4];
        scanf("%s",op);
        if (!strcmp(op,"get")) {
            int x;
            scanf("%d",&x);
            printf("%d\n",query_tree(x));
        } else {
            int x;
            scanf("%d",&x);
            modify_tree(x);
        }
    }
    return 0;
}