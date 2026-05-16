#include <bits/stdc++.h>
using namespace std;

const int N=155;
const int M=305;
const int inf=2e9;

int n,p;
int e[M],ne[M],h[N],tot;
int sz[N];
int f[N][N];

void add(int a,int b) {
    e[tot]=b,ne[tot]=h[a],h[a]=tot++;
}

void dfs(int u,int fa) {
    sz[u]=1;
    f[u][1]=0;
    for (int i=h[u];~i;i=ne[i]) {
        if (e[i]==fa) continue;
        dfs(e[i],u);
        sz[u]+=sz[e[i]];
        for (int k=sz[u];k;--k) {
            f[u][k]++;
            for (int j=1;j<=sz[e[i]];++j) {
                if (k-j<=0) break;
                f[u][k]=min(f[u][k-j]+f[e[i]][j],f[u][k]);
            }
        }
    }
}

int main() {
    memset(h,-1,sizeof(h));
    scanf("%d %d",&n,&p);
    for (int i=1;i<=n-1;++i) {
        int a,b;
        scanf("%d %d",&a,&b);
        add(a,b);
        add(b,a);
    }
    for (int i=1;i<=n;++i) {
        for (int j=0;j<=n;++j) {
            f[i][j]=inf;
        }
    }
    dfs(1,0);
    for (int i=2;i<=n;++i) f[i][p]++; // 除去 1 号根节点外，其余都要再去除与父节点连接的边
    int ans=inf;
    for (int i=1;i<=n;++i) {
        ans=min(ans,f[i][p]);
    }
    printf("%d",ans);
    return 0;
}

// f[i][j] i 为根节点，包含 j 个节点，删除边的最小数目