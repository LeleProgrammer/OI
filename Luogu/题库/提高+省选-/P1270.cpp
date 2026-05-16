// TLE 80 pts:
// #include <bits/stdc++.h>
// using namespace std;

// const int N=1005;
// const int M=5005;
// const int K=6005;
// const int inf=2e7;

// int n;
// int e[M],ne[M],h[N],w[M],tot,idx;
// int arr[N];
// int root;
// int f[N][K];
// int sz[N];

// void add(int a,int b,int c) {
//     e[tot]=b,w[tot]=c,ne[tot]=h[a],h[a]=tot++;
// }

// void dfs1(int fa) {
//     int u=++idx;
//     int a,b;
//     scanf("%d %d",&a,&b); a<<=1;
//     add(fa,u,a);
//     arr[u]=b;
//     if (!b) dfs1(u),dfs1(u);
// }

// void dfs(int u) {
//     for (int i=0;i<=n;++i) f[u][i]=-inf;
//     f[u][0]=0;
//     if (!~h[u]) {
//         for (int i=1;i<=arr[u];++i) {
//             for (int j=i*5;j<=i*5+4;++j) {
//                 f[u][j]=i;
//             }
//         }
//         return;
//     }
//     for (int i=h[u];~i;i=ne[i]) {
//         dfs(e[i]);
//         for (int j=n;j>=w[i];--j) {
//             for (int k=0;k<=j-w[i];++k) {
//                 f[u][j]=max(f[u][j],f[u][j-k-w[i]]+f[e[i]][k]);
//             }
//         }
//     }
//     // for (int i=0;i<=n;++i) {
//     //     printf("%d ",f[u][i]);
//     // }
//     // putchar(10);
// }

// int main() {
//     memset(h,-1,sizeof(h));
//     scanf("%d",&n);
//     root=++idx;
//     dfs1(root);
//     dfs(root);
//     int ans=0;
//     for (int i=1;i<=n-1;++i) {
//         ans=max(ans,f[root][i]);
//     }
//     printf("%d",ans);
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

const int N=1005;
const int M=5005;
const int K=6005;
const int P=2005;
const int inf=2e7;

int n;
int e[M],ne[M],h[N],w[M],tot,idx;
int arr[N];
int root;
int f[N][P];
int sz[N];

void add(int a,int b,int c) {
    e[tot]=b,w[tot]=c,ne[tot]=h[a],h[a]=tot++;
}

void dfs1(int fa) {
    int u=++idx;
    int a,b;
    scanf("%d %d",&a,&b); a<<=1;
    add(fa,u,a);
    arr[u]=b;
    if (!b) dfs1(u),dfs1(u);
}

void dfs(int u) {
    for (int i=0;i<=P-1;++i) f[u][i]=inf;
    f[u][0]=0;
    if (!~h[u]) {
        for (int i=1;i<=arr[u];++i) {
            f[u][i]=i*5;
        }
        sz[u]=arr[u];
        return;
    }
    for (int i=h[u];~i;i=ne[i]) {
        dfs(e[i]);
        sz[u]+=sz[e[i]];
        for (int j=sz[u];j;--j) {
            for (int k=0;k<=j;++k) {
                f[u][j]=min(f[u][j],f[u][j-k]+f[e[i]][k]+w[i]);
            }
        }
    }
    // printf("%d %d: ",w[h[u]],w[ne[h[u]]]);
    // for (int i=0;i<=sz[u];++i) {
    //     printf("%d ",f[u][i]);
    // }
    // putchar(10);
}

int main() {
    memset(h,-1,sizeof(h));
    scanf("%d",&n);
    root=++idx;
    dfs1(root);
    dfs(root);
    for (int i=P-1;i;--i) {
        if (f[root][i]>=n) continue;
        printf("%d",i);
        return 0;
    }
    return 0;
}