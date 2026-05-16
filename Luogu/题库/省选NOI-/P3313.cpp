#include <bits/stdc++.h>
using namespace std;

#define int long long

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

int n,q;
int e[M],ne[M],h[N],tot;
int id[N],son[N],sz[N],top[N],fa[N],dep[N],cnt;
int idx,root[N];
vector<int> vec;

struct node {
    int w,c;
} arr[N],w[N];

struct Seg {
    int l,r;
    int ls,rs;
    int sum,max;
} tr[N*25];

void add(int a,int b) {
    e[tot]=b,ne[tot]=h[a],h[a]=tot++;
}

void dfs1(int u,int p,int d) {
    fa[u]=p,dep[u]=p,sz[u]=1;
    _graph(i,u) {
        if (e[i]==fa[u]) continue;
        dfs1(e[i],u,d+1);
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

int new_node() {
    int k=vec.back();
    vec.pop_back();
    return k;
}

void del_node(int k) {
    vec.emplace_back(k);
}

void pushup(int u) {
    tr[u].sum=tr[tr[u].ls].sum+tr[tr[u].rs].sum;
    tr[u].max=max(tr[tr[u].ls].max,tr[tr[u].rs].max);
}

void build(int u,int pos,Seg& origin) {
    if (tr[u].l==pos && tr[u].r==pos) {
        tr[u].sum=origin.sum;
        tr[u].max=origin.max;
    } else {
        int mid=tr[u].l+tr[u].r>>1;
        if (pos<=mid) {
            if (!tr[u].ls) tr[u].ls=new_node(),tr[tr[u].ls]={tr[u].l,mid,0,0,0};
            build(tr[u].ls,pos,origin);
        } else {
            if (!tr[u].rs) tr[u].rs=new_node(),tr[tr[u].rs]={mid+1,tr[u].r,0,0,0};
            build(tr[u].rs,pos,origin);
        }
        pushup(u);
    }
}

bool destroy(int u,int pos) {
    if (tr[u].l==pos && tr[u].r==pos) {
        return true;
    } else {
        int mid=tr[u].l+tr[u].r>>1;
        if (pos<=mid) {
            if (destroy(tr[u].ls,pos)) {
                del_node(tr[u].ls),tr[u].ls=0;
                if (!tr[u].rs) return true;
            }
        } else {
            if (destroy(tr[u].rs,pos)) {
                del_node(tr[u].rs),tr[u].rs=0;
                if (!tr[u].ls) return true;
            }
        }
        pushup(u);
        return false;
    }
}

void modify(int u,int pos,int x) {
    if (tr[u].l==pos && tr[u].r==pos) tr[u].max=tr[u].sum=x;
    else {
        int mid=tr[u].l+tr[u].r>>1;
        if (pos<=mid) modify(tr[u].ls,pos,x);
        else modify(tr[u].rs,pos,x);
        pushup(u);
    }
}

int query_max(int u,int l,int r) {
    if (tr[u].l>=l && tr[u].r<=r) return tr[u].max;
    int mid=tr[u].l+tr[u].r>>1;
    int ans=0;
    if (l<=mid && tr[u].ls) ans=max(ans,query_max(tr[u].ls,l,r));
    if (r>mid && tr[u].rs) ans=max(ans,query_max(tr[u].rs,l,r));
    return ans;
}

int query_sum(int u,int l,int r) {
    if (tr[u].l>=l && tr[u].r<=r) return tr[u].sum;
    int mid=tr[u].l+tr[u].r>>1;
    int ans=0;
    if (l<=mid && tr[u].ls) ans+=query_sum(tr[u].ls,l,r);
    if (r>mid && tr[u].rs) ans+=query_sum(tr[u].rs,l,r);
    return ans;
}

int query_max_path(int u,int v,int c) {
    int ans=0;
    while (top[u]!=top[v]) {
        if (dep[top[u]]<dep[top[v]]) swap(u,v);
        ans=max(ans,query_max(root[c],id[top[u]],id[u]));
        u=fa[top[u]];
    }
    if (dep[u]<dep[v]) swap(u,v);
    ans=max(ans,query_max(root[c],id[v],id[u]));
    return ans;
}

int query_sum_path(int u,int v,int c) {
    int ans=0;
    while (top[u]!=top[v]) {
        if (dep[top[u]]<dep[top[v]]) swap(u,v);
        ans+=query_sum(root[c],id[top[u]],id[u]);
        u=fa[top[u]];
    }
    if (dep[u]<dep[v]) swap(u,v);
    ans+=query_sum(root[c],id[v],id[u]);
    return ans;
}

Seg get_origin(int u,int pos) {
    if (tr[u].l==pos && tr[u].r==pos) return tr[u];
    int mid=tr[u].l+tr[u].r>>1;
    if (pos<=mid) return get_origin(tr[u].ls,pos);
    else return get_origin(tr[u].rs,pos);
}

signed main() {
    memset(h,-1,sizeof(h));
    scanf("%lld %lld",&n,&q);
    _rep(i,1,n) {
        int w,c;
        scanf("%lld %lld",&w,&c);
        arr[i]={w,c};
    }
    _rep(i,1,n-1) {
        int a,b;
        scanf("%lld %lld",&a,&b);
        add(a,b); add(b,a);
    }
    dfs1(1,0,1),dfs2(1,1);
    _rep(i,1,N*25-1) vec.emplace_back(i);
    _rep(i,1,n) root[i]=new_node(),tr[root[i]]={1,n,0,0,0};
    _rep(i,1,n) {
        Seg s={0,0,0,0,arr[i].w,arr[i].w};
        build(root[arr[i].c],id[i],s);
    }
    while (q--) {
        char op[3];
        int x,y;
        scanf("%s %lld %lld",op,&x,&y);
        if (!strcmp(op,"CC")) {
            if (arr[x].c==y) continue;
            Seg s=get_origin(root[arr[x].c],id[x]);
            build(root[y],id[x],s);
            destroy(root[arr[x].c],id[x]);
            arr[x].c=y;
        } else if (!strcmp(op,"CW")) {
            modify(root[arr[x].c],id[x],y);
        } else if (!strcmp(op,"QS")) {
            int k=query_sum_path(x,y,arr[y].c);
            printf("%lld\n",k);
        } else if (!strcmp(op,"QM")) {
            int k=query_max_path(x,y,arr[y].c);
            printf("%lld\n",k);
        } else assert(false);
    }
    return 0;
}