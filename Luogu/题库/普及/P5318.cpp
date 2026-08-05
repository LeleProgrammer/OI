#include <bits/stdc++.h>
using namespace std;

priority_queue<int,vector<int>,greater<int> > nodes[100005]; // 从1开始，表示下一个点的编号
priority_queue<int,vector<int>,greater<int> > bfs_nodes[100005];

bool dfs_visit[100005];
bool bfs_visit[100005];

queue<int> q;

int n,m;

void dfs(int now) { // 到第now本书（now还未查询）
    if (now>n) {
        return ; // 超出则无法继续
    }
    if (dfs_visit[now]) {
        return ; // 查过了就不查了
    }
    printf("%d ",now); // 查到now了
    dfs_visit[now]=true;
    int node;
    while (!nodes[now].empty()) { // 向下延申
        node=nodes[now].top(); // 获取下一个node
        nodes[now].pop(); // 出队
        dfs(node); // 深搜
    }
    return ;
}

void bfs() {
    q.push(1); // 初始化
    int node;
    while (!q.empty()) {
        node=q.front(); // 获得队首
        q.pop(); // 出队
        if (node>n) {
            continue; // 超出则无法继续
        }
        if (bfs_visit[node]) {
            continue; // 查过了就不查了
        }
        printf("%d ",node);
        bfs_visit[node]=true;
        while (!bfs_nodes[node].empty()) {
            q.push(bfs_nodes[node].top()); // 把下面的结点加到队里
            bfs_nodes[node].pop(); // 出队
            // p.s. 此队非彼队...awa
        }
    }
    return ;
}

void init() {
    scanf("%d %d",&n,&m);
    int from,to;
    for (int i=1;i<=m;++i) {
        scanf("%d %d",&from,&to);
        nodes[from].push(to);
        bfs_nodes[from].push(to);
    }
    memset(dfs_visit,false,sizeof(dfs_visit));
    memset(bfs_visit,false,sizeof(bfs_visit));
    return ;
}

int main() {
    init();
    dfs(1);
    printf("\n");
    bfs();
    return 0;
}