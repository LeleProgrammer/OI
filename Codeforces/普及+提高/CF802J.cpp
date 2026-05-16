#include <bits/stdc++.h>
using namespace std;

int n,u,v,c,ans=0;
vector< pair<int,int> > tree[105];
bool vis[105];

void dfs(int node,int summ) {
    ans=max(ans,summ);
    for (int i=0;i<tree[node].size();++i) {
        if (!vis[tree[node][i].first]) {
            vis[tree[node][i].first]=true;
            dfs(tree[node][i].first,summ+tree[node][i].second);
            vis[tree[node][i].first]=false;
        }
    }
}

int main() {
    scanf("%d",&n);
    for (int i=1;i<=n-1;++i) {
        scanf("%d %d %d",&u,&v,&c);
        tree[u].push_back(make_pair(v,c));
        tree[v].push_back(make_pair(u,c));
    }
    memset(vis,false,sizeof(vis));
    vis[0]=true;
    dfs(0,0);
    printf("%d",ans);
    return 0;
}