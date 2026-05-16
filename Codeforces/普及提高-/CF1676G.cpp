#include <bits/stdc++.h>
using namespace std;

const int N=4005;

typedef pair<int,int> pii;

int T,n;
char a[N];
vector<int> son[N];
bool f[N];

pii dfs(int u) {
    int black=0,white=0;
    if (a[u]=='W') white++;
    else black++;
    for (int s:son[u]) {
        auto k=dfs(s);
        black+=k.first;
        white+=k.second;
    }
    f[u]=black==white;
    return {black,white};
}

int main() {
    scanf("%d",&T);
    while (T--) {
        scanf("%d",&n);
        for (int i=1;i<=n;++i) son[i].clear();
        for (int i=2;i<=n;++i) {
            int u;
            scanf("%d",&u);
            son[u].push_back(i);
        }
        for (int i=1;i<=n;++i) {
            scanf(" %c",&a[i]);
        }
        dfs(1);
        int ans=0;
        for (int i=1;i<=n;++i) ans+=f[i];
        printf("%d\n",ans);
    }
    return 0;
}