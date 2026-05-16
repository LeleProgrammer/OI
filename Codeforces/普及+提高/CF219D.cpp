#include <bits/stdc++.h>
using namespace std;

const int N=200005;
const int M=400005;
const int inf=2e9;

int n;
int e[M],ne[M],w[M],h[N],tot;
int f[N],g[N],sz[N];

void add(int a,int b,int c) {
    e[tot]=b,w[tot]=c,ne[tot]=h[a],h[a]=tot++;
}

void dfs1(int u,int fa) {
    for (int i=h[u];~i;i=ne[i]) {
        if (e[i]==fa) continue;
        dfs1(e[i],u);
        g[u]+=g[e[i]]+(w[i]^1);
        sz[u]+=sz[e[i]]+1;
    }
}

void dfs2(int u,int fa) {
    for (int i=h[u];~i;i=ne[i]) {
        if (e[i]==fa) continue;
        if (!w[i]) f[e[i]]=f[u]+1;
        else f[e[i]]=f[u]-1;
        dfs2(e[i],u);
    }
}

int main() {
    memset(h,-1,sizeof(h));
    scanf("%d",&n);
    for (int i=1;i<=n-1;++i) {
        int a,b;
        scanf("%d %d",&a,&b);
        add(a,b,0);
        add(b,a,1);
    }
    dfs1(1,0);
    f[1]=sz[1]-g[1];
    dfs2(1,0);
    // puts("TEST: ");
    // for (int i=1;i<=n;++i) {
    //     printf("f[%d]=%d, g[%d]=%d\n",i,f[i],i,g[i]);
    // }
    int minn=inf;
    for (int i=1;i<=n;++i) minn=min(minn,f[i]);
    printf("%d\n",minn);
    for (int i=1;i<=n;++i) {
        if (f[i]==minn) {
            printf("%d ",i);
        }
    }
    return 0;
}