#include <bits/stdc++.h>
using namespace std;

const int N=2000005;
const int M=2000005;

int n,m;
int e[M],ne[M],h[N],tot;
int dfn[N],low[N],ts;
int id[N],scc;
stack<int> stk;
bool flag[N];

void add(int a,int b) {
    e[tot]=b,ne[tot]=h[a],h[a]=tot++;
}

void tarjan(int u) {
    dfn[u]=low[u]=++ts;
    stk.push(u); flag[u]=true;
    for (int i=h[u];~i;i=ne[i]) {
        if (!dfn[e[i]]) {
            tarjan(e[i]);
            low[u]=min(low[u],low[e[i]]);
        } else if (flag[e[i]]) {
            low[u]=min(low[u],dfn[e[i]]);
        }
    }
    if (low[u]==dfn[u]) {
        scc++;
        int y;
        do {
            y=stk.top(); stk.pop(); flag[y]=false;
            id[y]=scc;
        } while (y!=u);
    }
}

int main() {
    memset(h,-1,sizeof(h));
    scanf("%d %d",&n,&m);
    while (m--) {
        int i,a,j,b;
        scanf("%d %d %d %d",&i,&a,&j,&b);
        --i,--j;
        add(i*2+!a,j*2+b); // x 与 !x 相差 1，所以 *2
        add(j*2+!b,i*2+a);
    }
    for (int i=0;i<n*2;++i) { // 枚举所有点
        if (!dfn[i]) {
            tarjan(i);
        }
    }
    bool ok=true;
    for (int i=0;i<n;++i) { // 枚举前一半的点
        if (id[i*2]==id[i*2+1]) {
            ok=false;
            puts("IMPOSSIBLE");
            break;
        }
    }
    if (ok) {
        puts("POSSIBLE");
        for (int i=0;i<n;++i) { // 枚举前一半的点
            // 拓扑排序较大者，也就是 scc 编号较小者
            if (id[i*2]<id[i*2+1]) printf("%d ",0);
            else printf("%d ",1);
        }
    }
    return 0;
}