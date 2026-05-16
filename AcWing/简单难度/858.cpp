#include <bits/stdc++.h>

#define inf 0x3f3f3f3f

using namespace std;

int n,m;
int u,v,w;
int G[505][505];
int dis[505];
bool chk[505];

int prim() {
    for (int i=1;i<=500;++i) dis[i]=inf;
    memset(chk,false,sizeof(chk));
    int ans=0;
    for (int i=1;i<=n;++i) {
        // 寻找距离集合最近的点
        // minn 表示下标
        int minn=-1;
        for (int j=1;j<=n;++j) {
            if (!chk[j] && (minn==-1 || dis[j]<dis[minn])) {
                minn=j;
            }
        }
        // 只有当前点是第一个点的时候才有可能是 inf
        // 如果不是第一个点，却出现了 inf，就说明该图不是连通图
        // 非连通图没有最小生成树
        if (i>=2 && dis[minn]==inf) return inf;
        // 计入最小生成树的总路径长度
        // 第一个点则不需要计入长度
        if (i>=2) ans=ans+dis[minn];
        // 加入集合，即添加到最小生成树中
        chk[minn]=true;
        // 将与该点有直接连接的集合外的点，更新距离
        for (int j=1;j<=n;++j) {
            dis[j]=min(dis[j],G[minn][j]);
        }
        // 更新距离的代码不能放到计入总长度和加入集合的前面
        // 如果该无向图存在自环，且为负权边，就会错误地更新到该点的 dis
    }
    return ans;
}

int main() {
    scanf("%d %d",&n,&m);
    for (int i=1;i<=500;++i) {
        for (int j=1;j<=500;++j) {
            G[i][j]=inf;
        }
    }
    for (int i=1;i<=m;++i) {
        scanf("%d %d %d",&u,&v,&w);
        G[u][v]=G[v][u]=min(G[u][v],w); // 可能有重边
    }
    int res=prim();
    if (res==inf) printf("impossible");
    else printf("%d",res);
    return 0;
}