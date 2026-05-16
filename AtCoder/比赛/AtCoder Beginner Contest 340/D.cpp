#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N=200005;
const int M=400005;

typedef pair<int,int> pii;

int n;
int a[N],b[N],x[N];
int e[M],ne[M],h[N],w[M],tot;
priority_queue< pii,vector<pii>,greater<pii> > q;
int dis[N];
bool check[N];

void add(int a,int b,int c) {
    e[tot]=b,w[tot]=c,ne[tot]=h[a],h[a]=tot++;
}

void dijkstra() {
    for (int i=1;i<=n;++i) dis[i]=1000000000000000000LL;
    memset(check,0,sizeof(check));
    dis[1]=0;
    q.push(make_pair(dis[1],1));
    while (!q.empty()) {
        auto tp=q.top(); q.pop();
        int u=tp.second;
        check[u]=true;
        for (int i=h[u];~i;i=ne[i]) {
            if (dis[e[i]]>dis[u]+w[i] && !check[e[i]]) {
                dis[e[i]]=dis[u]+w[i];
                q.push(make_pair(dis[e[i]],e[i]));
            }
        }
    }
}

signed main() {
    memset(h,-1,sizeof(h));
    scanf("%lld",&n);
    for (int i=1;i<=n-1;++i) {
        scanf("%lld %lld %lld",a+i,b+i,x+i);
    }
    for (int i=1;i<=n-1;++i) {
        add(i,i+1,a[i]);
        add(i,x[i],b[i]);
    }
    dijkstra();
    printf("%lld",dis[n]);
    return 0;
}