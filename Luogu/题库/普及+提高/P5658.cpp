#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N=500005;
const int M=1000005;

int n;
int e[M],ne[M],h[N],tot;
int a[N],fa[N];
int f[N],ex[N],last[N];

void add(int a,int b) {
    e[tot]=b,ne[tot]=h[a],h[a]=tot++;
}

void dfs(int u) {
    if (a[u]==0) {
        if (a[fa[u]]==0) ex[u]=1;
        else ex[u]=ex[fa[u]]+1;
        last[u]=u;
        f[u]=f[fa[u]];
    } else {
        if (!last[u]) {
            f[u]=f[fa[u]];
            ex[u]=0;
            last[u]=0;
        } else {
            f[u]=f[fa[u]]+ex[last[u]];
            ex[u]=ex[last[u]];
            last[u]=last[fa[last[u]]];
        }
    }
    for (int i=h[u];~i;i=ne[i]) {
        last[e[i]]=last[u];
        dfs(e[i]);
    }
}

signed main() {
    memset(h,-1,sizeof(h));
    scanf("%lld",&n);
    for (int i=1;i<=n;++i) {
        char c;
        scanf(" %c",&c);
        if (c=='(') a[i]=0;
        else a[i]=1;
    }
    for (int i=2;i<=n;++i) {
        int k;
        scanf("%d",&k);
        add(k,i);
        fa[i]=k;
    }
    dfs(1);
    int ans=0;
    for (int i=1;i<=n;++i) {
        ans^=(i*f[i]);
    }
    printf("%lld",ans);
    return 0;
}