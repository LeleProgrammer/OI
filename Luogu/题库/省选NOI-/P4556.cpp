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
const int K=25;

int n,m;
int e[M],ne[M],h[N],tot;
int layer[N],f[N][K];
int ans[N];
int idx;
unordered_map<int,int> cnt[N];
queue<int> q;

struct Seg {
    int l,r;
    int v,p;
} tr[(N<<2)*32];

void add(int a,int b) {
    e[tot]=b,ne[tot]=h[a],h[a]=tot++;
}

void bfs() {
    q.emplace(1); layer[1]=1;
    while (!q.empty()) {
        int u=q.front(); q.pop();
        _graph(i,u) {
            if (!layer[e[i]]) {
                layer[e[i]]=layer[u]+1;
                q.emplace(e[i]);
                f[e[i]][0]=u;
                _rep(j,1,K-1) f[e[i]][j]=f[f[e[i]][j-1]][j-1];
            }
        }
    }
}

int lca(int a,int b) {
    if (layer[a]<layer[b]) swap(a,b);
    _rrep(i,K-1,0) if (layer[f[a][i]]>=layer[b]) a=f[a][i];
    if (a==b) return a;
    _rrep(i,K-1,0) if (f[a][i]!=f[b][i]) a=f[a][i],b=f[b][i];
    return f[a][0];
}

int newNode() {
    tr[++idx]={0,0,0,0};
    return idx;
}

void pushup(int u) {
    tr[u].v=max(tr[tr[u].l].v,tr[tr[u].r].v);
    if (tr[u].v==tr[tr[u].l].v) tr[u].p=tr[tr[u].l].p;
    else tr[u].p=tr[tr[u].r].p;
}

void insert(int u,int l,int r,int p,int k) {
    // cout<<"insert "<<l<<" "<<r<<" "<<p<<" "<<k<<endl;
    if (l==p && r==p) {
        tr[u].v=k,tr[u].p=p;
        return;
    }
    int mid=l+r>>1;
    if (p<=mid) {
        if (!tr[u].l) tr[u].l=newNode();
        insert(tr[u].l,l,mid,p,k);
    } else {
        if (!tr[u].r) tr[u].r=newNode();
        insert(tr[u].r,mid+1,r,p,k);
    }
    pushup(u);
}

int merge(int a,int b,int l,int r) {
    // cout<<"merge "<<a<<" "<<b<<" "<<l<<" "<<r<<endl;
    if (!a) return b;
    else if (!b) return a;
    else if (l==r) tr[a].v+=tr[b].v;
    else {
        int mid=l+r>>1;
        tr[a].l=merge(tr[a].l,tr[b].l,l,mid);
        tr[a].r=merge(tr[a].r,tr[b].r,mid+1,r);
        pushup(a);
    }
    return a;
}

int dfs(int p,int fa) {
    // cout<<"dfs "<<p<<endl;
    int u=++idx;
    tr[u]={0,0,0};
    _iter(it,cnt[p]) if (it->second) insert(u,1,1e5,it->first,it->second);
    _graph(i,p) {
        if (e[i]==fa) continue;
        int t=dfs(e[i],p);
        u=merge(u,t,1,1e5);
    }
    // cout<<"ans "<<p<<": "<<tr[u].p<<" "<<tr[u].v<<endl;
    if (!tr[u].v) ans[p]=0;
    else ans[p]=tr[u].p;
    return u;
}

int main() {
    // FRR("P4556_2.in");
    // FRW("P4556_my.out");
    memset(h,-1,sizeof(h));
    scanf("%d %d",&n,&m);
    _rep(i,1,n-1) {
        int a,b;
        scanf("%d %d",&a,&b);
        add(a,b); add(b,a);
    }
    bfs();
    while (m--) {
        int x,y,z;
        scanf("%d %d %d",&x,&y,&z);
        int g=lca(x,y);
        // cout<<"lca "<<x<<" "<<y<<" is "<<g<<endl;
        cnt[x][z]++,cnt[y][z]++,cnt[g][z]--,cnt[f[g][0]][z]--;
    }
    dfs(1,0);
    _rep(i,1,n) printf("%d\n",ans[i]);
    return 0;
}