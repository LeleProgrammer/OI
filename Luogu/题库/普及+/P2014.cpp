#include <bits/stdc++.h>
using namespace std;

const int N=305;
const int M=305;
const int inf=2e6;

int n,m;
int e[M],ne[M],h[N],tot;
int s[N];
int f[N][N];
int sz[N];

void add(int a,int b) {
    e[tot]=b,ne[tot]=h[a],h[a]=tot++;
}

void dfs(int u) {
    f[u][0]=0;
    f[u][1]=s[u];
    sz[u]=1;
    for (int i=h[u];~i;i=ne[i]) {
        dfs(e[i]);
        sz[u]+=sz[e[i]];
        for (int j=sz[u];j;--j) {
            for (int k=1;k<=j-1;++k) {
                f[u][j]=max(f[u][j],f[u][j-k]+f[e[i]][k]);
            }
        }
    }
    // printf("%d: ",u);
    // for (int i=0;i<=m;++i) {
    //     printf("%d ",f[u][i]);
    // }
    // puts("");
}

int main() {
    memset(h,-1,sizeof(h));
    scanf("%d %d",&n,&m);
    for (int i=1;i<=n;++i) {
        int k;
        scanf("%d %d",&k,&s[i]);
        add(k,i);
    }
    for (int i=0;i<=N-1;++i) {
        for (int j=0;j<=N-1;++j) {
            f[i][j]=-inf;
        }
    }
    f[0][0]=0;
    for (int i=h[0];~i;i=ne[i]) {
        dfs(e[i]);
        for (int j=m;j;--j) {
            for (int k=1;k<=j;++k) {
                f[0][j]=max(f[0][j],f[0][j-k]+f[e[i]][k]);
            }
        }
    }
    printf("%d",f[0][m]);
    return 0;
}