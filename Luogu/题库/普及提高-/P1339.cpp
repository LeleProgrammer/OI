#include <bits/stdc++.h>

#define inf 0x3f3f3f3f

using namespace std;

int G[2505][2505];
int n,m,s,t,u,v,w;
int dis[2505];
bool check[2505];

void dijkstra() {
    for (int i=0;i<2505;++i) dis[i]=inf;
    memset(check,false,sizeof(check));
    dis[s]=0;
    for (int i=1;i<=n;++i) {
        int minn=inf,mini;
        for (int j=1;j<=n;++j) {
            if ((!check[j]) && dis[j]<minn) {
                minn=dis[j];
                mini=j;
            }
        }
        check[mini]=true;
        for (int j=1;j<=n;++j) {
            if (G[mini][j] && !check[j] && dis[j]>dis[mini]+G[mini][j]) {
                dis[j]=dis[mini]+G[mini][j];
            }
        }
    }
}

int main() {
    memset(G,0,sizeof(G));
    scanf("%d %d %d %d",&n,&m,&s,&t);
    for (int i=1;i<=m;++i) {
        scanf("%d %d %d",&u,&v,&w);
        G[u][v]=G[v][u]=w;
    }
    dijkstra();
    printf("%d",dis[t]);
    return 0;
}