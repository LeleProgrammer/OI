#include <bits/stdc++.h>
using namespace std;

const int N=100005;
const int M=100005;

int n,q;
int e[M],ne[M],h[N],tot;
int id[N],cnt;
int layer[N],fa[N],top[N],son[N],sz[N];

struct SegmentTree {
    int l,r;
    int tag,sum;
} tr[N*4];

void add(int a,int b) {
    e[tot]=b,ne[tot]=h[a],h[a]=tot++;
}

void dfs1(int u,int dep) {
    layer[u]=dep;
    sz[u]=1;
    for (int i=h[u];~i;i=ne[i]) {
        dfs1(e[i],dep+1);
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
    if (~root.tag) {
        left.tag=root.tag;
        right.tag=root.tag;
        left.sum=(left.r-left.l+1)*root.tag;
        right.sum=(right.r-right.l+1)*root.tag;
        root.tag=-1;
    }
}

void build(int u,int l,int r) {
    tr[u]={l,r,-1,0};
    if (l==r) return;
    int mid=l+r>>1;
    build(u<<1,l,mid);
    build(u<<1|1,mid+1,r);
    pushup(u);
}

void modify(int u,int l,int r,int k) {
    if (tr[u].l>=l && tr[u].r<=r) {
        tr[u].tag=k;
        tr[u].sum=(tr[u].r-tr[u].l+1)*k;
    } else {
        pushdown(u);
        int mid=tr[u].l+tr[u].r>>1;
        if (l<=mid) modify(u<<1,l,r,k);
        if (r>mid) modify(u<<1|1,l,r,k);
        pushup(u);
    }
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
    for (int i=2;i<=n;++i) {
        int k;
        scanf("%d",&k);
        k++;
        fa[i]=k;
        add(k,i);
    }
    dfs1(1,1);
    dfs2(1,1);
    build(1,1,cnt);
    scanf("%d",&q);
    while (q--) {
        char op[55];
        int x;
        scanf("%s %d",op,&x);
        x++;
        if (!strcmp(op,"install")) {
            int past=tr[1].sum;
            modify_path(1,x,1);
            int now=tr[1].sum;
            printf("%d\n",abs(past-now));
        } else {
            int past=tr[1].sum;
            modify(1,id[x],id[x]+sz[x]-1,0);
            int now=tr[1].sum;
            printf("%d\n",abs(past-now));
        }
    }
    return 0;
}