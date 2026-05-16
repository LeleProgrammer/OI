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

const int N=100005;
const int M=200005;

int n,m;
int arr[N];
int e[M],ne[M],h[N],tot;
int w[N],id[N],son[N],top[N],dep[N],sz[N],fa[N],cnt;

struct Seg {
    int l,r;
    int ls,rs;
    int sum;
} tr[N*30];

int root[N],idx;

void add(int a,int b) {
    e[tot]=b,ne[tot]=h[a],h[a]=tot++;
}

void dfs1(int u,int p,int d) {
    dep[u]=d,fa[u]=p,sz[u]=1;
    _graph(i,u) {
        if (e[i]==p) continue;
        dfs1(e[i],u,d+1);
        sz[u]+=sz[e[i]];
        if (sz[e[i]]>sz[son[u]]) son[u]=e[i];
    }
}

void dfs2(int u,int p) {
    top[u]=p,id[u]=++cnt,w[id[u]]=arr[u];
    if (!son[u]) return;
    dfs2(son[u],p);
    _graph(i,u) {
        if (e[i]==fa[u] || e[i]==son[u]) continue;
        dfs2(e[i],e[i]);
    }
}

void pushup(int u) {
    tr[u].sum=tr[tr[u].ls].sum+tr[tr[u].rs].sum;
}

void build(int u,int pos) {
    if (tr[u].l==pos && tr[u].r==pos) {
        tr[u].sum=1;
        return;
    }
    int mid=tr[u].l+tr[u].r>>1;
    if (pos<=mid) {
        if (!tr[u].ls) tr[u].ls=++idx,tr[idx]={tr[u].l,mid,0,0,0};
        build(tr[u].ls,pos);
    } else {
        if (!tr[u].rs) tr[u].rs=++idx,tr[idx]={mid+1,tr[u].r,0,0,0};
        build(tr[u].rs,pos);
    }
    pushup(u);
}

int query(int u,int l,int r) {
    if (tr[u].l>=l && tr[u].r<=r) return tr[u].sum;
    int mid=tr[u].l+tr[u].r>>1;
    int ans=0;
    if (l<=mid && tr[u].ls) ans+=query(tr[u].ls,l,r);
    if (r>mid && tr[u].rs) ans+=query(tr[u].rs,l,r);
    return ans;
}

int query_path(int u,int v,int c) {
    int ans=0;
    while (top[u]!=top[v]) {
        if (dep[top[u]]<dep[top[v]]) swap(u,v);
        ans+=query(root[c],id[top[u]],id[u]);
        u=fa[top[u]];
    }
    if (dep[u]<dep[v]) swap(u,v);
    ans+=query(root[c],id[v],id[u]);
    return ans;
}

int main() {
    while (scanf("%d %d",&n,&m)!=EOF) {
        memset(h,-1,sizeof(h));
        cnt=idx=tot=0;
        _rep(i,1,n) scanf("%d",&arr[i]);
        _rep(i,1,n-1) {
            int a,b;
            scanf("%d %d",&a,&b);
            add(a,b); add(b,a);
        }
        _rep(i,0,n) root[i]=++idx,tr[idx]={1,n,0,0,0};
        dfs1(1,0,1),dfs2(1,1);
        _rep(i,1,n) build(root[arr[i]],id[i]);
        while (m--) {
            int a,b,c;
            scanf("%d %d %d",&a,&b,&c);
            int k=query_path(a,b,c);
            if (k) puts("Find");
            else puts("NotFind");
        }
        putchar(10);
        _rep(i,1,n) root[i]=w[i]=id[i]=sz[i]=son[i]=fa[i]=top[i]=dep[i]=0;
        _rep(i,1,idx) tr[i]={0,0,0,0,0};
    }
    return 0;
}