#include <bits/stdc++.h>
using namespace std;

const int N=10005;
const int M=50005;

int n,m,a,b;
int e[M],ne[M],h[N],tot;
int dfn[N],low[N],ts;
int id[N],scc,sz[N];
stack<int> stk;
bool flag[N];

void add(int a,int b) {
    e[++tot]=b,ne[tot]=h[a],h[a]=tot;
}

void tarjan(int u) {
    dfn[u]=low[u]=++ts;
    stk.push(u); flag[u]=true;
    for (int i=h[u];i;i=ne[i]) {
        if (!dfn[e[i]]) {
            tarjan(e[i]);
            low[u]=min(low[u],low[e[i]]);
        } else if (flag[e[i]]) {
            low[u]=min(low[u],dfn[e[i]]);
        }
    }
    if (dfn[u]==low[u]) {
        scc++;
        int y;
        do {
            y=stk.top(); stk.pop(); flag[y]=false;
            id[y]=scc;
            sz[scc]++;
        } while (u!=y);
    }
}

int main() {
    scanf("%d %d",&n,&m);
    while (m--) {
        scanf("%d %d",&a,&b);
        add(a,b);
    }
    for (int i=1;i<=n;++i) {
        if (!dfn[i]) {
            tarjan(i);
        }
    }
    int ans=0;
    for (int i=1;i<=scc;++i) {
        if (sz[i]>1) ans++;
    }
    printf("%d",ans);
    return 0;
}