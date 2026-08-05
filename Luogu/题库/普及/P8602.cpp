#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N=100005;
const int M=200005;

typedef pair<int,int> pii;

int n;
int e[M],ne[M],h[N],w[M],tot;
int dis[N];

void add(int a,int b,int c) {
    e[tot]=b,w[tot]=c,ne[tot]=h[a],h[a]=tot++;
}

void dfs(int u,int fa) {
    for (int i=h[u];~i;i=ne[i]) {
        if (e[i]==fa) continue;
        dis[e[i]]=dis[u]+w[i];
        dfs(e[i],u);
    }
}

pii findFarthest(int s) {
    dis[s]=0;
    dfs(s,0);
    int ans=s;
    for (int i=1;i<=n;++i) {
        if (dis[i]>dis[ans]) ans=i;
    }
    return {ans,dis[ans]};
}

signed main() {
    memset(h,-1,sizeof(h));
    scanf("%lld",&n);
    for (int i=1;i<=n-1;++i) {
        int a,b,c;
        scanf("%lld %lld %lld",&a,&b,&c);
        add(a,b,c);
        add(b,a,c);
    }
    auto a=findFarthest(1);
    auto b=findFarthest(a.first);
    int t=b.second;
    printf("%lld",(1+t)*t/2+t*10);
    return 0;
}