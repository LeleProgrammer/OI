#include <bits/stdc++.h>

#define inf -1000000000
#define int long long

using namespace std;

const int N=100005;
const int M=200005;

int n;
int e[M],ne[M],f[M],h[N],tot;
int id[N],cnt;
int fa[N],son[N],sz[N],top[N],layer[N];
int arr[N],w[N];

struct SegmentTree {
    int l,r;
    int tag;
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
        dfs1(e[i],u,depth+1);
        arr[e[i]]=f[i];
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
        if (e[i]==son[u] || e[i]==fa[u]) continue;
        dfs2(e[i],e[i]);
    }
}

void pushup(int u) {
    tr[u].max=max(tr[u<<1].max,tr[u<<1|1].max);
}

void pushdown(int u) {
    auto &root=tr[u],&left=tr[u<<1],&right=tr[u<<1|1];
    if (root.tag!=inf) {
        left.tag=right.tag=left.max=right.max=root.tag;
        root.tag=inf;
    }
}

void build(int u,int l,int r) {
    tr[u]={l,r,inf,w[l]};
    if (l==r) return;
    int mid=l+r>>1;
    build(u<<1,l,mid);
    build(u<<1|1,mid+1,r);
    pushup(u);
}

void modify(int u,int l,int r,int k) {
    if (tr[u].l>=l && tr[u].r<=r) {
        tr[u].tag=tr[u].max=k;
    } else {
        pushdown(u);
        int mid=tr[u].l+tr[u].r>>1;
        if (l<=mid) modify(u<<1,l,r,k);
        if (r>mid) modify(u<<1|1,l,r,k);
        pushup(u);
    }
}

int query(int u,int l,int r) {
    if (tr[u].l>=l && tr[u].r<=r) return tr[u].max;
    pushdown(u);
    int mid=tr[u].l+tr[u].r>>1;
    int res=-1;
    if (l<=mid) res=max(res,query(u<<1,l,r));
    if (r>mid) res=max(res,query(u<<1|1,l,r));
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
    int res=inf;
    while (top[u]!=top[v]) {
        if (layer[top[u]]<layer[top[v]]) swap(u,v);
        res=max(res,query(1,id[top[u]],id[u]));
        u=fa[top[u]];
    }
    if (layer[u]<layer[v]) swap(u,v);
    if (u!=v) res=max(res,query(1,id[v]+1,id[u]));
    return res;
}

signed main() {
    memset(h,-1,sizeof(h));
    scanf("%lld",&n);
    for (int i=1;i<=n-1;++i) {
        int a,b,c;
        scanf("%lld %lld %lld",&a,&b,&c);
        add(a,b,c);
        add(b,a,c);
    }
    dfs1(1,0,1);
    dfs2(1,1);
    build(1,1,cnt);
    while (true) {
        char op[7];
        scanf("%s",op);
        if (!strcmp(op,"DONE")) break;
        else if (!strcmp(op,"CHANGE")) {
            int a,b;
            scanf("%lld %lld",&a,&b);
            modify_path(e[a*2-2],e[(a*2-2)^1],b);
        } else {
            int a,b;
            scanf("%lld %lld",&a,&b);
            if (a==b) puts("0");
            else printf("%lld\n",query_path(a,b));
        }
    }
    return 0;
}