#include <bits/stdc++.h>
using namespace std;

const int N=10005,M=100005;

int n,m,u,v;
int a[N];
int e[M],ne[M],h[N],tot;
int e2[M],ne2[M],h2[N],tot2;
int dfn[N],low[N],ts;
int id[N],sum[N],scc;
int in[N];
int dis[N];
bool flag[N];
stack<int> stk;
queue<int> q;

void add(int a,int b) {
    e[++tot]=b,ne[tot]=h[a],h[a]=tot;
}

void add2(int a,int b) {
    e2[++tot2]=b,ne2[tot2]=h2[a],h2[a]=tot2;
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
            sum[scc]+=a[y];
        } while (u!=y);
    }
}

int topu() {
    int ans=0;
    for (int i=1;i<=scc;++i) {
        if (!in[i]) {
            q.push(i);
            dis[i]=sum[i];
        }
    }
    while (!q.empty()) {
        int curr=q.front(); q.pop();
        for (int i=h2[curr];i;i=ne2[i]) {
            in[e2[i]]--;
            dis[e2[i]]=max(dis[e2[i]],dis[curr]+sum[e2[i]]);
            if (!in[e2[i]]) {
                q.push(e2[i]);
            }
        }
    }
    for (int i=1;i<=scc;++i) {
        ans=max(ans,dis[i]);
    }
    return ans;
}

int main() {
    scanf("%d %d",&n,&m);
    for (int i=1;i<=n;++i) {
        scanf("%d",&a[i]);
    }
    while (m--) {
        scanf("%d %d",&u,&v);
        add(u,v);
    }
    for (int i=1;i<=n;++i) {
        if (!dfn[i]) {
            tarjan(i);
        }
    }
    for (int i=1;i<=n;++i) {
        for (int j=h[i];j;j=ne[j]) {
            if (id[i]!=id[e[j]]) {
                add2(id[i],id[e[j]]);
                in[id[e[j]]]++;
            }
        }
    }
    printf("%d",topu());
    return 0;
}