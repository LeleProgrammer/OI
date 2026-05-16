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
int e[M],ne[M],h[N],tot;
int layer[N],sz[N],son[N],fa[N],top[N],id[N],cnt;
int arr[N],w[N];

struct Seg {
    int l,r;
    int cnt;
    int L,R;
    int tag;
    void init() {
        L=R=cnt=0;
    }
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
    id[u]=++cnt,w[id[u]]=arr[u],top[u]=p;
    if (!son[u]) return;
    dfs2(son[u],p);
    _graph(i,u) {
        if (e[i]==fa[u] || e[i]==son[u]) continue;
        dfs2(e[i],e[i]);
    }
}

void pushup(Seg& u,Seg l,Seg r) {
    if (l.R==r.L) u.cnt=l.cnt+r.cnt-1;
    else u.cnt=l.cnt+r.cnt;
    if (l.L) u.L=l.L;
    else u.L=r.L;
    if (r.R) u.R=r.R;
    else u.R=l.R;
}

void pushup(int u) {
    pushup(tr[u],tr[u<<1],tr[u<<1|1]);
}

void pushdown(int u) {
    auto &root=tr[u],&left=tr[u<<1],&right=tr[u<<1|1];
    if (~root.tag) {
        left.tag=root.tag,right.tag=root.tag;
        left.cnt=right.cnt=1;
        left.L=left.R=right.L=right.L=root.tag;
        root.tag=-1;
    }
}

void build(int u,int l,int r) {
    tr[u]={l,r,1,w[l],w[l],-1};
    // printf("[%d , %d] : %d %d %d\n",l,r,tr[u].L,tr[u].R,tr[u].cnt);
    if (l==r) return;
    int mid=l+r>>1;
    build(u<<1,l,mid); build(u<<1|1,mid+1,r);
    pushup(u);
    // printf("[%d , %d] : %d %d %d\n",l,r,tr[u].L,tr[u].R,tr[u].cnt);
}

void modify(int u,int l,int r,int k) {
    if (tr[u].l>=l && tr[u].r<=r) {
        tr[u].cnt=1;
        tr[u].L=tr[u].R=k;
        tr[u].tag=k;
    } else {
        pushdown(u);
        int mid=tr[u].l+tr[u].r>>1;
        if (l<=mid) modify(u<<1,l,r,k);
        if (r>mid) modify(u<<1|1,l,r,k);
        pushup(u);
    }
}

Seg query(int u,int l,int r) {
    if (tr[u].l>=l && tr[u].r<=r) return tr[u];
    pushdown(u);
    int mid=tr[u].l+tr[u].r>>1;
    Seg ans,L,R;
    ans.init(),L.init(),R.init();
    if (l<=mid) L=query(u<<1,l,r);
    if (r>mid) R=query(u<<1|1,l,r);
    // cout<<tr[u].l<<" "<<tr[u].r<<" "<<L.cnt<<" "<<R.cnt<<endl;
    pushup(ans,L,R);
    return ans;
}

void modify_path(int u,int v,int c) {
    while (top[u]!=top[v]) {
        if (layer[top[u]]<layer[top[v]]) swap(u,v);
        modify(1,id[top[u]],id[u],c);
        u=fa[top[u]];
    }
    if (layer[u]<layer[v]) swap(u,v);
    modify(1,id[v],id[u],c);
}

Seg query_path(int u,int v) {
    Seg ansU,ansV;
    ansU.init(),ansV.init();
    while (top[u]!=top[v]) {
        if (layer[top[u]]<layer[top[v]]) swap(u,v),swap(ansU,ansV);
        Seg t=query(1,id[top[u]],id[u]);
        // printf("query %d, %d : %d\n",id[top[u]],id[u],t.cnt);
        pushup(ansU,t,ansU);
        u=fa[top[u]];
    }
    if (layer[u]<layer[v]) swap(u,v),swap(ansU,ansV);
    Seg t=query(1,id[v],id[u]);
    // printf("query %d, %d : %d\n",id[v],id[u],t.cnt);
    pushup(ansU,t,ansU);
    swap(ansV.L,ansV.R);
    pushup(ansU,ansV,ansU);
    // cout<<"Test: "<<ansU.cnt<<" "<<ansV.cnt<<endl;
    return ansU;
}

int main() {
    memset(h,-1,sizeof(h));
    scanf("%d %d",&n,&m);
    _rep(i,1,n) scanf("%d",&arr[i]);
    _rep(i,1,n-1) {
        int a,b;
        scanf("%d %d",&a,&b);
        add(a,b); add(b,a);
    }
    dfs1(1,0,1);
    dfs2(1,1);
    // printf("w: "); _rep(i,1,n) printf("%d ",w[i]); putchar(10);
    build(1,1,n);
    while (m--) {
        char op;
        scanf(" %c",&op);
        if (op=='Q') {
            int a,b;
            scanf("%d %d",&a,&b);
            printf("%d\n",query_path(a,b).cnt);
        } else {
            int a,b,c;
            scanf("%d %d %d",&a,&b,&c);
            modify_path(a,b,c);
        }
    }
    return 0;
}