#include <bits/stdc++.h>

#define int long long
#define inf 1000000000000000000LL

using namespace std;

const int N=205;
const int M=4005;

int n,m,x,a,b,c,S,T;
int e[M],ne[M],f[M],h[N],tot;
int layer[N],cur[N];

void add(int a,int b,int c) {
    e[tot]=b,f[tot]=c,ne[tot]=h[a],h[a]=tot++;
    e[tot]=a,f[tot]=0,ne[tot]=h[b],h[b]=tot++;
}

bool bfs() {
    memset(layer,-1,sizeof(layer));
    queue<int> q;
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

int dfs(int u,int limit) {
    if (u==T) return limit;
    int k=0;
    for (int i=cur[u];~i && k<limit;i=ne[i]) {
        cur[u]=i;
        if (layer[e[i]]==layer[u]+1 && f[i]) {
            int ret=dfs(e[i],min(f[i],limit-k));
            if (!ret) layer[e[i]]=-1;
            k+=ret,f[i]-=ret,f[i^1]+=ret;
        }
    }
    return k;
}

int dinic() {
    int ans=0,k;
    while (bfs()) while (k=dfs(S,inf)) ans+=k;
    return ans;
}

signed main() {
    memset(h,-1,sizeof(h));
    scanf("%lld %lld %lld",&n,&m,&x); S=1,T=n;
    while (m--) {
        scanf("%lld %lld %lld",&a,&b,&c);
        add(a,b,c);
    }
    int flow=dinic();
    if (!flow) puts("Orz Ni Jinan Saint Cow!");
    else printf("%lld %lld",flow,(int)ceil((double(x))/(double(flow))));
    return 0;
}