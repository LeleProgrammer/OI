#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N=500005;
const int M=500005;

typedef pair<int,int> pii;

int n,m,s,p;
int e[M],ne[M],h[N],tot;
int e2[M],ne2[M],h2[N],tot2;
int a[N];
bool dest[N];
int dfn[N],low[N],ts;
bool flag[N];
int cost[N];
int scc;
int id[N];
stack<int> stk;
int dis[N];
bool check[N];
queue<int> q;

void add(int a,int b) {
    e[tot]=b,ne[tot]=h[a],h[a]=tot++;
}

void add2(int a,int b) {
    e2[tot2]=b,ne2[tot2]=h2[a],h2[a]=tot2++;
}

void tarjan(int u) {
    dfn[u]=low[u]=++ts;
    flag[u]=true;
    stk.push(u);
    for (int i=h[u];~i;i=ne[i]) {
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
        } while (y!=u);
    }
}

void spfa(int s) {
    memset(dis,-1,sizeof(dis));
    memset(check,0,sizeof(check));
    check[s]=true;
    dis[s]=cost[s];
    q.push(s);
    while (!q.empty()) {
        int u=q.front(); q.pop(); check[u]=false;
        for (int i=h2[u];~i;i=ne2[i]) {
            if (dis[e2[i]]<dis[u]+cost[e2[i]]) {
                dis[e2[i]]=dis[u]+cost[e2[i]];
                if (!check[e2[i]]) {
                    q.push(e2[i]);
                }
            }
        }
    }
}

signed main() {
    memset(h,-1,sizeof(h));
    memset(h2,-1,sizeof(h2));
    scanf("%lld %lld",&n,&m);
    while (m--) {
        int u,v;
        scanf("%lld %lld",&u,&v);
        add(u,v);
    }
    for (int i=1;i<=n;++i) scanf("%lld",&a[i]);
    scanf("%lld %lld",&s,&p);
    while (p--) {
        int v;
        scanf("%lld",&v);
        dest[v]=true;
    }
    for (int i=1;i<=n;++i) {
        if (!dfn[i]) {
            tarjan(i);
        }
    }
    for (int i=1;i<=n;++i) cost[id[i]]+=a[i];
    for (int i=1;i<=n;++i) {
        for (int j=h[i];~j;j=ne[j]) {
            if (id[e[j]]!=id[i]) {
                add2(id[i],id[e[j]]);
            }
        }
    }
    spfa(id[s]);
    int ans=0;
    for (int i=1;i<=n;++i) {
        if (dest[i]) ans=max(ans,dis[id[i]]);
    }
    printf("%lld",ans);
    return 0;
}