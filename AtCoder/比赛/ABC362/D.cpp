#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N=200005;
const int M=400005;
const int inf=1e18;

typedef pair<int,int> pii;

int n,m;
int arr[N];
int e[M],ne[M],w[M],h[N],tot;
int dis[N];
priority_queue< pii,vector<pii>,greater<pii> > q;

void add(int a,int b,int c) {
    e[tot]=b,w[tot]=c,ne[tot]=h[a],h[a]=tot++;
}

void dijkstra() {
    for (int i=0;i<N;++i) dis[i]=inf;
    q.push({dis[1]=arr[1],1});
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
    scanf("%lld %lld",&n,&m);
    for (int i=1;i<=n;++i) h[i]=-1;
    for (int i=1;i<=n;++i) scanf("%lld",&arr[i]);
    while (m--) {
        int a,b,c;
        scanf("%lld %lld %lld",&a,&b,&c);
        add(a,b,c+arr[b]);
        add(b,a,c+arr[a]);
    }
    dijkstra();
    for (int i=2;i<=n;++i) {
        printf("%lld ",dis[i]);
    }
    return 0;
}