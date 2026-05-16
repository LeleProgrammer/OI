#include <bits/stdc++.h>

#define inf 0x3f3f3f3f

using namespace std;

const int N=405;
const int M=100005;

int n,F,D,S,T;
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
    scanf("%d %d %d",&n,&F,&D); S=0,T=F+n+n+D+1;
    for (int i=1;i<=n;++i) {
        int a,b;
        scanf("%d %d",&a,&b);
        while (a--) {
            int u;
            scanf("%d",&u);
            add(u,F+i,1);
        }
        while (b--) {
            int u;
            scanf("%d",&u);
            add(F+n+i,F+n+n+u,1);
        }
    }
    for (int i=1;i<=F;++i) {
        add(S,i,1);
    }
    for (int i=1;i<=D;++i) {
        add(F+n+n+i,T,1);
    }
    for (int i=F+1;i<=F+n;++i) {
        add(i,i+n,1);
    }
    printf("%d",dinic());
    return 0;
}