#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N=100005;
const int M=600005;
const int inf=1e18;

int n,root,S,T;
int e[M],ne[M],f[M],h[N],tot;
int layer[N],cur[N];
bool flag[N];

void add(int a,int b,int c) {
    e[tot]=b,ne[tot]=h[a],f[tot]=c,h[a]=tot++;
    e[tot]=a,ne[tot]=h[b],f[tot]=0,h[b]=tot++;
}

bool bfs() {
    queue<int> q;
    memset(layer,-1,sizeof(layer));
    q.push(S); layer[S]=0; cur[S]=h[S];
    while (!q.empty()) {
        int u=q.front(); q.pop();
        for (int i=h[u];~i;i=ne[i]) {
            if (layer[e[i]]==-1 && f[i]) {
                layer[e[i]]=layer[u]+1;
                cur[e[i]]=h[e[i]];
                if (e[i]==T) return true;
                q.push(e[i]);
            }
        }
    }
    return false;
}

int debug;

int dfs(int u,int limit) {
    debug++;
    assert(debug<=1e7);
    if (u==T) return limit;
    int k=0;
    for (int i=cur[u];~i && k<limit;i=ne[i]) {
        cur[u]=i;
        if (layer[e[i]]==layer[u]+1 && f[i]) {
            int ret=dfs(e[i],min(f[i],limit-k));
            if (!ret) layer[e[i]]=-1;
            f[i]-=ret,f[i^1]+=ret,k+=ret;
        }
    }
    return k;
}

int dinic() {
    int k,ans=0;
    while (bfs()) while (k=dfs(S,inf)) ans+=k;
    return ans;
}

int vis[N];

void init(int u,int fa) {
    bool ok=false;
    vis[u]=true;
    for (int i=h[u];~i;i=ne[i]) {
        if (e[i]==fa || vis[e[i]]) continue;
        init(e[i],u);
        ok=true;
    }
    if (!ok) flag[u]=true;
}

signed main() {
    memset(h,-1,sizeof(h));
    scanf("%lld %lld",&n,&root); S=0,T=N-1;
    for (int i=1;i<=n-1;++i) {
        int a,b,c;
        scanf("%lld %lld %lld",&a,&b,&c);
        add(a,b,c);
        add(b,a,c);
    }
    init(root,0);
    add(S,root,inf);
    add(root,S,inf);
    for (int i=1;i<=n;++i) {
        if (flag[i]) {
            add(i,T,inf);
            add(T,i,inf);
        }
    }
    int ans=dinic();
    printf("%lld",ans);
    return 0;
}