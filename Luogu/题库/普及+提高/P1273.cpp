#include <bits/stdc++.h>
using namespace std;

const int N=3005;
const int M=6005;
const int inf=2000000000;

int n,m;
int e[M],ne[M],h[N],w[N],tot;
int a[N];
int f[N][N];
int sz[N];

void add(int a,int b,int c) {
    e[tot]=b,w[tot]=c,ne[tot]=h[a],h[a]=tot++;
}

void dfs(int u) {
    f[u][0]=0;
    if (u>=n-m+1) {
        f[u][1]=a[u];
        sz[u]=1;
        return;
    }
    for (int i=h[u];~i;i=ne[i]) {
        dfs(e[i]);
        sz[u]+=sz[e[i]];
        for (int j=sz[u];j;--j) {
            for (int k=0;k<=sz[e[i]] && k<=j;++k) {
                f[u][j]=max(f[u][j],f[u][j-k]+f[e[i]][k]-w[i]);
            }
        }
        // printf("%d: ",u);
        // for (int i=0;i<=m;++i) {
        //     printf("%d ",f[u][i]);
        // }
        // putchar(10);
    }
}

int main() {
    memset(h,-1,sizeof(h));
    scanf("%d %d",&n,&m);
    for (int i=1;i<=n-m;++i) {
        int k;
        scanf("%d",&k);
        for (int j=1;j<=k;++j) {
            int a,b;
            scanf("%d %d",&a,&b);
            add(i,a,b);
        }
    }
    for (int i=n-m+1;i<=n;++i) {
        scanf("%d",&a[i]);
    }
    for (int i=0;i<=N-1;++i) {
        for (int j=0;j<=N-1;++j) {
            f[i][j]=-inf;
        }
    }
    dfs(1);
    for (int i=m;i;--i) {
        if (f[1][i]<0) continue;
        printf("%d",i);
        return 0;
    }
    return 0;
}