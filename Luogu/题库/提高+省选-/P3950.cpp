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

const int N=300005;
const int M=600005;

int n,m;
int e[M],ne[M],h[N],tot;
int layer[N],fa[N],top[N],sz[N],son[N],id[N],cnt;
int his[N],idx;

struct Seg {
    int l,r;
    int sum;
} tr[N<<2];

void add(int a,int b) {
    e[tot]=b,ne[tot]=h[a],h[a]=tot++;
}

void dfs1(int u,int p,int dep) {
    sz[u]=1,fa[u]=p,layer[u]=dep;
    _graph(i,u) {
        if (e[i]==fa[u]) continue;
        dfs1(e[i],u,dep+1);
        sz[u]+=sz[e[i]];
        if (sz[e[i]]>sz[son[u]]) son[u]=e[i];
    }
}

void dfs2(int u,int p) {
    id[u]=++cnt,top[u]=p;
    if (!son[u]) return;
    dfs2(son[u],p);
    _graph(i,u) {
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
    build(u<<1,l,mid); build(u<<1|1,mid+1,r);
    pushup(u);
}

void modify(int u,int p,int k) {
    if (tr[u].l==p && tr[u].r==p) tr[u].sum+=k;
    else {
        int mid=tr[u].l+tr[u].r>>1;
        if (p<=mid) modify(u<<1,p,k);
        else modify(u<<1|1,p,k);
        pushup(u);
    }
}

int query(int u,int l,int r) {
    if (tr[u].l>=l && tr[u].r<=r) return tr[u].sum;
    int ans=0;
    int mid=tr[u].l+tr[u].r>>1;
    if (l<=mid) ans+=query(u<<1,l,r);
    if (r>mid) ans+=query(u<<1|1,l,r);
    return ans;
}

int query_path(int u,int v) {
    int ans=0;
    while (top[u]!=top[v]) {
        if (layer[top[v]]>layer[top[u]]) swap(u,v);
        ans+=query(1,id[top[u]],id[u]);
        u=fa[top[u]];
    }
    if (layer[v]>layer[u]) swap(u,v);
    ans+=query(1,id[v],id[u]);
    ans-=query(1,id[v],id[v]);
    return ans;
}

int main() {
    memset(h,-1,sizeof(h));
    scanf("%d %d",&n,&m);
    _rep(i,1,n-1) {
        int a,b;
        scanf("%d %d",&a,&b);
        add(a,b); add(b,a);
    }
    dfs1(1,0,1);
    dfs2(1,1);
    build(1,1,n);
    while (m--) {
        char op[5];
        scanf("%s",op);
        if (*op=='Q') {
            int p,q;
            scanf("%d %d",&p,&q);
            if (query_path(p,q)) puts("No");
            else puts("Yes");
        } else if (*op=='C') {
            int p,q;
            scanf("%d %d",&p,&q);
            if (layer[p]<layer[q]) swap(p,q);
            his[++idx]=p;
            modify(1,id[p],1);
        } else {
            int x;
            scanf("%d",&x);
            modify(1,id[his[x]],-1);
        }
    }
    return 0;
}