#include <bits/stdc++.h>
using namespace std;

const int N=10005;
const int M=30005;

int n,m,u,v;
int e[M],ne[M],h[N],tot;
int dfn[N],low[N],ts;
int root,ans;

void add(int a,int b) {
    e[tot]=b,ne[tot]=h[a],h[a]=tot++;
}

void tarjan(int u) {
    dfn[u]=low[u]=++ts; // 标记时间戳
    int cnt=0; // 以 u 为根节点的子树，去除 u 后连通块的个数
    for (int i=h[u];~i;i=ne[i]) { // 枚举每一条边
        if (!dfn[e[i]]) { // 没有搜过
            tarjan(e[i]); // 搜索
            low[u]=min(low[u],low[e[i]]); // 更新 low
            if (low[e[i]]>=dfn[u]) { // 下一个点最多只能到达自己或以下
                cnt++; // u 是割点
            }
        } else { // 搜过了
            low[u]=min(low[u],dfn[e[i]]); // 更新 low
        }
    }
    if (u!=root) cnt++; // 如果 u 不是最原先搜索时的根节点，则去除后会加一个连通块
    ans=max(ans,cnt); // 结果取更大值
}

int main() {
    while (scanf("%d %d",&n,&m),n || m) {
        memset(dfn,0,sizeof(dfn));
        memset(h,-1,sizeof(h));
        tot=0; ts=0;
        while (m--) {
            scanf("%d %d",&u,&v);
            add(u,v),add(v,u);
        }
        ans=0;
        int ltk=0;
        for (root=0;root<=n-1;++root) {
            if (!dfn[root]) {
                ltk++; // 原图若不连通，此处连通块 +1
                tarjan(root); // 搜索该连通块
            }
        }
        printf("%d",ans+ltk-1);
        putchar(10);
    }
    return 0;
}