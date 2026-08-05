#include <bits/stdc++.h>

#define inf 0x3f3f3f3f
#define negative_inf -0x3f3f3f3f

using namespace std;

vector<int> G[1505];
vector<int> W[1505];
int dis[1505];
int n,m,u,v,w;
queue<int> nodes;
queue<int> steps;
int getnode,getstep;

void bfs() {
    while (!nodes.empty()) {
        getnode=nodes.front();
        getstep=steps.front();
        nodes.pop();
        steps.pop();
        if (getstep<=dis[getnode]) continue;
        dis[getnode]=getstep;
        for (int i=0;i<G[getnode].size();++i) {
            nodes.push(G[getnode][i]);
            steps.push(getstep+W[getnode][i]);
        }
    }
}

int main() {
    for (int i=0;i<=1504;++i) {
        dis[i]=negative_inf;
    }
    scanf("%d %d",&n,&m);
    while (m--) {
        scanf("%d %d %d",&u,&v,&w);
        G[u].push_back(v);
        W[u].push_back(w);
    }
    nodes.push(1);
    steps.push(0);
    bfs();
    if (dis[n]==negative_inf) {
        printf("-1");
    } else {
        printf("%d",dis[n]);
    }
    return 0;
}