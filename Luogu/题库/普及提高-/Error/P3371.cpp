#include <bits/stdc++.h>

#define inf 0x7fffffff

using namespace std;

int n,m,s,u,v,w;
vector<int> G[10005];
vector<int> W[10005];
int dis[10005];
bool check[10005];

void dijkstra() {
    for (int i=0;i<=10004;++i) dis[i]=inf;
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
        for (int j=0;j<G[mini].size();++j) {
            if ((!check[G[mini][j]]) && (W[mini][j]+dis[mini]<dis[G[mini][j]])) {
                dis[G[mini][j]]=W[mini][j]+dis[mini];
            }
        }
    }
}

int main() {
    scanf("%d %d %d",&n,&m,&s);
    for (int i=1;i<=m;++i) {
        scanf("%d %d %d",&u,&v,&w);
        bool add=true;
        for (int j=0;j<G[u].size();++j) {
            if (G[u][j]==v) {
                if (W[u][v]>w) W[u][v]=w;
                add=false;
                break;
            }
        }
        if (add) {
            G[u].push_back(v);
            W[u].push_back(w);
        }
    }
    dijkstra();
    for (int i=1;i<=n;++i) {
        printf("%d ",dis[i]);
    }
    return 0;
}