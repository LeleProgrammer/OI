#include <bits/stdc++.h>
using namespace std;

const int N=1505;
const int M=3005;

int n;
int e[M],ne[M],h[N],tot;
int f[N][2];
bool vis[N];

void add(int a,int b) {
    e[tot]=b,ne[tot]=h[a],h[a]=tot++;
}

void dfs(int u) {
    vis[u]=true;
    f[u][0]=0;
    f[u][1]=1;
    if (!~h[u]) return;
    for (int i=h[u];~i;i=ne[i]) {
        if (vis[e[i]]) continue;
        dfs(e[i]);
        f[u][0]+=f[e[i]][1];
        f[u][1]+=min(f[e[i]][0],f[e[i]][1]);
    }
}

int main() {
    memset(h,-1,sizeof(h));
    scanf("%d",&n);
    for (int i=1;i<=n;++i) {
        int v;
        scanf("%d",&v); v++;
        int k;
        scanf("%d",&k);
        for (int j=1;j<=k;++j) {
            int p;
            scanf("%d",&p); p++;
            add(v,p);
            add(p,v);
        }
    }
    dfs(1);
    printf("%d",min(f[1][0],f[1][1]));
    return 0;
}