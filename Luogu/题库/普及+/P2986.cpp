#include <bits/stdc++.h>

#define int long long
#define inf 9000000000000000000LL

using namespace std;

const int N=100005;
const int M=200005;

int n;
int c[N];
int e[M],w[M],ne[M],h[N],tot;
int d[N],s[N];
int f[N];
int sum;

void add(int a,int b,int c) {
    e[tot]=b,w[tot]=c,ne[tot]=h[a],h[a]=tot++;
}

void dfs1(int u,int fa) {
    s[u]=c[u];
    for (int i=h[u];~i;i=ne[i]) {
        if (e[i]==fa) continue;
        d[e[i]]=d[u]+w[i];
        dfs1(e[i],u);
        s[u]+=s[e[i]];
    }
}

void dfs2(int u,int fa) {
    for (int i=h[u];~i;i=ne[i]) {
        if (e[i]==fa) continue;
        f[e[i]]=f[u]-(s[e[i]]*w[i])+((sum-s[e[i]])*w[i]);
        dfs2(e[i],u);
    }
}

signed main() {
    memset(h,-1,sizeof(h));
    scanf("%lld",&n);
    for (int i=1;i<=n;++i) {
        scanf("%lld",&c[i]);
        sum+=c[i];
    }
    for (int i=1;i<=n-1;++i) {
        int a,b,c;
        scanf("%lld %lld %lld",&a,&b,&c);
        add(a,b,c);
        add(b,a,c);
    }
    dfs1(1,0);
    for (int i=1;i<=n;++i) {
        f[1]=f[1]+(c[i]*d[i]);
    }
    dfs2(1,0);
    int ans=inf;
    for (int i=1;i<=n;++i) ans=min(ans,f[i]);
    printf("%lld",ans);
    return 0;
}