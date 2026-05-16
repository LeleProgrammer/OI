#include <bits/stdc++.h>
using namespace std;

const int N=100005;
const int M=200005;

typedef pair<int,int> pii;

int n,m;
int e[M],ne[M],h[N],tot;
int id[N],cnt;
int sz[N],top[N],son[N],layer[N],fa[N];
vector<pii> edges;

struct SegmentTree {
    int l,r;
    int sum; // black:0 white:1
} tr[N*4];

void add(int a,int b) {
    e[tot]=b,ne[tot]=h[a],h[a]=tot++;
}

void dfs1(int u,int p,int dep) {
    fa[u]=p;
    sz[u]=1;
    layer[u]=dep;
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

void build(int u,int l,int r) {
    tr[u]={l,r,0};
    if (l==r) return;
    int mid=l+r>>1;
    build(u<<1,l,mid);
    build(u<<1|1,mid+1,r);
    pushup(u);
}

void modify(int u,int p,int k) {
    if (tr[u].l==p && tr[u].r==p) {
        tr[u].sum=k;
    } else {
        int mid=tr[u].l+tr[u].r>>1;
        if (p<=mid) modify(u<<1,p,k);
        else modify(u<<1|1,p,k);
        pushup(u);
    }
}

int query(int u,int l,int r) {
    if (tr[u].l>=l && tr[u].r<=r) return tr[u].sum;
    int mid=tr[u].l+tr[u].r>>1;
    int ans=0;
    if (l<=mid) ans+=query(u<<1,l,r);
    if (r>mid) ans+=query(u<<1|1,l,r);
    return ans;
}

pii query_path(int u,int v) {
    int ans=0;
    int len=0;
    while (top[u]!=top[v]) {
        if (layer[top[u]]<layer[top[v]]) swap(u,v);
        len+=id[u]-id[top[u]]+1;
        ans+=query(1,id[top[u]],id[u]);
        u=fa[top[u]];
    }
    if (u!=v) {
        if (layer[u]<layer[v]) swap(u,v);
        ans=ans+query(1,id[v],id[u])-query(1,id[v],id[v]);
        len+=id[u]-id[v];
    }
    return {ans,len};
}

int main() {
    memset(h,-1,sizeof(h));
    edges.push_back({0,0});
    scanf("%d",&n);
    for (int i=1;i<=n-1;++i) {
        int a,b;
        scanf("%d %d",&a,&b);
        add(a,b);
        add(b,a);
        edges.push_back({a,b});
    }
    dfs1(1,0,1);
    dfs2(1,1);
    build(1,1,n);
    scanf("%d",&m);
    while (m--) {
        int op;
        scanf("%d",&op);
        if (op==1) {
            int u;
            scanf("%d",&u);
            int dest;
            if (layer[edges[u].first]<layer[edges[u].second]) dest=edges[u].second;
            else dest=edges[u].first;
            modify(1,id[dest],0);
        } else if (op==2) {
            int u;
            scanf("%d",&u);
            int dest;
            if (layer[edges[u].first]<layer[edges[u].second]) dest=edges[u].second;
            else dest=edges[u].first;
            modify(1,id[dest],1);
        } else {
            int u,v;
            scanf("%d %d",&u,&v);
            auto ans=query_path(u,v);
            if (!ans.first) printf("%d\n",ans.second);
            else puts("-1");
        }
    }
    return 0;
}