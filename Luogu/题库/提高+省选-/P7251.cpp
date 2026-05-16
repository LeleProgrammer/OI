#include <bits/stdc++.h>
using namespace std;

const int N=100005;
const int M=300005;

typedef pair<int,int> pii;

int n,m;
int e[M],ne[M],h[N],tot;
int id[N],scc;
int dfn[N],low[N],ts;
bool flag[N];
stack<int> stk;
vector<int> sccs[N];
int in[N],out[N];
vector<pii> edges;

void add(int a,int b) {
    e[tot]=b,ne[tot]=h[a],h[a]=tot++;
}

void tarjan(int u) {
    dfn[u]=low[u]=++ts;
    stk.push(u);
    flag[u]=true;
    for (int i=h[u];~i;i=ne[i]) {
        if (!dfn[e[i]]) {
            tarjan(e[i]);
            low[u]=min(low[u],low[e[i]]);
        } else if (flag[e[i]]) {
            low[u]=min(low[u],dfn[e[i]]);
        }
    }
    if (dfn[u]==low[u]) {
        int y;
        scc++;
        do {
            y=stk.top(); stk.pop(); flag[y]=false;
            id[y]=scc;
            sccs[scc].push_back(y);
        } while (u!=y);
    }
}

int main() {
    memset(h,-1,sizeof(h));
    scanf("%d %d",&n,&m);
    while (m--) {
        int a,b;
        scanf("%d %d",&a,&b);
        add(a,b);
        edges.push_back({a,b});
    }
    for (int i=1;i<=n;++i) {
        if (!dfn[i]) tarjan(i);
    }
    for (auto edge:edges) {
        int from=edge.first;
        int to=edge.second;
        if (id[from]!=id[to]) {
            in[id[to]]++;
            out[id[from]]++;
        }
    }
    if (scc==1) {
        printf("%d\n%d",n,0);
    } else {
        int in_zero=0,out_zero=0,ans1=0,ans2=0;
        for (int i=1;i<=scc;++i) {
            if (!in[i]) in_zero++;
            if (!out[i]) out_zero++;
            ans1=max(ans1,(int)sccs[i].size());
        }
        ans2=max(in_zero,out_zero);
        printf("%d\n%d",ans1,ans2);
    }
    return 0;
}