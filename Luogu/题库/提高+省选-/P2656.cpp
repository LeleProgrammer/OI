#include <bits/stdc++.h>
using namespace std;

const int N=80005;
const int M=200005;

int n,m,s;
int e[M],ne[M],w[M],h[N],tot;
double p[M];
int e2[M],ne2[M],w2[M],h2[N],tot2;
int dfn[N],low[N],ts;
int id[N],scc;
bool flag[N];
int cost[N];
stack<int> stk;
bool check[N];
queue<int> q;
int dis[N];

void add(int a,int b,int c,double d) {
    e[tot]=b,w[tot]=c,p[tot]=d,ne[tot]=h[a],h[a]=tot++;
}

void add2(int a,int b,int c) {
    e2[tot2]=b,w2[tot2]=c,ne2[tot2]=h2[a],h2[a]=tot2++;
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
    dis[s]=cost[s];
    q.push(s);
    check[s]=true;
    while (!q.empty()) {
        int u=q.front(); q.pop(); check[u]=false;
        for (int i=h2[u];~i;i=ne2[i]) {
            if (dis[e2[i]]<dis[u]+w2[i]+cost[e2[i]]) {
                dis[e2[i]]=dis[u]+w2[i]+cost[e2[i]];
                if (!check[e2[i]]) {
                    q.push(e2[i]);
                }
            }
        }
    }
}

int main() {
    memset(h,-1,sizeof(h));
    memset(h2,-1,sizeof(h2));
    scanf("%d %d",&n,&m);
    while (m--) {
        int a,b,c; double d;
        scanf("%d %d %d %lf",&a,&b,&c,&d);
        add(a,b,c,d);
    }
    scanf("%d",&s);
    for (int i=1;i<=n;++i) {
        if (!dfn[i]) {
            tarjan(i);
        }
    }
    for (int i=1;i<=n;++i) {
        for (int j=h[i];~j;j=ne[j]) {
            if (id[i]==id[e[j]]) {
                while (w[j]) {
                    cost[id[i]]+=w[j];
                    w[j]=w[j]*(int(p[j]*10))/10;
                }
            }
        }
    }
    for (int i=1;i<=n;++i) {
        for (int j=h[i];~j;j=ne[j]) {
            if (id[i]!=id[e[j]]) {
                add2(id[i],id[e[j]],w[j]);
            }
        }
    }
    spfa(id[s]);
    int ans=0;
    for (int i=1;i<=scc;++i) {
        ans=max(ans,dis[i]);
    }
    printf("%d",ans);
    return 0;
}