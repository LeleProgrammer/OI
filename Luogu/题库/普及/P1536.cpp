#include <bits/stdc++.h>
using namespace std;

int n,m,u,v;

int p[1005];

int find(int x) {
    if (p[x]!=x) return p[x]=find(p[x]);
    return p[x];
}

int main() {
    while (true) {
        scanf("%d",&n);
        if (!n) break;
        scanf("%d",&m);
        for (int i=1;i<=n;++i) p[i]=i;
        while (m--) {
            scanf("%d %d",&u,&v);
            p[find(u)]=find(v);
        }
        // 祖先即自己的点，说明没有与其它点相连（最原先的祖先除外，所以-1）
        int ans=-1;
        for (int i=1;i<=n;++i) if (p[i]==i) ans++;
        printf("%d\n",ans);
    }
    return 0;
}