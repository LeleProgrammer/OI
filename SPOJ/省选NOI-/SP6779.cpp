#include <bits/stdc++.h>
using namespace std;

#define int long long

#define endl '\n'
#define FRR(file) freopen(file,"r",stdin)
#define FRW(file) freopen(file,"w",stdout)
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
const int inf=1e18;

int n,m;
int arr[N];
int e[M],ne[M],h[N],tot;
int id[N],fa[N],top[N],layer[N],son[N],sz[N],w[N],cnt;

void add(int a,int b) {
    e[tot]=b,ne[tot]=h[a],h[a]=tot++;
}

struct Seg {
    int l,r;
    int lmx,rmx,mmx;
    int sum;
    int tag;
    void init() {
        l=r=lmx=rmx=mmx=sum=0;
        tag=inf;
    }
} tr[N<<2];

void dfs1(int u,int p,int dep) {
    fa[u]=p;
    layer[u]=dep;
    sz[u]=1;
    _graph(i,u) {
        if (e[i]==p) continue;
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

void rev(Seg& u) {
    swap(u.lmx,u.rmx);
}

void pushup(Seg& u,Seg& l,Seg& r) {
    u.lmx=max(l.lmx,l.sum+r.lmx);
    u.rmx=max(r.rmx,r.sum+l.rmx);
    u.mmx=max(max(l.mmx,r.mmx),l.rmx+r.lmx);
    u.sum=l.sum+r.sum;
}

Seg pushup(Seg& l,Seg& r) {
    Seg u;
    u.init();
    pushup(u,l,r);
    return u;
}

void pushup(int u) {
    pushup(tr[u],tr[u<<1],tr[u<<1|1]);
}

void pushdown(int u) {
    auto &root=tr[u],&left=tr[u<<1],&right=tr[u<<1|1];
    if (root.tag!=inf) {
        left.tag=right.tag=root.tag;
        left.sum=(left.r-left.l+1)*root.tag;
        right.sum=(right.r-right.l+1)*root.tag;
        left.lmx=left.rmx=max(root.tag,left.sum);
        left.mmx=max(0LL,left.sum);
        right.lmx=right.rmx=max(root.tag,right.sum);
        right.mmx=max(0LL,right.sum);
        root.tag=inf;
    }
}

void build(int u,int l,int r) {
    tr[u].l=l,tr[u].r=r,tr[u].tag=inf;
    if (l==r) {
        tr[u].sum=w[l];
        tr[u].lmx=tr[u].rmx=max(w[l],tr[u].sum);
        tr[u].mmx=max(0LL,tr[u].sum);
    } else {
        int mid=l+r>>1;
        build(u<<1,l,mid); build(u<<1|1,mid+1,r);
        pushup(u);
    }
}

void modify(int u,int l,int r,int k) {
    if (tr[u].l!=tr[u].r) pushdown(u);
    if (tr[u].l>=l && tr[u].r<=r) {
        tr[u].sum=(tr[u].r-tr[u].l+1)*k;
        tr[u].lmx=tr[u].rmx=max(k,tr[u].sum);
        tr[u].mmx=max(0LL,tr[u].sum);
        tr[u].tag=k;
    } else {
        int mid=tr[u].l+tr[u].r>>1;
        if (l<=mid) modify(u<<1,l,r,k);
        if (r>mid) modify(u<<1|1,l,r,k);
        pushup(u);
    }
}

Seg query(int u,int l,int r) {
    if (tr[u].l!=tr[u].r) pushdown(u);
    if (tr[u].l>=l && tr[u].r<=r) return tr[u];
    int mid=tr[u].l+tr[u].r>>1;
    Seg left,right,ans;
    left.init();
    right.init();
    ans.init();
    if (l<=mid) left=query(u<<1,l,r);
    if (r>mid) right=query(u<<1|1,l,r);
    pushup(ans,left,right);
    return ans;
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

Seg query_path(int u,int v) {
    Seg ansu,ansv,ans;
    ansu.init();
    ansv.init();
    ans.init();
    while (top[u]!=top[v]) {
        if (layer[top[u]]<layer[top[v]]) {
            Seg s=query(1,id[top[v]],id[v]);
            v=fa[top[v]];
            ansv=pushup(s,ansv);
        } else {
            Seg s=query(1,id[top[u]],id[u]);
            u=fa[top[u]];
            ansu=pushup(s,ansu);
        }
    }
    if (layer[u]<layer[v]) {
        Seg s=query(1,id[u],id[v]);
        ansv=pushup(s,ansv);
    } else {
        Seg s=query(1,id[v],id[u]);
        ansu=pushup(s,ansu);
    }
    rev(ansu);
    pushup(ans,ansu,ansv);
    return ans;
}

signed main() {
    memset(h,-1,sizeof(h));
    scanf("%lld",&n);
    _rep(i,1,n) scanf("%lld",&arr[i]);
    _rep(i,1,n-1) {
        int a,b;
        scanf("%lld %lld",&a,&b);
        add(a,b); add(b,a);
    }
    dfs1(1,0,1);
    dfs2(1,1);
    build(1,1,n);
    scanf("%lld",&m);
    while (m--) {
        int op,a,b;
        scanf("%lld %lld %lld",&op,&a,&b);
        if (op==1) printf("%lld\n",query_path(a,b).mmx);
        else {
            int c;
            scanf("%lld",&c);
            modify_path(a,b,c);
        }
    }
    return 0;
}