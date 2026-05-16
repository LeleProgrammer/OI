#include <bits/stdc++.h>

#define inf 0x3f3f3f3f

using namespace std;

const int N=3005;
const int M=8005;

int n,p,m,u,v;
int e[M],ne[M],h[N],tot;
int buy[N];
int dfn[N],low[N],ts;
int id[N],scc;
bool flag[N];
int scc_buy[N];
int in[N];
stack<int> stk;
vector<int> scc_nodes[N];
bool fg[N];
bool vis[N];

bool cmp(const int& a,const int& b) {
    return a<b;
}

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
    if (dfn[u]==low[u]) {
        scc++;
        int y;
        do {
            y=stk.top(); stk.pop(); flag[y]=false;
            id[y]=scc;
            scc_nodes[scc].push_back(y);
        } while (y!=u);
    }
}

int dfs(int u) {
    if (vis[u]) return inf;
    vis[u]=true;
    int minn=u;
    for (int i=h[u];~i;i=ne[i]) {
        if (fg[e[i]]) continue;
        minn=min(minn,dfs(e[i]));
    }
    return minn;
}

void dfs2(int u) {
    if (fg[u]) return;
    fg[u]=true;
    for (int i=h[u];~i;i=ne[i]) {
        dfs2(e[i]);
    }
}

int main() {
    memset(h,-1,sizeof(h));
    scanf("%d",&n);
    for (int i=1;i<=n;++i) {
        buy[i]=scc_buy[i]=inf;
    }
    scanf("%d",&p);
    while (p--) {
        scanf("%d %d",&u,&v);
        buy[u]=v;
    }
    scanf("%d",&m);
    while (m--) {
        scanf("%d %d",&u,&v);
        add(u,v);
    }
    for (int i=1;i<=n;++i) if (!dfn[i]) tarjan(i);
    for (int i=1;i<=n;++i) {
        scc_buy[id[i]]=min(scc_buy[id[i]],buy[i]);
    }
    for (int i=1;i<=n;++i) {
        for (int j=h[i];~j;j=ne[j]) {
            if (id[i]!=id[e[j]]) {
                in[id[e[j]]]++;
            }
        }
    }
    for (int i=1;i<=scc;++i) {
        if (scc_buy[i]!=inf) {
            dfs2(scc_nodes[i][0]);
        }
    }
    bool ok=true;
    int ans=0;
    int unok_ans=inf;
    for (int i=1;i<=scc;++i) {
        sort(scc_nodes[i].begin(),scc_nodes[i].end(),cmp);
        if (in[i]==0) {
            if (scc_buy[i]==inf) {
                ok=false;
                memset(vis,0,sizeof(vis));
                unok_ans=min(unok_ans,dfs(scc_nodes[i][0]));
            } else ans+=scc_buy[i];
        }
    }
    if (ok) {
        puts("YES");
        printf("%d",ans);
    } else {
        puts("NO");
        printf("%d",unok_ans);
    }
    return 0;
}