#include <bits/stdc++.h>

#define inf 2147483647

using namespace std;

const int K=10005;
const int N=1110007;
const int M=6120005;

int n,S,T;
int e[M],f[N],ne[M],h[N],tot;
int layer[N],cur[N];

void add(int a,int b,int c) {
    e[tot]=b,f[tot]=c,ne[tot]=h[a],h[a]=tot++;
    e[tot]=a,f[tot]=0,ne[tot]=h[b],h[b]=tot++;
}

bool bfs() {
    queue<int> q;
    memset(layer,-1,sizeof(layer));
    layer[S]=0; cur[S]=h[S];
    q.push(S);
    while (!q.empty()) {
        int u=q.front(); q.pop();
        for (int i=h[u];~i;i=ne[i]) {
            if (layer[e[i]]==-1 && f[i]>=1) {
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
        if (layer[e[i]]==layer[u]+1 && f[i]>=1) {
            int ret=dfs(e[i],min(f[i],limit-k));
            if (!ret) layer[e[i]]=-1;
            f[i]-=ret,f[i^1]+=ret,k+=ret;
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
    scanf("%d",&n); S=0,T=N-1;
    for (int i=1;i<=n;++i) {
        int a,b;
        scanf("%d %d",&a,&b);
        add(S,i,1);
        add(i,n+a,1);
        add(i,n+b,1);
    }
    for (int i=1;i<=K;++i) {
        add(n+i,T,1);
    }
    dinic();
    int cnt=0;
    for (int i=1;i<=K;++i) {
        if (f[h[n+i]]) break;
        cnt++;
    }
    printf("%d",cnt);
    return 0;
}

/*
HACK:
4
1 4
1 2
2 3
3 5
*/