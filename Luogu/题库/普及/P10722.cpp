#include <bits/stdc++.h>
using namespace std;

const int N=100005;

int n,q;
int a[N],t[N];
vector<int> son[N];

void dfs(int u) {
    a[u]^=t[u];
    for (int i=0;i<son[u].size();++i) {
        t[son[u][i]]^=t[u];
        dfs(son[u][i]);
    }
}

int main() {
    scanf("%d",&n);
    for (int i=2;i<=n;++i) {
        int k;
        scanf("%d",&k);
        son[k].push_back(i);
    }
    for (int i=1;i<=n;++i) {
        scanf("%1d",&a[i]);
    }
    scanf("%d",&q);
    while (q--) {
        int u;
        scanf("%d",&u);
        t[u]^=1;
    }
    dfs(1);
    for (int i=1;i<=n;++i) printf("%d",a[i]);
    return 0;
}