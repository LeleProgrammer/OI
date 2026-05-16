#include <bits/stdc++.h>
using namespace std;

const int N=20;
const int inf=2e9;

int n;
int g[N][N];
int f[1<<N][N];

int main() {
    scanf("%d",&n);
    for (int i=0;i<=n-1;++i) {
        for (int j=0;j<=n-1;++j) {
            scanf("%d",&g[i][j]);
        }
    }
    for (int i=0;i<(1<<N);++i) {
        for (int j=0;j<N;++j) {
            f[i][j]=inf;
        }
    }
    f[1][0]=0;
    for (int i=1;i<=(1<<n)-1;++i) {
        for (int j=0;j<=n-1;++j) {
            if (!((i>>j)&1)) continue;
            for (int k=0;k<=n-1;++k) {
                if (!((i>>k)&1)) continue;
                f[i][j]=min(f[i][j],f[i-(1<<j)][k]+g[k][j]);
            }
        }
    }
    printf("%lld",f[(1<<n)-1][n-1]);
    return 0;
}