#include <bits/stdc++.h>
using namespace std;

const int K=100001;
const int N=100005;
const int M=2000005;

int T,n;
int w[N],a[N];
int e[M],ne[M],h[N],tot;
int dfn[N],low[N],ts;
bool flag[N];
int id[N],scc;
stack<int> stk;

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
        } while (y!=u);
    }
}

int main() {
    scanf("%d",&T);
    while (T--) {
        memset(h,-1,sizeof(h));
        memset(dfn,0,sizeof(dfn));
        memset(low,0,sizeof(low));
        memset(id,0,sizeof(id));
        scc=0,ts=0,tot=0;
        memset(flag,0,sizeof(flag));
        while (!stk.empty()) stk.pop();
        scanf("%d",&n);
        for (int i=1;i<=n;++i) {
            scanf("%d",&w[i]);
        }
        for (int i=1;i<=n;++i) {
            scanf("%d",&a[i]);
        }
        for (int i=1;i<=K;++i) {
            for (int j=i+i;j<=K;j+=i) {
                add(i,j);
            }
        }
        for (int i=1;i<=n;++i) {
            add(w[i],a[i]);
        }
        for (int i=1;i<=K;++i) {
            if (!dfn[i]) tarjan(i);
        }
        int cnt=0;
        for (int i=1;i<=n;++i) {
            if (id[w[i]]==id[a[i]]) cnt++;
        }
        printf("%d\n",cnt);
    }
    return 0;
}