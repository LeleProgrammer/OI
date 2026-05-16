#include <bits/stdc++.h>
using namespace std;

const int N=10005;
const int M=120005;
const int K=105;
const int inf=1e9;

int n,m,S,T;
int arr[K][K];
int e[M],ne[M],f[M],h[N],tot;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int layer[N],cur[N];

void add(int a,int b,int c) {
    e[tot]=b,f[tot]=c,ne[tot]=h[a],h[a]=tot++;
    e[tot]=a,f[tot]=0,ne[tot]=h[b],h[b]=tot++;
}

int get(int i,int j) {
    return (i-1)*m+j;
}

bool check(int i,int j) {
    if (i>=1 && i<=n && j>=1 && j<=m) return true;
    return false;
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
    scanf("%d %d",&n,&m); S=0,T=N-1;
    for (int i=1;i<=n;++i) {
        for (int j=1;j<=m;++j) {
            scanf("%d",&arr[i][j]);
        }
    }
    for (int i=1;i<=n;++i) {
        for (int j=1;j<=m;++j) {
            for (int p=0;p<4;++p) {
                if (!check(i+dx[p],j+dy[p])) continue;
                add(get(i,j),get(i+dx[p],j+dy[p]),1);
            }
            if (arr[i][j]==1) add(S,get(i,j),inf);
            else if (arr[i][j]==2) add(get(i,j),T,inf);
        }
    }
    int ans=dinic();
    printf("%d",ans);
    return 0;
}