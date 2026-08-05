#include <bits/stdc++.h>

#define inf 0x7ffffff

using namespace std;

int n,m,u,v,w;

vector<int> G[5005];
vector<int> W[5005];

int dis[5005];
bool chk[5005];

int prim() {
    for (int i=1;i<=n;++i) dis[i]=inf;
    memset(chk,false,sizeof(chk));
    int res=0;
    for (int i=1;i<=n;++i) {
        int curr=-1;
        for (int j=1;j<=n;++j) {
            if (!chk[j] && (curr==-1 || dis[j]<dis[curr])) {
                curr=j;
            }
        }
        if (i>=2 && dis[curr]==inf) return inf;
        if (i>=2) res+=dis[curr];
        chk[curr]=true;
        for (int j=0;j<G[curr].size();++j) {
            dis[G[curr][j]]=min(dis[G[curr][j]],W[curr][j]);
        }
    }
    return res;
}

int main() {
    scanf("%d %d",&n,&m);
    for (int i=1;i<=m;++i) {
        scanf("%d %d %d",&u,&v,&w);
        G[u].push_back(v);
        G[v].push_back(u);
        W[u].push_back(w);
        W[v].push_back(w);
    }
    int ans=prim();
    if (ans==inf) printf("orz");
    else printf("%d",ans);
    return 0;
}

// prim