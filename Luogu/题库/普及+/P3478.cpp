#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N=1000005;
const int M=2000005;

int n;
int e[M],ne[M],h[N],tot;
int d[N],sz[N],f[N];

void add(int a,int b) {
    e[tot]=b,ne[tot]=h[a],h[a]=tot++;
}

void dfs1(int u,int fa) {
    sz[u]=1;
    for (int i=h[u];~i;i=ne[i]) {
        if (e[i]==fa) continue;
        d[e[i]]=d[u]+1;
        dfs1(e[i],u);
        sz[u]+=sz[e[i]];
    }
}

void dfs2(int u,int fa) {
    for (int i=h[u];~i;i=ne[i]) {
        if (e[i]==fa) continue;
        f[e[i]]=f[u]-sz[e[i]]+(n-sz[e[i]]);
        dfs2(e[i],u);
    }
}

signed main() {
    memset(h,-1,sizeof(h));
    scanf("%lld",&n);
    for (int i=1;i<=n-1;++i) {
        int a,b;
        scanf("%lld %lld",&a,&b);
        add(a,b);
        add(b,a);
    }
    dfs1(1,0);
    for (int i=1;i<=n;++i) f[1]+=d[i];
    dfs2(1,0);
    int ans=1;
    for (int i=1;i<=n;++i) {
        if (f[i]>f[ans]) ans=i;
    }
    printf("%lld",ans);
    return 0;
}