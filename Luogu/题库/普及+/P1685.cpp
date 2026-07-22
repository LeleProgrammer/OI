#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N=10005;
const int M=50005;
const int mod=10000;

int n,m,S,T,t0;
int e[M],ne[M],h[N],w[M],tot;
int in[N];
int f[N],g[N];
queue<int> q;

void add(int a,int b,int c) {
    e[tot]=b,w[tot]=c,ne[tot]=h[a],h[a]=tot++;
}

void topu() {
    for (int i=1;i<=n;++i) {
        if (!in[i]) {
            q.push(i);
        }
    }
    g[S]=1;
    while (!q.empty()) {
        int u=q.front(); q.pop();
        for (int i=h[u];~i;i=ne[i]) {
            g[e[i]]+=g[u];
            g[e[i]]%=mod;
            f[e[i]]+=f[u]+(w[i]*g[u]);
            f[e[i]]%=mod;
            in[e[i]]--;
            if (!in[e[i]]) q.push(e[i]);
        }
    }
}

signed main() {
    memset(h,-1,sizeof(h));
    scanf("%lld %lld %lld %lld %lld",&n,&m,&S,&T,&t0);
    while (m--) {
        int a,b,c;
        scanf("%lld %lld %lld",&a,&b,&c);
        add(a,b,c);
        in[b]++;
    }
    topu();
    int total=f[T];
    total+=(g[T]-1)*t0;
    total%=mod;
    printf("%lld",total);
    return 0;
}