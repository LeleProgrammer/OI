#include <bits/stdc++.h>
using namespace std;

const int N=10005;
const int M=50005;

int n,m,u;
int e[M],ne[M],h[N],tot;
int dfn[N],low[N],ts;
int id[N],scc;
bool flag[N];
stack<int> stk;
int in[N],out[N];
int ans1,ans2;

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
        } else if (flag[e[i]]) low[u]=min(low[u],dfn[e[i]]);
    }
    if (dfn[u]==low[u]) {
        scc++;
        int y;
        do {
            y=stk.top(); stk.pop(); flag[y]=false;
            id[y]=scc;
        } while (y!=u);
    }
}

int main() {
    scanf("%d",&n);
    for (int i=1;i<=n;++i) {
        while (true) {
            scanf("%d",&u);
            if (!u) break;
            add(i,u);
        }
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
                in[id[e[j]]]++;
            }
        }
    }
    for (int i=1;i<=scc;++i) {
        if (!in[i]) {
            ans1++;
        }
        if (!out[i]) {
            ans2++;
        }
    }
    printf("%d\n%d",ans1,scc==1?0:max(ans1,ans2));
    return 0;
}