#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N=500005;
const int M=1000005;

int n,s;
int e[M],ne[M],w[M],h[N],tot;
int f[N];
int g[N];

void add(int a,int b,int c) {
    e[tot]=b,w[tot]=c,ne[tot]=h[a],h[a]=tot++;
}

void dfs(int u,int fa) {
    int t=0,s=0,cnt=0;
    for (int i=h[u];~i;i=ne[i]) {
        if (e[i]==fa) continue;
        dfs(e[i],u);
        t=max(t,g[e[i]]+w[i]);
        s+=g[e[i]]+w[i];
        f[u]+=f[e[i]];
        cnt++;
    }
    g[u]=t;
    t*=cnt;
    int delta=t-s;
    f[u]+=delta;
}

signed main() {
    memset(h,-1,sizeof(h));
    scanf("%lld %lld",&n,&s);
    for (int i=1;i<=n-1;++i) {
        int a,b,c;
        scanf("%lld %lld %lld",&a,&b,&c);
        add(a,b,c);
        add(b,a,c);
    }
    dfs(s,0);
    printf("%lld",f[s]);
    return 0;
}