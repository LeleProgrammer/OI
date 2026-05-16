#include <bits/stdc++.h>

#define inf 9000000000000000000LL
#define int long long

using namespace std;

const int N=400005;
const int M=800005;

int n,m;
int e[M],ne[M],h[N],tot;
int id[N],cnt;
int son[N],sz[N],top[N],fa[N],layer[N];
int arr[N],w[N],f[M];

struct SegmentTree {
    int l,r;
    int mod;
    int rev;
    int max,min,sum;
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
        sz[u]+=sz[e[i]];
        arr[e[i]]=f[i];
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
    tr[u].sum=tr[u<<1].sum+tr[u<<1|1].sum;
    tr[u].min=min(tr[u<<1].min,tr[u<<1|1].min);
}

void pushdown(int u) {
    auto &root=tr[u],&left=tr[u<<1],&right=tr[u<<1|1];
    if (root.mod!=inf) {
        left.mod=right.mod=root.mod;
        left.max=left.min=right.max=right.min=root.mod;
        left.rev=right.rev=root.rev=0;
        left.sum=(left.r-left.l+1)*root.mod;
        right.sum=(right.r-right.l+1)*root.mod;
        root.mod=inf;
    }
    if (root.rev) {
        left.rev^=1;
        right.rev^=1;
        root.rev=0;
        int lmax,lmin,rmax,rmin;
        lmax=left.max;
        lmin=left.min;
        rmax=right.max;
        rmin=right.min;
        left.max=-lmin;
        left.min=-lmax;
        right.max=-rmin;
        right.min=-rmax;
        left.sum*=-1;
        right.sum*=-1;
    }
}

void build(int u,int l,int r) {
    tr[u]={l,r,inf,0,w[l],w[l],w[l]};
    if (l==r) return;
    int mid=l+r>>1;
    build(u<<1,l,mid);
    build(u<<1|1,mid+1,r);
    pushup(u);
}

void modify_change(int u,int l,int r,int k) {
    if (tr[u].l>=l && tr[u].r<=r) {
        pushdown(u);
        tr[u].mod=k;
        tr[u].max=tr[u].min=k;
        tr[u].sum=(tr[u].r-tr[u].l+1)*k;
        tr[u].rev=0;
    } else {
        pushdown(u);
        int mid=tr[u].l+tr[u].r>>1;
        if (l<=mid) modify_change(u<<1,l,r,k);
        if (r>mid) modify_change(u<<1|1,l,r,k);
        pushup(u);
    }
}

void modify_rev(int u,int l,int r) {
    if (tr[u].l>=l && tr[u].r<=r) {
        pushdown(u);
        tr[u].rev^=1;
        int maxx,minn;
        maxx=tr[u].max;
        minn=tr[u].min;
        tr[u].max=-minn;
        tr[u].min=-maxx;
        tr[u].sum*=-1;
    } else {
        pushdown(u);
        int mid=tr[u].l+tr[u].r>>1;
        if (l<=mid) modify_rev(u<<1,l,r);
        if (r>mid) modify_rev(u<<1|1,l,r);
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

int query_min(int u,int l,int r) {
    if (tr[u].l>=l && tr[u].r<=r) return tr[u].min;
    pushdown(u);
    int mid=tr[u].l+tr[u].r>>1;
    int res=inf;
    if (l<=mid) res=min(res,query_min(u<<1,l,r));
    if (r>mid) res=min(res,query_min(u<<1|1,l,r));
    return res;
}

void path_modify_change(int u,int v,int k) {
    while (top[u]!=top[v]) {
        if (layer[top[u]]<layer[top[v]]) swap(u,v);
        modify_change(1,id[top[u]],id[u],k);
        u=fa[top[u]];
    }
    if (layer[u]<layer[v]) swap(u,v);
    if (u!=v) modify_change(1,id[v]+1,id[u],k);
}

void path_modify_rev(int u,int v) {
    while (top[u]!=top[v]) {
        if (layer[top[u]]<layer[top[v]]) swap(u,v);
        modify_rev(1,id[top[u]],id[u]);
        u=fa[top[u]];
    }
    if (layer[u]<layer[v]) swap(u,v);
    if (u!=v) modify_rev(1,id[v]+1,id[u]);
}

int path_query_sum(int u,int v) {
    int ans=0;
    while (top[u]!=top[v]) {
        if (layer[top[u]]<layer[top[v]]) swap(u,v);
        ans+=query_sum(1,id[top[u]],id[u]);
        u=fa[top[u]];
    }
    if (layer[u]<layer[v]) swap(u,v);
    if (u!=v) ans+=query_sum(1,id[v]+1,id[u]);
    return ans;
}

int path_query_max(int u,int v) {
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

int path_query_min(int u,int v) {
    int ans=inf;
    while (top[u]!=top[v]) {
        if (layer[top[u]]<layer[top[v]]) swap(u,v);
        ans=min(ans,query_min(1,id[top[u]],id[u]));
        u=fa[top[u]];
    }
    if (layer[u]<layer[v]) swap(u,v);
    if (u!=v) ans=min(ans,query_min(1,id[v]+1,id[u]));
    return ans;
}

signed main() {
    memset(h,-1,sizeof(h));
    scanf("%lld",&n);
    for (int i=1;i<=n-1;++i) {
        int u,v,w;
        scanf("%lld %lld %lld",&u,&v,&w); u++,v++;
        add(u,v,w);
        add(v,u,w);
    }
    dfs1(1,0,1);
    dfs2(1,1);
    build(1,1,cnt);
    scanf("%lld",&m);
    while (m--) {
        char op[4];
        scanf("%s",op);
        if (!strcmp(op,"C")) {
            int i,w;
            scanf("%lld %lld",&i,&w);
            path_modify_change(e[i*2-2],e[(i*2-2)^1],w);
        } else if (!strcmp(op,"N")) {
            int u,v;
            scanf("%lld %lld",&u,&v); u++,v++;
            path_modify_rev(u,v);
        } else if (!strcmp(op,"SUM")) {
            int u,v;
            scanf("%lld %lld",&u,&v); u++,v++;
            printf("%lld\n",path_query_sum(u,v));
        } else if (!strcmp(op,"MAX")) {
            int u,v;
            scanf("%lld %lld",&u,&v); u++,v++;
            printf("%lld\n",path_query_max(u,v));
        } else {
            int u,v;
            scanf("%lld %lld",&u,&v); u++,v++;
            printf("%lld\n",path_query_min(u,v));
        }
    }
    return 0;
}