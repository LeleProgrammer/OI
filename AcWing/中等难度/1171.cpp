#include <bits/stdc++.h>
using namespace std;

const int N=10005;

int h[N];
int e[N*2];
int w[N*2];
int ne[N*2];
int tot;
int n,m;
int x,y,k;

vector< pair<int,int> > qs[N];

// 链式前向星存图
void add(int a,int b,int c) {
    e[++tot]=b;
    w[tot]=c;
    ne[tot]=h[a];
    h[a]=tot;
}

// 并查集

int p[N];

int fd(int x) {
    if (p[x]!=x) p[x]=fd(p[x]);
    return p[x];
}

// dfs 求 dis 数组，即每个点到根节点的距离

int dis[N];

void dfs(int curr,int parent) {
    for (int i=h[curr];i;i=ne[i]) {
        if (e[i]==parent) continue;
        dis[e[i]]=dis[curr]+w[i];
        dfs(e[i],curr);
    }
}

// tarjan 求 lca

int sta[N]; // 1 表示正在搜（遍历到了但还没有回溯）

int res[N*2]; // 储存结果

void tarjan(int curr) {
    sta[curr]=1; // 遍历到了
    for (int i=h[curr];i;i=ne[i]) { // 枚举与这个点连接的所有点
        if (!sta[e[i]]) { // 不能是父节点
            tarjan(e[i]); // 深搜
            // 这里要搜完才更新 p[e[i]]
            p[e[i]]=curr; // curr 的子树的所有节点的并查集指向 curr
        }
    }
    for (pair<int,int> gp:qs[curr]) { // 查找一下第一个点为 curr 的询问
        if (sta[gp.first]==2) { // 另外一个点必须是搜索过且已经结束的
            int tmp=fd(gp.first); // 获取
            // 根到第一个点的距离加上根到第二个点的距离
            // 根到这两个点的最近公共祖先的距离被算了两次
            // 减掉之后就是第一个点到第二个点的距离
            res[gp.second]=dis[gp.first]+dis[curr]-dis[tmp]*2;
        }
    }
    sta[curr]=2; // 结束搜索
}

int main() {
    scanf("%d %d",&n,&m);
    for (int i=1;i<=n-1;++i) {
        scanf("%d %d %d",&x,&y,&k);
        add(x,y,k);
        add(y,x,k);
    }
    for (int i=1;i<=m;++i) {
        scanf("%d %d",&x,&y);
        if (x!=y) {
            // 两边都要添加，有可能一个点在搜索的时候另外一个点还没搜索
            qs[x].push_back({y,i});
            qs[y].push_back({x,i});
        }
    }
    // 初始化并查集
    for (int i=1;i<=n;++i) p[i]=i;
    // dfs 初始化 dis 数组
    dfs(1,-1);
    // tarjan 求 lca
    tarjan(1);
    // 输出结果
    for (int i=1;i<=m;++i) {
        printf("%d\n",res[i]);
    }
    return 0;
}