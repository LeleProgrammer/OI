#include <bits/stdc++.h>
using namespace std;

const int N=16005;
const int M=32005;

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

int main() {
    memset(h,-1,sizeof(h));
    scanf("%d",&n);
    for (int i=1;i<=n;++i) {
        scanf("%d",&a[i]);
    }
    for (int i=1;i<=n-1;++i) {
        int a,b;
        scanf("%d %d",&a,&b);
        add(a,b);
        add(b,a);
    }
    dfs(1,0);
    int ans=-2147483647;
    for (int i=1;i<=n;++i) ans=max(ans,f[i]);
    printf("%d",ans);
    return 0;
}