#include <bits/stdc++.h>
using namespace std;

const int N=100005;
const int M=200005;

int n,m;
int e[M],ne[M],h[N],tot;
int f[N];
int in[N];

void add(int a,int b) {
    e[tot]=b,ne[tot]=h[a],h[a]=tot++;
}

int dfs(int u) {
    if (~f[u]) return f[u];
    if (!~h[u]) return f[u]=1;
    f[u]=0;
    for (int i=h[u];~i;i=ne[i]) {
        f[u]+=dfs(e[i]);
    }
    return f[u];
}

int main() {
    memset(h,-1,sizeof(h));
    memset(f,-1,sizeof(f));
    scanf("%d %d",&n,&m);
    while (m--) {
        int a,b;
        scanf("%d %d",&a,&b);
        add(a,b);
        in[b]++;
    }
    int root,ans=0;
    for (root=1;root<=n;++root) if (~h[root] && !in[root]) ans+=dfs(root);
    printf("%d",ans);
    return 0;
}