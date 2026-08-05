#include <bits/stdc++.h>

#define inf 0x3f3f3f3f

using namespace std;

int a,n;
int G[505][505];
int dis[505];
bool chk[505];

int prim() {
    memset(dis,0x3f,sizeof(dis));
    memset(chk,false,sizeof(chk));
    int ans=a;
    for (int i=1;i<=n;++i) {
        int curr=-1;
        for (int j=1;j<=n;++j) {
            if (!chk[j] && (curr==-1 || dis[j]<dis[curr])) {
                curr=j;
            }
        }
        if (i!=1) ans+=dis[curr];
        chk[curr]=true;
        for (int j=1;j<=n;++j) {
            dis[j]=min(dis[j],G[curr][j]);
        }
    }
    return ans;
}

int main() {
    scanf("%d %d",&a,&n);
    for (int i=1;i<=n;++i) {
        for (int j=1;j<=n;++j) {
            scanf("%d",&G[i][j]);
            if (G[i][j]>a) G[i][j]=a;
            else if (i==j) G[i][j]=inf;
            else if (G[i][j]==0) G[i][j]=a;
        }
    }
    int ans=prim();
    printf("%d",ans);
    return 0;
}