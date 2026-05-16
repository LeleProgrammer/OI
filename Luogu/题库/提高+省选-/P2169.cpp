#include <bits/stdc++.h>
using namespace std;

const int N=200005;
const int M=1000005;

typedef pair<int,int> pii;

int n,m;
int a,b,c;
int e[M],ne[M],w[M],h[N],tot;
int dfn[N],low[N],ts;
int id[N],scc;
int e2[M],ne2[M],w2[M],h2[N],tot2;
bool flag[N];
stack<int> stk;
bool check[N];
int dis[N];
priority_queue< pii,vector<pii>,greater<pii> > q;

void add(int a,int b,int c) {
    e[tot]=b,w[tot]=c,ne[tot]=h[a],h[a]=tot++;
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
    if (low[u]==dfn[u]) {
        scc++;
        int y;
        do {
            y=stk.top(); stk.pop(); flag[y]=false;
            id[y]=scc;
        } while (y!=u);
    }
}

void dijkstra(int s) {
    memset(dis,0x3f,sizeof(dis));
    memset(check,0,sizeof(check));
    dis[s]=0;
    q.push(make_pair(dis[s],s));
    while (!q.empty()) {
        auto tp=q.top(); q.pop();
        int curr=tp.second;
        check[curr]=true;
        for (int i=h2[curr];~i;i=ne2[i]) {
            if (dis[e2[i]]>dis[curr]+w2[i] && !check[e2[i]]) {
                dis[e2[i]]=dis[curr]+w2[i];
                q.push(make_pair(dis[e2[i]],e2[i]));
            }
        }
    }
}

int main() {
    memset(h,-1,sizeof(h));
    scanf("%d %d",&n,&m);
    while (m--) {
        scanf("%d %d %d",&a,&b,&c);
        add(a,b,c);
    }
    for (int i=1;i<=n;++i) {
        if (!dfn[i]) {
            tarjan(i);
        }
    }
    memset(h2,-1,sizeof(h2));
    for (int i=1;i<=n;++i) {
        for (int j=h[i];~j;j=ne[j]) {
            if (id[i]!=id[e[j]]) {
                add2(id[i],id[e[j]],w[j]);
            }
        }
    }
    dijkstra(id[1]);
    printf("%d",dis[id[n]]);
    return 0;
}