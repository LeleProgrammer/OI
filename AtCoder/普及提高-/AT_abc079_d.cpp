#include <bits/stdc++.h>
using namespace std;

const int N=15;
const int M=105;
const int H=205;

typedef pair<int,int> pii;

int n,m;
int c[N][N];
int e[M],w[M],ne[M],h[N],tot;
int a[H][H];
int dis[N][N];
priority_queue<pii> q;
int ans;

void add(int a,int b,int c) {
    e[tot]=b,w[tot]=c,ne[tot]=h[a],h[a]=tot++;
}

void dijkstra(int s) {
    while (!q.empty()) q.pop();
    memset(dis[s],0x3f,sizeof(dis[s]));
    q.push({0,s});
    dis[s][s]=0;
    while (!q.empty()) {
        auto tp=q.top(); q.pop();
        int u=tp.second;
        for (int i=h[u];~i;i=ne[i]) {
            if (dis[s][e[i]]>dis[s][u]+w[i]) {
                dis[s][e[i]]=dis[s][u]+w[i];
                q.push({dis[s][e[i]],e[i]});
            }
        }
    }
}

int main() {
    memset(h,-1,sizeof(h));
    scanf("%d %d",&n,&m);
    for (int i=0;i<=9;++i) {
        for (int j=0;j<=9;++j) {
            scanf("%d",&c[i][j]);
            add(i,j,c[i][j]);
        }
    }
    for (int i=1;i<=n;++i) {
        for (int j=1;j<=m;++j) {
            scanf("%d",&a[i][j]);
        }
    }
    for (int i=0;i<=9;++i) {
        dijkstra(i);
    }
    for (int i=1;i<=n;++i) {
        for (int j=1;j<=m;++j) {
            if (!~a[i][j]) continue;
            ans+=dis[a[i][j]][1];
        }
    }
    printf("%d\n",ans);
    return 0;
}