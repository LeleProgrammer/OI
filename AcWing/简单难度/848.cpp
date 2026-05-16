#include <bits/stdc++.h>
using namespace std;

int n,m,u,v;
vector<int> G[100005];
int in[100005];
queue<int> q;
vector<int> res;
int t;

bool topsort() {
    while (!q.empty()) {
        t=q.front();
        res.push_back(t);
        q.pop();
        for (int i=0;i<G[t].size();) {
            in[G[t][i]]--;
            if (in[G[t][i]]==0) q.push(G[t][i]);
            G[t].erase(G[t].begin());
        }
    }
    return res.size()==n;
}

int main() {
    scanf("%d %d",&n,&m);
    for (int i=1;i<=m;++i) {
        scanf("%d %d",&u,&v);
        G[u].push_back(v);
        in[v]++;
    }
    for (int i=1;i<=n;++i) {
        if (in[i]==0) {
            q.push(i);
        }
    }
    if (topsort()) {
        for (int i=0;i<=n-1;++i) {
            printf("%d ",res[i]);
        }
    } else {
        printf("-1");
    }
    return 0;
}