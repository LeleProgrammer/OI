#include <bits/stdc++.h>
using namespace std;

const int N=55;
const int M=2505;

int n,m;
int e[M],ne[M],h[N],tot;
int dfn[N],low[N],ts;
int ans;

void add(int a,int b) {
    e[tot]=b,ne[tot]=h[a],h[a]=tot++;
}

void tarjan(int u,int from) {
    dfn[u]=low[u]=++ts;
    for (int i=h[u];~i;i=ne[i]) {
        if (!dfn[e[i]]) {
            tarjan(e[i],i);
            low[u]=min(low[u],low[e[i]]);
            if (low[e[i]]>dfn[u]) ans++;
        } else if (i!=(from^1)) {
            low[u]=min(low[u],dfn[e[i]]);
        }
    }
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
    for (int i=1;i<=n;++i) if (!dfn[i]) tarjan(i,M);
    printf("%d\n",ans);
    return 0;
}