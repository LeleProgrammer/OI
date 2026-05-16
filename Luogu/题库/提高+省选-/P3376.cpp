#include <bits/stdc++.h>

#define int long long
#define inf 1000000000000000000LL

using namespace std;

const int N=205;
const int M=10005;

int n,m,S,T;
int e[M],ne[M],f[M],h[N],tot;
int layer[N],cur[N]; // layer: 分层 ; cur: 弧优化，表示枚举出边的时候从哪一条边开始

void add(int a,int b,int c) {
    e[tot]=b,f[tot]=c,ne[tot]=h[a],h[a]=tot++;
    e[tot]=a,f[tot]=0,ne[tot]=h[b],h[b]=tot++;
}

bool bfs() {
    queue<int> q;
    memset(layer,-1,sizeof(layer)); // 初始未分层
    q.push(S); layer[S]=0; cur[S]=h[S]; // 添加起点，并设置分层，初始化弧优化数组
    while (!q.empty()) {
        int u=q.front(); q.pop();
        for (int i=h[u];~i;i=ne[i]) {
            if (layer[e[i]]==-1 && f[i]>=1) { // 还未搜过，并且可以增广
                layer[e[i]]=layer[u]+1; // 赋予层数
                cur[e[i]]=h[e[i]]; // 初始化弧优化数组
                if (e[i]==T) return true; // 搜到终点，直接退出，因为其它还没有搜到的点的层数一定比终点深，所以无法从其它点走到终点的，没必要再搜了
                q.push(e[i]); // 入队
            }
        }
    }
    return false;
}

int dfs(int u,int limit) {
    if (u==T) return limit; // 搜到终点，limit 即为结果
    int k=0; // 从这个点出发，添加的流量
    for (int i=cur[u];~i && k<limit;i=ne[i]) { // 弧优化，搜过的就不用再搜了，如果枚举边的时候所添加的流量已经达到或超过最大流量，就不能再添加流量了
        cur[u]=i; // 更新弧优化数组
        if (layer[e[i]]==layer[u]+1 && f[i]>=1) { // 不能出现环，并且能够被增广
            int ret=dfs(e[i],min(f[i],limit-k)); // 下一个点能够添加的最大流量，不能超过边的容量，也不能超过目前该点的限制
            if (!ret) layer[e[i]]=-1; // 不能添加，下一个点就没有用了
            f[i]-=ret,f[i^1]+=ret,k+=ret; // 更新残留网络
        }
    }
    return k;
}


int dinic() {
    int ans=0,k;
    while (bfs()) while (k=dfs(S,inf)) ans+=k; // 只要还有增广路径就继续搜
    return ans;
}

signed main() {
    memset(h,-1,sizeof(h));
    scanf("%lld %lld %lld %lld",&n,&m,&S,&T);
    while (m--) {
        int a,b,c;
        scanf("%lld %lld %lld",&a,&b,&c);
        add(a,b,c);
    }
    printf("%lld",dinic());
    return 0;
}