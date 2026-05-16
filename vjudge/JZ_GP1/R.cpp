#include <bits/stdc++.h>
using namespace std;

const int N=20005;
const int M=200005;

int n,m;
int a,b,c;
int e[M],ne[M],w[M],h[N],tot;
int color[N]; // 染色法判定二分图

void add(int a,int b,int c) {
    e[tot]=b,w[tot]=c,ne[tot]=h[a],h[a]=tot++;
}

bool dfs(int curr,int c,int limit) {
    color[curr]=c;
    for (int i=h[curr];~i;i=ne[i]) {
        if (w[i]<=limit) continue; // 小于等于 mid 的边一律不找
        if (!color[e[i]]) {
            if (!dfs(e[i],3-c,limit)) return false; // 之后的填色出现冲突
        } else if (color[e[i]]==c) return false; // 下一步填色出现冲突
    }
    return true;
}

bool check(int mid) { // 保留大于 mid 的边
    memset(color,0,sizeof(color));
    bool ok=true;
    for (int i=1;i<=n && ok;++i) {
        if (!color[i]) {
            ok&=dfs(i,1,mid);
        }
    }
    return ok;
}

int main() {
    memset(h,-1,sizeof(h));
    scanf("%d %d",&n,&m);
    while (m--) {
        scanf("%d %d %d",&a,&b,&c);
        add(a,b,c); add(b,a,c); // 无向图加双向边
    }
    int l=0,r=1000000000;
    while (l<r) { // 二分答案
        int mid=l+r>>1;
        if (check(mid)) r=mid; // 还是一个二分图
        else l=mid+1; // 不是二分图了
    }
    printf("%d",r); // 搜到最后 r 就是答案
    return 0;
}