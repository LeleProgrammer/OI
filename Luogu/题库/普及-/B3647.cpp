#include <bits/stdc++.h>

#define inf 0x3f3f3f3f

using namespace std;

int n,m,u,v,w;
int g[105][105];

void floyd() {
    for (int k=1;k<=n;++k) {
        for (int i=1;i<=n;++i) {
            for (int j=1;j<=n;++j) {
                g[i][j]=min(g[i][k]+g[k][j],g[i][j]);
            }
        }
    }
}

int main() {
    for (int i=1;i<=104;++i) {
        for (int j=1;j<=104;++j) {
            g[i][j]=inf;
        }
    }
    for (int i=1;i<=104;++i) g[i][i]=0;
    scanf("%d %d",&n,&m);
    for (int i=1;i<=m;++i) {
        scanf("%d %d %d",&u,&v,&w);
        g[u][v]=w;
        g[v][u]=w;
    }
    floyd();
    for (int i=1;i<=n;++i) {
        for (int j=1;j<=n;++j) {
            printf("%d ",g[i][j]);
        }
        printf("\n");
    }
    return 0;
}