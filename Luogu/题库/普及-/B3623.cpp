#include <bits/stdc++.h>
using namespace std;

int n,k;
int arr[15];
bool vis[15];

void dfs(int pos) {
    if (pos>k) {
        for (int i=1;i<=k;++i) {
            printf("%d ",arr[i]);
        }
        printf("\n");
        return;
    }
    for (int i=1;i<=n;++i) {
        if (!vis[i]) {
            vis[i]=true;
            arr[pos]=i;
            dfs(pos+1);
            vis[i]=false;
        }
    }
}

int main() {
    memset(vis,false,sizeof(vis));
    scanf("%d %d",&n,&k);
    dfs(1);
    return 0;
}