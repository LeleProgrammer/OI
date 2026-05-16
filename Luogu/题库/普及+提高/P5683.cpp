#include <bits/stdc++.h>
using namespace std;

const int N=3005;
const int M=6005;
const int inf=2e9;

typedef pair<int,int> pii;

int n,m,s1,t1,s2,t2;
int e[M],ne[M],h[N],tot;
int dis[3][N];
int ans;
priority_queue< pii,vector<pii>,greater<pii> > q;

void add(int a,int b) {
    e[tot]=b,ne[tot]=h[a],h[a]=tot++;
}

void dijkstra(int s,int k) {
    for (int i=0;i<N;++i) dis[k][i]=inf;
    q.push({dis[k][s]=0,s});
    while (!q.empty()) {
        auto tp=q.top(); q.pop();
        int u=tp.second;
        for (int i=h[u];~i;i=ne[i]) {
            if (dis[k][e[i]]>dis[k][u]+1) {
                dis[k][e[i]]=dis[k][u]+1;
                q.push({dis[k][e[i]],e[i]});
            }
        }
    }
}

int main() {
    memset(h,-1,sizeof(h));
    scanf("%d %d",&n,&m);
    for (int i=1;i<=m;++i) {
        int a,b;
        scanf("%d %d",&a,&b);
        add(a,b);
        add(b,a);
    }
    scanf("%d %d %d %d",&s1,&t1,&s2,&t2);
    dijkstra(1,0);
    dijkstra(s1,1);
    dijkstra(s2,2);
    ans=-inf;
    for (int i=1;i<=n;++i) {
        int d1=dis[0][i];
        int d2=dis[1][i];
        int d3=dis[2][i];
        if (d1+d2>t1 || d1+d3>t2) continue;
        ans=max(ans,m-(d1+d2+d3));
    }
    if (ans==-inf) printf("-1");
    else printf("%d",ans);
    return 0;
}