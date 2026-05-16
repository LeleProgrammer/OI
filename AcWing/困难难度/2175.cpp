#include <bits/stdc++.h>

#define inf 0x3f3f3f3f

using namespace std;

const int N=105;
const int M=5250;

int n,m,S,T,a,b;
int e[M],ne[M],f[M],h[N],tot;
int layer[N],cur[N];

void add(int a,int b,int c) {
    e[tot]=b,f[tot]=c,ne[tot]=h[a],h[a]=tot++;
    e[tot]=a,f[tot]=0,ne[tot]=h[b],h[b]=tot++;
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

int main() {
    memset(h,-1,sizeof(h));
    scanf("%d %d",&m,&n); S=0,T=n+1;
    for (int i=1;i<=m;++i) add(S,i,1);
    for (int i=m+1;i<=n;++i) add(i,T,1);
    while (scanf("%d %d",&a,&b)!=EOF && a!=-1) add(a,b,1);
    printf("%d\n",dinic());
    for (int i=0;i<tot;i+=2) {
        if (e[i^1]>=1 && e[i^1]<=m && !f[i]) {
            printf("%d %d\n",e[i^1],e[i]);
        }
    }
    return 0;
}