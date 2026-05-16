#include <bits/stdc++.h>

#define inf 0x3f3f3f3f

using namespace std;

const int N=40005;

int n,m,a,b;

int e[N*2];
int ne[N*2];
int h[N*2];
int tot;

// 链式前向星
void add(int u,int v) {
    e[++tot]=v;
    ne[tot]=h[u];
    h[u]=tot;
}

// lca 必备数组
int f[N][25];
int depth[N];

// bfs 预处理
void bfs(int root) {
    queue<int> q;
    q.push(root);
    for (int i=1;i<=N-1;++i) { // 节点编号不一定小于等于 n
        depth[i]=inf;
    }
    depth[root]=1;
    depth[0]=0; // 0 表示跳出了根节点，出界
    while (!q.empty()) {
        int curr=q.front();
        q.pop();
        for (int i=h[curr];i;i=ne[i]) { // 枚举每一条边
            if (depth[e[i]]==inf) { // 还没搜过
                depth[e[i]]=depth[curr]+1; // 更新 depth
                q.push(e[i]); // 入队
                f[e[i]][0]=curr; // 下一个点跳一层就是自己
                for (int j=1;j<=20;++j) { // 更新 f 数组
                    f[e[i]][j]=f[f[e[i]][j-1]][j-1]; // 更新的是下一个点，不是 curr
                }
            }
        }
    }
}

// lca
int lca(int x,int y) {
    // 使 x 的深度大于 y 的深度
    if (depth[x]<depth[y]) swap(x,y);
    // 跳到同一层
    for (int j=20;j>=0;--j) {
        if (depth[f[x][j]]>=depth[y]) {
            x=f[x][j];
        }
    }
    if (x==y) return x; // 两个点相同，直接返回
    for (int j=20;j>=0;--j) {
        // 等于，则为公共祖先，但不一定最近
        // 不等于，则不是公共祖先，还可以往上跳
        // 使其无限接近最近公共祖先，直至到达最近公共祖先的下一层
        if (f[x][j]!=f[y][j]) {
            x=f[x][j];
            y=f[y][j];
        }
    }
    // 此时，往上面走一层就是最近公共祖先
    return f[x][0]; // 2^0 = 1 步
}

int main() {
    scanf("%d",&n);
    int root=0;
    for (int i=1;i<=n;++i) {
        scanf("%d %d",&a,&b);
        if (b==-1) {
            root=a;
            continue;
        }
        add(a,b);
        add(b,a);
    }
    bfs(root);
    scanf("%d",&m);
    while (m--) {
        scanf("%d %d",&a,&b);
        int res=lca(a,b);
        if (res==a) res=1;
        else if (res==b) res=2;
        else res=0;
        printf("%d\n",res);
    }
    return 0;
}