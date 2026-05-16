#include <bits/stdc++.h>
using namespace std;

const int N=100005;
const int M=200005;
const int inf=1e9;

int n,q;
int e[M],ne[M],h[N],tot;
int id[N],top[N],layer[N],fa[N],sz[N],idx;
int flag[N];
int son[N];

struct SegmentTree {
    int l,r;
    int val;
} tr[N*4];

void add(int a,int b) {
    e[tot]=b,ne[tot]=h[a],h[a]=tot++;
}

void dfs1(int u,int p,int dep) {
    fa[u]=p;
    sz[u]=1;
    layer[u]=dep;
    for (int i=h[u];~i;i=ne[i]) {
        if (e[i]==p) continue;
        dfs1(e[i],u,dep+1);
        sz[u]+=sz[e[i]];
        if (sz[e[i]]>sz[son[u]]) son[u]=e[i];
    }
}

void dfs2(int u,int p) {
    id[u]=++idx;
    flag[idx]=u;
    top[u]=p;
    if (!son[u]) return;
    dfs2(son[u],p);
    for (int i=h[u];~i;i=ne[i]) {
        if (e[i]==fa[u] || e[i]==son[u]) continue;
        dfs2(e[i],e[i]);
    }
}

void pushup(int u) {
    tr[u].val=min(tr[u<<1].val,tr[u<<1|1].val);
}

void build(int u,int l,int r) {
    tr[u]={l,r,inf};
    if (l==r) return;
    int mid=l+r>>1;
    build(u<<1,l,mid);
    build(u<<1|1,mid+1,r);
    pushup(u);
}

void modify(int u,int k) {
    if (tr[u].l==k && tr[u].r==k) {
        if (tr[u].val==k) tr[u].val=inf;
        else tr[u].val=k;
    } else {
        int mid=tr[u].l+tr[u].r>>1;
        if (k<=mid) modify(u<<1,k);
        else modify(u<<1|1,k);
        pushup(u);
    }
}

int query(int u,int l,int r) {
    if (tr[u].l>=l && tr[u].r<=r) return tr[u].val;
    int mid=tr[u].l+tr[u].r>>1;
    int ans=inf;
    if (l<=mid) ans=min(ans,query(u<<1,l,r));
    if (r>mid) ans=min(ans,query(u<<1|1,l,r));
    return ans;
}

int query_path(int u) {
    int ans=inf;
    while (u) {
        int t=query(1,id[top[u]],id[u]);
        ans=min(ans,t);
        u=fa[top[u]];
    }
    return ans;
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
        int op,x;
        scanf("%d %d",&op,&x);
        if (op==0) {
            modify(1,id[x]);
        } else {
            int ans=query_path(x);
            if (ans==inf) ans=-1;
            else ans=flag[ans];
            printf("%d\n",ans);
        }
    }
    return 0;
}