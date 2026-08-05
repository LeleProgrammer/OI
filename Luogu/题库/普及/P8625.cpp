#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N=100005;
const int M=200005;

int n;
int a[N];
int e[M],ne[M],h[N],tot;
int f[N];

void add(int a,int b) {
    e[tot]=b,ne[tot]=h[a],h[a]=tot++;
}

int dfs(int u,int fa) {
    for (int i=h[u];~i;i=ne[i]) {
        if (e[i]==fa) continue;
        f[u]=max(f[u],f[u]+dfs(e[i],u));
    }
    f[u]+=a[u];
    return f[u];
}

signed main() {
    memset(h,-1,sizeof(h));
    scanf("%lld",&n);
    for (int i=1;i<=n;++i) scanf("%lld",&a[i]);
    for (int i=1;i<=n-1;++i) {
        int a,b;
        scanf("%lld %lld",&a,&b);
        add(a,b);
        add(b,a);
    }
    dfs(1,0);
    int ans=0;
    for (int i=1;i<=n;++i) ans=max(ans,f[i]);
    printf("%lld",ans);
    return 0;
}