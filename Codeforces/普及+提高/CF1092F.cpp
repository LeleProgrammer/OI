#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N=200005;
const int M=400005;

int n;
int a[N];
int e[M],ne[M],h[N],tot;
int d[N],sz[N],sum;
int f[N];

void add(int a,int b) {
    e[tot]=b,ne[tot]=h[a],h[a]=tot++;
}

void dfs1(int u,int fa) {
    sz[u]=a[u];
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
        f[e[i]]=f[u]-sz[e[i]]+(sum-sz[e[i]]);
        dfs2(e[i],u);
    }
}

signed main() {
    memset(h,-1,sizeof(h));
    scanf("%lld",&n);
    for (int i=1;i<=n;++i) {
        scanf("%lld",&a[i]);
        sum+=a[i];
    }
    for (int i=1;i<=n-1;++i) {
        int u,v;
        scanf("%lld %lld",&u,&v);
        add(u,v);
        add(v,u);
    }
    dfs1(1,0);
    for (int i=1;i<=n;++i) f[1]+=d[i]*a[i];
    dfs2(1,0);
    int ans=0;
    for (int i=1;i<=n;++i) ans=max(ans,f[i]);
    printf("%lld",ans);
    return 0;
}