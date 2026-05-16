#include <bits/stdc++.h>
using namespace std;

const int N=1005;
const int M=20005;

int n,m,S,T;
int e[M],ne[M],f[M],h[N],tot; // 前向星维护残留网络
bool vis[N]; // bfs 点是否查询过
int previous[N]; // 记录路径
int minn[N]; // 增广路径上的最小值

// 维护的是残留网络
void add(int a,int b,int c) {
    e[tot]=b,f[tot]=c,ne[tot]=h[a],h[a]=tot++;
    e[tot]=a,f[tot]=0,ne[tot]=h[b],h[b]=tot++;
}

bool bfs() {
    queue<int> q;
    q.push(S);
    memset(vis,0,sizeof(vis));
    memset(previous,0,sizeof(previous));
    minn[S]=0x3f3f3f3f; // 源点流量默认是无穷的
    while (!q.empty()) {
        int u=q.front(); q.pop();
        vis[u]=true;
        for (int i=h[u];~i;i=ne[i]) {
            if (f[i]>0 && !vis[e[i]]) { // 增广路径的定义，边必须是正数
                previous[e[i]]=i; // 记录路径
                minn[e[i]]=min(minn[u],f[i]);
                if (e[i]==T) return true; // 到达终点就退出
                q.push(e[i]);
            }
        }
    }
    return false;
}

int EK() {
    int ans=0;
    while (bfs()) { // 只要还有增广路径
        ans+=minn[T]; // 增加流量
        for (int i=T;i!=S;i=e[previous[i]^1]) { //  更新残留网络
            f[previous[i]]-=minn[T];
            f[previous[i]^1]+=minn[T];
        }
    }
    return ans;
}

int main() {
    memset(h,-1,sizeof(h));
    scanf("%d %d %d %d",&n,&m,&S,&T);
    while (m--) {
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        add(a,b,c);
    }
    printf("%d",EK());
    return 0;
}