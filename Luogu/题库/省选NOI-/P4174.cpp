#include <bits/stdc++.h>

#define inf 0x3f3f3f3f

using namespace std;

const int N=100005;
const int M=500005;

int n,m,S,T;
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

int main() {
    memset(h,-1,sizeof(h));
    scanf("%d %d",&n,&m); S=0,T=N-1;
    for (int i=1;i<=n;++i) {
        int p;
        scanf("%d",&p);
        add(m+i,T,p);
    }
    int cnt=0;
    for (int i=1;i<=m;++i) {
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        add(S,i,c);
        add(i,m+a,inf);
        add(i,m+b,inf);
        cnt+=c;
    }
    /*
    cnt 记录的是所有与源点连接的边的容量之和
    dinic 求的是割边的最小值
    相减便得到所选边之和
    */
    printf("%d",cnt-dinic());
    return 0;
}