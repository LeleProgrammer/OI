#include <bits/stdc++.h>
using namespace std;

int n,q,u,v;
bool G[305][305];
int values[305];
int dis[305][305];
int cnt[305][305];
bool check[305];

void dijkstra(int s) {
    dis[s][s]=0;
    cnt[s][s]=values[s];
    memset(check,false,sizeof(check));
    // check[s]=true;
    for (int i=1;i<=n;++i) {
        int minn=0x3f3f3f3f,mini;
        for (int j=1;j<=n;++j) {
            if ((!check[j]) && dis[s][j]<minn) {
                minn=dis[s][j],mini=j;
            }
        }
        check[mini]=true;
        for (int j=1;j<=n;++j) {
            if (G[mini][j] && (!check[j]) && ((dis[s][mini]+1<dis[s][j]) || (dis[s][mini]+1==dis[s][j] && cnt[s][mini]+values[j]>cnt[s][j]))) {
                dis[s][j]=dis[s][mini]+1;
                cnt[s][j]=cnt[s][mini]+values[j];
            }
        }
    }
}

int main() {
    scanf("%d",&n);
    for (int i=1;i<=n;++i) {
        scanf("%d",values+i);
    }
    char c;
    for (int i=1;i<=n;++i) {
        for (int j=1;j<=n;++j) {
            scanf(" %c",&c);
            if (c=='N') {
                G[i][j]=false;
            } else {
                G[i][j]=true;
            }
        }
    }
    for (int i=1;i<=n;++i) {
        for (int j=1;j<=n;++j) {
            dis[i][j]=0x3f3f3f3f;
        }
    }
    for (int i=1;i<=n;++i) {
        dijkstra(i);
    }
    scanf("%d",&q);
    for (int i=1;i<=q;++i) {
        scanf("%d %d",&u,&v);
        if (dis[u][v]==0x3f3f3f3f) {
            printf("Impossible\n");
            continue;
        }
        printf("%d %d\n",dis[u][v],cnt[u][v]);
    }
    return 0;
}