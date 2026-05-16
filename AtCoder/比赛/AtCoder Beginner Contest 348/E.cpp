#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N=100005;
const int M=200005;

int n;
int c[N];
int e[M],ne[M],h[N],tot;
int d[N]; // dis[1,i]
int s[N]; // sum
int s_all; // s[1]+...+s[n]
int f[N]; // f(i)

void add(int a,int b) {
    e[tot]=b,ne[tot]=h[a],h[a]=tot++;
}

void dfs1(int u,int fa) {
    s[u]=c[u];
    for (int i=h[u];~i;i=ne[i]) {
        if (e[i]==fa) continue;
        d[e[i]]=d[u]+1;
        dfs1(e[i],u);
        s[u]+=s[e[i]];
    }
}

void dfs2(int u,int fa) {
    for (int i=h[u];~i;i=ne[i]) {
        if (e[i]==fa) continue;
        f[e[i]]=f[u]-s[e[i]]+s_all-s[e[i]];
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
    for (int i=1;i<=n;++i) {
        scanf("%lld",&c[i]);
        s_all+=c[i];
    }
    dfs1(1,0);
    for (int i=1;i<=n;++i) {
        f[1]=f[1]+(c[i]*d[i]);
    }
    dfs2(1,0);
    int ans=9000000000000000000LL;
    for (int i=1;i<=n;++i) {
        ans=min(ans,f[i]);
    }
    printf("%lld",ans);
    return 0;
}