#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define FRR(file) freopen(file,"r",stdin)
#define FRW(file) freopen(file,"w",stdout)
#define TIMESTAMP cerr<<fixed<<setprecision(3)<<clock()*1.0/CLOCKS_PER_SEC<<"s"<<endl;
#define _rep(i,a,b) for (int i=(a);i<=(b);++i)
#define _reps(i,a,b,c) for (int i=(a);i<=(b);c)
#define _rrep(i,a,b) for (int i=(a);i>=(b);--i)
#define _rreps(i,a,b,c) for (int i=(a);i>=(b);c)
#define _iter(i,a) for (auto i=a.begin();i!=a.end();++i)
#define _graph(i,u) for (int i=h[u];~i;i=ne[i])
#define rint register int
#define LL long long
typedef pair<int,int> pii;

const int N=1005;
const int M=2005;

int n,k;
int arr[N];
int son[N],layer[N],top[N],fa[N],sz[N];
int id[N],w[N],cnt;
int e[M],ne[M],h[N],tot;

struct Seg {
    int l,r;
    int sz,sum;
} tr[N<<2];

void add(int a,int b) {
    e[tot]=b,ne[tot]=h[a],h[a]=tot++;
}

void dfs1(int u,int p,int dep) {
    layer[u]=dep,sz[u]=1,fa[u]=p;
    _graph(i,u) {
        if (e[i]==fa[u]) continue;
        dfs1(e[i],u,dep+1);
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
    _graph(i,u) {
        if (e[i]==fa[u] || e[i]==son[u]) continue;
        dfs2(e[i],e[i]);
    }
}

void pushup(int u) {
    tr[u].sz=tr[u<<1].sz+tr[u<<1|1].sz;
    tr[u].sum=tr[u<<1].sum+tr[u<<1|1].sum;
}

void build(int u,int l,int r) {
    tr[u]={l,r,1,w[l]};
    if (l==r) return;
    int mid=l+r>>1;
    build(u<<1,l,mid); build(u<<1|1,mid+1,r);
    pushup(u);
}

pii operator + (pii a,pii b) {
    return {a.first+b.first,a.second+b.second};
}

pii query(int u,int l,int r) {
    if (tr[u].l>=l && tr[u].r<=r) return {tr[u].sz,tr[u].sum};
    int mid=tr[u].l+tr[u].r>>1;
    pii ans={0,0};
    if (l<=mid) ans=ans+query(u<<1,l,r);
    if (r>mid) ans=ans+query(u<<1|1,l,r);
    return ans;
}

pii query_path(int u,int v) {
    pii ans={0,0};
    while (top[u]!=top[v]) {
        if (layer[top[u]]<layer[top[v]]) swap(u,v);
        ans=ans+query(1,id[top[u]],id[u]);
        u=fa[top[u]];
    }
    if (layer[u]<layer[v]) swap(u,v);
    ans=ans+query(1,id[v],id[u]);
    return ans;
}

int main() {
    memset(h,-1,sizeof(h));
    scanf("%d %d",&n,&k);
    _rep(i,1,n) scanf("%d",&arr[i]);
    _rep(i,1,n-1) {
        int a,b;
        scanf("%d %d",&a,&b);
        add(a,b); add(b,a);
    }
    dfs1(1,0,1);
    dfs2(1,1);
    build(1,1,n);
    int ans=0;
    _rep(i,1,n) _rep(j,1,n) {
        auto t=query_path(i,j);
        // printf("%d to %d, sum %d, tot %d\n",i,j,t.second,t.first);
        if (t.second>k) continue;
        ans=max(ans,t.first);
    }
    printf("%d",ans);
    return 0;
}