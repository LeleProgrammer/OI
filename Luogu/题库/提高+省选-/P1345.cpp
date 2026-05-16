#include <bits/stdc++.h>
using namespace std;

const int N=205;
const int M=2805;
const int inf=1e9;

int n,m,c1,c2,S,T;
int e[M],f[M],ne[M],h[N],tot;
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

int main() {
    memset(h,-1,sizeof(h));
    scanf("%d %d %d %d",&n,&m,&c1,&c2); S=0,T=N-1;
    while (m--) {
        int a,b;
        scanf("%d %d",&a,&b);
        add(a+n,b,inf);
        add(b+n,a,inf);
    }
    for (int i=1;i<=n;++i) {
        add(i,i+n,1);
    }
    add(S,c1+n,inf);
    add(c2,T,inf);
    int ans=dinic();
    printf("%d",ans);
    return 0;
}

/*
i 表示接收，n+i 表示连接出去，
为了放置最小割自动去除 c1，应该从源点直接连到 c1 的出点，
同理，从 c2 的入点连接到汇点。
*/