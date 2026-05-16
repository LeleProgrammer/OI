#include <bits/stdc++.h>
using namespace std;

const int N=2005;
const int M=1000005;

int T,tt,n,m;
int e[M],ne[M],h[N],tot;
int color[N];
bool ok;

void add(int a,int b) {
    e[tot]=b,ne[tot]=h[a],h[a]=tot++;
}

void dfs(int u,int fa) {
    if (!ok) return;
    for (int i=h[u];~i && ok;i=ne[i]) {
        if (e[i]==fa) continue;
        if (color[e[i]]==color[u]) {
            ok=false;
            return;
        } else if (color[e[i]]!=-1) continue;
        color[e[i]]=color[u]^1;
        dfs(e[i],u);
    }
}

int main() {
    scanf("%d",&T);
    while (T--) {
        scanf("%d %d",&n,&m);
        for (int i=1;i<=n;++i) h[i]=-1,color[i]=-1;
        tot=0;
        while (m--) {
            int a,b;
            scanf("%d %d",&a,&b);
            add(a,b); add(b,a);
        }
        ok=true;
        for (int i=1;i<=n && ok;++i) {
            if (color[i]==-1) color[i]=0;
            dfs(i,0);
        }
        printf("Scenario #%d:\n",++tt);
        if (!ok) puts("Suspicious bugs found!");
        else puts("No suspicious bugs found!");
    }
    return 0;
}