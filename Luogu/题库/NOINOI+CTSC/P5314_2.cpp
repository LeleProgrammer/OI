#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
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

namespace IO {
    inline void read(int &a) {
        int sym=1,num=0;
        char c=getchar();
        while (c<'0' || c>'9') {
            if (c=='-') {
                sym=-1;
            }
            c=getchar();
        }
        while (c>='0' && c<='9') {
            num=num*10+c-'0';
            c=getchar();
        }
        a=sym*num;
    }
    inline void write(int a) {
        if (a<0) {
            putchar('-');
            a*=-1;
        }
        if (a>=10) {
            write(a/10);
        }
        putchar(a%10+'0');
    }
}

using IO::read;
using IO::write;

const int N=1000005;
const int M=2000005;
const int inf=2e9+1e8;

int n,m;
int arr[N];
int e[M],ne[M],h[N],tot;
int layer[N],sz[N],top[N],fa[N],son[N];
int id[N],w[N],cnt;
tree<pii,null_type,less<pii>,rb_tree_tag,tree_order_statistics_node_update> root[N];
int tr[N];

inline void add(int a,int b) {
    e[tot]=b,ne[tot]=h[a],h[a]=tot++;
}

inline void dfs1(int u,int p,int dep) {
    sz[u]=1,fa[u]=p,layer[u]=dep;
    _graph(i,u) {
        if (e[i]==fa[u]) continue;
        dfs1(e[i],u,dep+1);
        sz[u]+=sz[e[i]];
        if (sz[e[i]]>sz[son[u]]) son[u]=e[i];
    }
}

inline void dfs2(int u,int p) {
    id[u]=++cnt,top[u]=p;
    w[id[u]]=arr[u];
    if (!son[u]) return;
    dfs2(son[u],p);
    _graph(i,u) {
        if (e[i]==fa[u] || e[i]==son[u]) continue;
        if (e[i]!=son[u]) root[u].insert({arr[e[i]],e[i]});
        dfs2(e[i],e[i]);
    }
}

int lowbit(int x) {
    return x&(-x);
}

void modify(int x,int k) {
    while (x<=n) {
        tr[x]+=k;
        x+=lowbit(x);
    }
}

int query(int x) {
    int ans=0;
    while (x>0) {
        ans+=tr[x];
        x-=lowbit(x);
    }
    return ans;
}

void modify(int l,int r,int k) {
    modify(l,k);
    modify(r+1,-k);
}

inline void modify_path(int u,int v,int k) {
    while (top[u]!=top[v]) {
        if (layer[top[u]]<layer[top[v]]) swap(u,v);
        modify(id[top[u]],id[u],k);
        int las=top[u];
        u=fa[top[u]];
        int t=query(id[las]);
        root[u].erase({t-k,las});
        root[u].insert({t,las});
    }
    if (layer[u]<layer[v]) swap(u,v);
    modify(id[v],id[u],k);
    if (v==top[v] && fa[v]) {
        int t=query(id[v]);
        root[fa[v]].erase({t-k,v});
        root[fa[v]].insert({t,v});
    }
}

inline int query_yth(int x,int y) {
    int p;
    if (fa[x]) p=query(id[fa[x]]);
    else p=0;
    int s;
    if (son[x]) s=query(id[son[x]]);
    else s=0;
    int u=query(id[x]);
    root[x].insert({u,x});
    if (p) root[x].insert({p,fa[x]});
    if (s) root[x].insert({s,son[x]});
    int ans=root[x].find_by_order(y-1)->first;
    if (p) root[x].erase({p,fa[x]});
    if (s) root[x].erase({s,son[x]});
    root[x].erase({u,x});
    return ans;
}

int main() {
    memset(h,-1,sizeof(h));
    read(n),read(m);
    _rep(i,1,n) read(arr[i]);
    _rep(i,1,n-1) {
        int a,b;
        read(a),read(b);
        add(a,b); add(b,a);
    }
    dfs1(1,0,1);
    dfs2(1,1);
    _rep(i,1,n) modify(i,w[i]-w[i-1]);
    while (m--) {
        int op;
        read(op);
        if (op==1) {
            int x,y,z;
            read(x),read(y),read(z);
            modify_path(x,y,z);
        } else {
            int x,y;
            read(x),read(y);
            int ans=query_yth(x,y);
            write(ans); putchar(10);
        }
    }
    return 0;
}