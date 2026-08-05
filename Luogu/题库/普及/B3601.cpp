#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N=2005;
const int M=2005;
const int inf=9e18;

typedef pair<int,int> pii;

int n,m;
int e[M],ne[M],w[M],h[N],tot;
int dis[N];
priority_queue< pii,vector<pii>,greater<pii> > q;

void add(int a,int b,int c) {
    e[tot]=b,w[tot]=c,ne[tot]=h[a],h[a]=tot++;
}

void dijkstra(int s) {
    for (int i=1;i<=n;++i) dis[i]=inf;
    q.push({dis[s]=0,s});
    while (!q.empty()) {
        auto tp=q.top(); q.pop();
        int u=tp.second;
        for (int i=h[u];~i;i=ne[i]) {
            if (dis[e[i]]>dis[u]+w[i]) {
                dis[e[i]]=dis[u]+w[i];
                q.push({dis[e[i]],e[i]});
            }
        }
    }
}

signed main() {
    memset(h,-1,sizeof(h));
    scanf("%lld %lld",&n,&m);
    while (m--) {
        int a,b,c;
        scanf("%lld %lld %lld",&a,&b,&c);
        add(a,b,c);
    }
    dijkstra(1);
    for (int i=1;i<=n;++i) {
        if (dis[i]==inf) dis[i]=-1;
        printf("%lld ",dis[i]);
    }
    return 0;
}