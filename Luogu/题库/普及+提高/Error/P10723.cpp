#include <bits/stdc++.h>
using namespace std;

const int N=100005;
const int M=200005;
const int inf=1e6;

int n;
int arr[N];
int e[M],ne[M],h[N],tot;
int f[N][2];
int root;

void add(int a,int b) {
    e[tot]=b,ne[tot]=h[a],h[a]=tot++;
}

void dfs(int u,int fa) {
    f[u][arr[u]]=0;
    if (arr[u]^1) f[u][arr[u]^1]=1;
    bool ok=arr[u];
    for (int i=h[u];~i;i=ne[i]) {
        if (e[i]==fa) continue;
        dfs(e[i],u);
        f[u][1]=min(f[u][1],min(f[e[i]][0],f[e[i]][1])+arr[u]);
        if (f[e[i]][0]==inf) ok=false;
    }
    if (!ok) f[u][0]=inf;
}

int main() {
    memset(h,-1,sizeof(h));
    scanf("%d",&n);
    for (int i=1;i<=n;++i) {
        scanf("%d",&arr[i]);
    }
    for (int i=1;i<=n-1;++i) {
        int a,b;
        scanf("%d %d",&a,&b);
        add(a,b);
        add(b,a);
    }
    for (int i=0;i<N;++i) f[i][1]=inf;
    for (root=1;root<=n;++root) if (arr[root]) break;
    if (root>n) {
        printf("0");
        return 0;
    }
    dfs(root,0);
    cout<<root<<endl;
    for (int i=1;i<=n;++i) {
        printf("f[%d][%d]=%d,f[%d][%d]=%d\n",i,0,f[i][0],i,1,f[i][1]);
    }
    printf("%d",f[root][1]);
    return 0;
}