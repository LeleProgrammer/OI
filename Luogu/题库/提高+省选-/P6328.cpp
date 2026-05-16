#include <bits/stdc++.h>
using namespace std;

const int N=1005;
const int M=200005;
const int inf=2e9;

typedef pair<int,int> pii;

int n,m,Q;
int dis[N][N];
vector<int> G[N];
bool flag[N];
priority_queue< pii,vector<pii>,greater<pii> > q;
bitset<N> cnt[N][N];

void add(int a,int b) {
    G[a].push_back(b);
}

void dijkstra(int s) {
    q.push({dis[s][s]=0,s});
    while (!q.empty()) {
        auto tp=q.top(); q.pop();
        int u=tp.second;
        if (flag[u]) continue;
        flag[u]=true;
        for (int v:G[u]) {
            if (dis[s][v]>dis[s][u]+1) {
                dis[s][v]=dis[s][u]+1;
                q.push({dis[s][v],v});
            }
        }
    }
}

int main() {
    scanf("%d %d %d",&n,&m,&Q);
    while (m--) {
        int x,y;
        scanf("%d %d",&x,&y);
        add(x,y); add(y,x);
    }
    for (int i=1;i<=n;++i) {
        for (int j=1;j<=n;++j) {
            dis[i][j]=inf;
            flag[j]=false;
        }
        dijkstra(i);
        for (int j=1;j<=n;++j) {
            if (dis[i][j]==inf) continue;
            cnt[i][dis[i][j]][j]=1;
        }
        for (int j=1;j<=n;++j) {
            cnt[i][j]|=cnt[i][j-1];
        }
    }
    while (Q--) {
        int a;
        scanf("%d",&a);
        bitset<N> ans;
        while (a--) {
            int x,y;
            scanf("%d %d",&x,&y);
            ans|=cnt[x][y];
        }
        printf("%d\n",ans.count());
    }
    return 0;
}