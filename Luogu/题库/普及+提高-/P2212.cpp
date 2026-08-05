#include <bits/stdc++.h>

#define inf 0x3f3f3f3f

using namespace std;

int n,c;

struct dot {
    int x;
    int y;
} a[2005];

int G[2005][2005];
int dis[2005];
bool chk[2005];

inline int dist(int x1,int y1,int x2,int y2) {
    return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}

int prim() {
    memset(dis,0x3f,sizeof(dis));
    memset(chk,false,sizeof(chk));
    int tot=0;
    for (int i=1;i<=n;++i) {
        int curr=-1;
        for (int j=1;j<=n;++j) {
            if (!chk[j] && (curr==-1 || dis[j]<dis[curr])) {
                curr=j;
            }
        }
        if (i!=1 && dis[curr]==inf) return inf;
        if (i!=1) tot+=dis[curr];
        chk[curr]=true;
        for (int j=1;j<=n;++j) {
            dis[j]=min(dis[j],G[curr][j]);
        }
    }
    return tot;
}

int main() {
    scanf("%d %d",&n,&c);
    for (int i=1;i<=n;++i) {
        scanf("%d %d",&a[i].x,&a[i].y);
    }
    for (int i=1;i<=n;++i) {
        for (int j=1;j<=n;++j) {
            if (i==j) G[i][j]=inf;
            else if (dist(a[i].x,a[i].y,a[j].x,a[j].y)<c) G[i][j]=inf;
            else G[i][j]=dist(a[i].x,a[i].y,a[j].x,a[j].y);
        }
    }
    int ans=prim();
    if (ans==inf) puts("-1");
    else printf("%d",ans);
    return 0;
}