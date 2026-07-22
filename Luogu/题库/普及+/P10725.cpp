#include <bits/stdc++.h>
using namespace std;

const int N=100005;
const int M=200005;
const int inf=1e8;

int n;
int arr[N];
int e[M],ne[M],h[N],tot;
int f[N][2];
int g[N];
int p[N];
int q[N];

void add(int a,int b) {
    e[tot]=b,ne[tot]=h[a],h[a]=tot++;
}

void dfs(int u,int fa) {
    f[u][arr[u]]=0;
    for (int i=h[u];~i;i=ne[i]) {
        if (e[i]==fa) continue;
        dfs(e[i],u);
        p[u]=max(p[u],f[u][0]+f[e[i]][1]+1);
        q[u]=max(q[u],f[u][1]+f[e[i]][0]+1);
        f[u][0]=max(f[u][0],f[e[i]][0]+1);
        f[u][1]=max(f[u][1],f[e[i]][1]+1);
        g[u]=max(g[u],f[u][arr[u]^1]);
    }
}

int main() {
    memset(h,-1,sizeof(h));
    scanf("%d",&n);
    for (int i=1;i<=n;++i) {
        scanf("%d",&arr[i]);
    }
    for (int i=1;i<=n-1;++i) {
        int a,b;
        scanf("%d %d",&a,&b);
        add(a,b);
        add(b,a);
    }
    for (int i=0;i<N;++i) {
        f[i][0]=f[i][1]=g[i]=p[i]=q[i]=-inf;
    }
    dfs(1,0);
    int ans=0;
    for (int i=1;i<=n;++i) {
        ans=max(ans,max(g[i],max(p[i],q[i])));
    }
    printf("%d",ans);
    return 0;
}