#include <bits/stdc++.h>
using namespace std;

#define int unsigned int

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

const int N=1000005;
const int M=2000005;
const int K=N*30;
const int L=0,R=2.1e9;
const int inf=2e9+1e8;

int n,m;
int arr[N];
int e[M],ne[M],h[N],tot;
int layer[N],sz[N],top[N],fa[N],son[N];
int id[N],w[N],cnt;
int root[N];
stack<int> stk;

struct Seg {
    int l,r;
    int sum,add;
} seg[N<<2];

struct Seg2 {
    int l,r;
    int sz;
} tr[K];

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
    w[id[u]]=arr[u];
    if (!son[u]) return;
    dfs2(son[u],p);
    _graph(i,u) {
        if (e[i]==fa[u] || e[i]==son[u]) continue;
        dfs2(e[i],e[i]);
    }
}

void pushup(int u) {
    seg[u].sum=seg[u<<1].sum+seg[u<<1|1].sum;
}

void pushdown(int u) {
    auto &root=seg[u],&left=seg[u<<1],&right=seg[u<<1|1];
    if (root.add) {
        left.add+=root.add;
        left.sum+=(left.r-left.l+1)*root.add;
        right.add+=root.add;
        right.sum+=(right.r-right.l+1)*root.add;
        root.add=0;
    }
}

void build(int u,int l,int r) {
    seg[u]={l,r,w[l],0};
    if (l==r) return;
    int mid=l+r>>1;
    build(u<<1,l,mid); build(u<<1|1,mid+1,r);
    pushup(u);
}

void modify(int u,int l,int r,int k) {
    if (seg[u].l>=l && seg[u].r<=r) {
        seg[u].add+=k;
        seg[u].sum+=(seg[u].r-seg[u].l+1)*k;
    } else {
        pushdown(u);
        int mid=seg[u].l+seg[u].r>>1;
        if (l<=mid) modify(u<<1,l,r,k);
        if (r>mid) modify(u<<1|1,l,r,k);
        pushup(u);
    }
}

int query(int u,int p) {
    if (seg[u].l==p && seg[u].r==p) return seg[u].sum;
    pushdown(u);
    int mid=seg[u].l+seg[u].r>>1;
    if (p<=mid) return query(u<<1,p);
    else return query(u<<1|1,p);
}

int newNode() {
    int ans=stk.top();
    stk.pop();
    tr[ans]={0,0,0};
    return ans;
}

void delNode(int x) {
    stk.emplace(x);
}

void pushupp(int u) {
    tr[u].sz=tr[tr[u].l].sz+tr[tr[u].r].sz;
}

void insert(int u,int p,int l,int r) {
    if (p==l && p==r) tr[u].sz++;
    else {
        int mid=l+r>>1;
        if (p<=mid) {
            if (!tr[u].l) tr[u].l=newNode();
            insert(tr[u].l,p,l,mid);
        } else {
            if (!tr[u].r) tr[u].r=newNode();
            insert(tr[u].r,p,mid+1,r);
        }
        pushupp(u);
    }
}

bool remove(int u,int p,int l,int r) {
    if (p==l && p==r) {
        tr[u].sz--;
        if (!tr[u].sz) {
            delNode(u);
            return true;
        }
        return false;
    } else {
        int mid=l+r>>1;
        if (p<=mid) {
            if (remove(tr[u].l,p,l,mid)) tr[u].l=0;
        } else {
            if (remove(tr[u].r,p,mid+1,r)) tr[u].r=0;
        }
        if (!tr[u].l && !tr[u].r) {
            delNode(u);
            return true;
        }
        pushupp(u);
        return false;
    }
}

void dfs3(int u) {
    root[u]=newNode();
    tr[root[u]]={0,0,0};
    insert(root[u],arr[u],L,R);
    _graph(i,u) {
        if (e[i]==fa[u]) continue;
        if (e[i]!=son[u]) insert(root[u],arr[e[i]],L,R);
        dfs3(e[i]);
    }
}

void modify_path(int u,int v,int k) {
    while (top[u]!=top[v]) {
        if (layer[top[u]]<layer[top[v]]) swap(u,v);
        modify(1,id[top[u]],id[u],k);
        u=fa[top[u]];
        int t=query(1,id[son[u]]);
        remove(root[u],t,L,R);
        t+=k;
        insert(root[u],t,L,R);
    }
    if (layer[u]<layer[v]) swap(u,v);
    modify(1,id[v],id[u],k);
}

int find_yth(int u,int y,int l,int r) {
    if (l==r) return l;
    int mid=l+r>>1;
    if (y<=tr[tr[u].l].sz) return find_yth(tr[u].l,y,l,mid);
    y-=tr[tr[u].l].sz;
    return find_yth(tr[u].r,y,mid+1,r);
}

int query_yth(int x,int y) {
    int p;
    if (fa[x]) p=query(1,id[fa[x]]);
    else p=0;
    int s;
    if (son[x]) s=query(1,id[son[x]]);
    else s=0;
    if (p) insert(root[x],p,L,R);
    if (s) insert(root[x],s,L,R);
    int ans=find_yth(root[x],y,L,R);
    if (p) remove(root[x],p,L,R);
    if (s) remove(root[x],s,L,R);
    return ans;
}

void init_stk() {
    _rep(i,1,K-1) stk.emplace(i);
}

signed main() {
    memset(h,-1,sizeof(h));
    init_stk();
    scanf("%u %u",&n,&m);
    _rep(i,1,n) scanf("%u",&arr[i]);
    _rep(i,1,n-1) {
        int a,b;
        scanf("%u %u",&a,&b);
        add(a,b); add(b,a);
    }
    dfs1(1,0,1);
    dfs2(1,1);
    dfs3(1);
    build(1,1,n);
    while (m--) {
        int op;
        scanf("%u",&op);
        if (op==1) {
            int x,y,z;
            scanf("%u %u %u",&x,&y,&z);
            modify_path(x,y,z);
        } else {
            int x,y;
            scanf("%u %u",&x,&y);
            int ans=query_yth(x,y);
            printf("%u\n",ans);
        }
    }
    return 0;
}