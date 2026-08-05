#include <bits/stdc++.h>
using namespace std;

const int N=10005;
const int M=50005;

int n,m,a,b;
int e[M],ne[M],h[N],tot;
int dfn[N],low[N],ts;
int id[N],sz[N],scc;
stack<int> stk;
bool flag[N];
int out[N];
int ans;

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
        } while (y!=u);
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
    for (int i=1;i<=n;++i) {
        for (int j=h[i];j;j=ne[j]) {
            if (id[i]!=id[e[j]]) {
                out[id[i]]++;
            }
        }
    }
    int zero=0;
    for (int i=1;i<=scc;++i) {
        if (!out[i]) {
            zero++;
            if (zero==2) {
                ans=0;
                break;
            }
            ans+=sz[i];
        }
    }
    printf("%d",ans);
    return 0;
}