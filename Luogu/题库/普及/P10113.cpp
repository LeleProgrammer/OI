#include <bits/stdc++.h>
using namespace std;

const int N=100005;
const int M=200005;

int n,Q;
int e[M],ne[M],h[N],tot;
int id[N],cnt;
int layer[N],son[N],sz[N],top[N],fa[N];
int f[N];

void add(int a,int b) {
    e[tot]=b,ne[tot]=h[a],h[a]=tot++;
}

void dfs1(int u,int p) {
    fa[u]=p;
    sz[u]=1;
    for (int i=h[u];~i;i=ne[i]) {
        if (e[i]==p) continue;
        layer[e[i]]=layer[u]+1;
        dfs1(e[i],u);
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

int lca(int u,int v) {
    while (top[u]!=top[v]) {
        if (layer[top[u]]<layer[top[v]]) swap(u,v);
        u=fa[top[u]];
    }
    if (layer[u]<layer[v]) swap(u,v);
    return v;
}

void dfs3(int u) {
    for (int i=h[u];~i;i=ne[i]) {
        if (e[i]==fa[u]) continue;
        f[e[i]]=max(e[i],f[u]);
        dfs3(e[i]);
    }
}

int main() {
    memset(h,-1,sizeof(h));
    scanf("%d",&n);
    for (int i=2;i<=n;++i) {
        int v;
        scanf("%d",&v); v++;
        add(v,i);
    }
    dfs1(1,0);
    dfs2(1,1);
    f[1]=1;
    dfs3(1);
    scanf("%d",&Q);
    while (Q--) {
        int k;
        scanf("%d",&k);
        int val,ans;
        scanf("%d",&val); val++; ans=val;
        for (int i=2;i<=k;++i) {
            scanf("%d",&val); val++;
            ans=lca(ans,val);
        }
        printf("%d\n",f[ans]-1);
    }
    return 0;
}