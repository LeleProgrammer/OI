#include <bits/stdc++.h>
using namespace std;

const int N=600005;
const int M=1200005;

typedef pair<int,int> pii;

int n,m;
int e[M],ne[M],h[N],tot;
int dfn[N],low[N],ts;
int id[N],dcc;
int dis[N];
stack<int> stk;

void add(int a,int b) {
    e[tot]=b,ne[tot]=h[a],h[a]=tot++;
}

void tarjan(int u,int from) {
    dfn[u]=low[u]=++ts;
    stk.push(u);
    for (int i=h[u];~i;i=ne[i]) {
        if (!dfn[e[i]]) {
            tarjan(e[i],i);
            low[u]=min(low[u],low[e[i]]);
        } else if (i!=(from^1)) {
            low[u]=min(low[u],dfn[e[i]]);
        }
    }
    if (dfn[u]==low[u]) {
        dcc++;
        int y;
        do {
            y=stk.top(); stk.pop();
            id[y]=dcc;
        } while (y!=u);
    }
}

void dfs(int u,int fa) {
    for (int i=h[u];~i;i=ne[i]) {
        if (e[i]==fa) continue;
        if (dis[e[i]-n]) continue;
        dis[e[i]-n]=dis[u-n]+1;
        dfs(e[i],u);
    }
}

pii findFarthest(int s) {
    memset(dis,0,sizeof(dis));
    dfs(s,0);
    int maxi=0;
    for (int i=1;i<=dcc;++i) {
        if (dis[i]>dis[maxi]) maxi=i;
    }
    return {maxi,dis[maxi]};
}

int main() {
    memset(h,-1,sizeof(h));
    scanf("%d %d",&n,&m);
    while (m--) {
        int a,b;
        scanf("%d %d",&a,&b);
        add(a,b);
        add(b,a);
    }
    tarjan(1,-1);
    for (int u=1;u<=n;++u) {
        for (int i=h[u];~i;i=ne[i]) {
            if (id[u]!=id[e[i]]) {
                add(id[u]+n,id[e[i]]+n);
            }
        }
    }
    if (dcc==1) {
        puts("0");
        return 0;
    }
    auto p=findFarthest(n+1);
    auto q=findFarthest(p.first+n);
    printf("%d",q.second);
    return 0;
}