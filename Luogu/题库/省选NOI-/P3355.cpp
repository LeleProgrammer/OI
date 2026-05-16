#include <bits/stdc++.h>

#define inf 2147483647

using namespace std;

const int N=500005;
const int M=500005;

int n,m,S,T;
bool flag[205][205];
int e[M],f[M],ne[M],h[N],tot;
int dx[8]={-1,-2,-2,-1,1,2,2,1};
int dy[8]={-2,-1,1,2,2,1,-1,-2};
int layer[N],cur[N];

void add(int a,int b,int c) {
    e[tot]=b,f[tot]=c,ne[tot]=h[a],h[a]=tot++;
    e[tot]=a,f[tot]=0,ne[tot]=h[b],h[b]=tot++;
}

int get(int i,int j) {
    return (i-1)*n+j;
}

bool check(int x,int y) {
    if (x>=1 && y>=1 && x<=n && y<=n && !flag[x][y]) {
        return true;
    } else {
        return false;
    }
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
    scanf("%d %d",&n,&m); S=0,T=N-1;
    int cnt=n*n;
    while (m--) {
        int a,b;
        scanf("%d %d",&a,&b);
        if (!flag[a][b]) cnt--;
        flag[a][b]=true;
    }
    for (int i=1;i<=n;++i) {
        for (int j=1;j<=n;++j) {
            if (flag[i][j] || (i+j)%2==0) continue;
            for (int p=0;p<8;++p) {
                int x=i+dx[p];
                int y=j+dy[p];
                if (check(x,y)) add(get(i,j),get(x,y),inf);
            }
        }
    }
    for (int i=1;i<=n;++i) {
        for (int j=1;j<=n;++j) {
            if ((i+j)%2) add(S,get(i,j),1);
            else add(get(i,j),T,1);
        }
    }
    printf("%d",cnt-dinic());
    return 0;
}