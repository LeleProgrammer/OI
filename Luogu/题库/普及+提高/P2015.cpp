#include <bits/stdc++.h>
using namespace std;

int n,q,u,v,w;
int tree[105][105];
vector<int> G[105];
int f[105][105];
int root;

void dfs(int pos,int from) {
    f[pos][0]=0;
    if (G[pos].size()==1) return; // leaf
    vector<int> available;
    for (int i=0;i<G[pos].size();++i) {
        if (G[pos][i]!=from) dfs(G[pos][i],pos),available.push_back(G[pos][i]);
    }
    f[pos][1]=max(tree[pos][available[0]],tree[pos][available[1]]);
    for (int i=2;i<=q;++i) { // stay
        for (int l=0,r=i-l;r>=0;++l,--r) { // l for left, r for right
            if (l==0) f[pos][i]=max(f[pos][i],f[available[1]][r-1]+tree[pos][available[1]]);
            else if (r==0) f[pos][i]=max(f[pos][i],f[available[0]][l-1]+tree[pos][available[0]]);
            else f[pos][i]=max(f[pos][i],f[available[0]][l-1]+tree[pos][available[0]]+f[available[1]][r-1]+tree[pos][available[1]]);
        }
    }
}

int main() {
    scanf("%d %d",&n,&q);
    for (int i=1;i<=n-1;++i) {
        scanf("%d %d %d",&u,&v,&w);
        tree[u][v]=w;
        tree[v][u]=w;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    memset(f,0,sizeof(f));
    dfs(1,-0x3f);
    printf("%d",f[1][q]);
    return 0;
}