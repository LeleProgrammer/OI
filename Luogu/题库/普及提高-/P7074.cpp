#include <bits/stdc++.h>

#define int long long
#define inf -1000000000000000000LL
#define max3(a,b,c) max(a,max(b,c))

using namespace std;

const int N=1005;

int n,m;
int a[N][N];
int f[N][N][2];

signed main() {
    scanf("%lld %lld",&n,&m);
    for (int i=1;i<=n;++i) {
        for (int j=1;j<=m;++j) {
            scanf("%lld",&a[i][j]);
        }
    }
    for (int i=0;i<=N-1;++i) {
        for (int j=0;j<=N-1;++j) {
            f[i][j][0]=f[i][j][1]=inf;
        }
    }
    f[1][1][0]=f[1][1][1]=a[1][1];
    for (int j=1;j<=m;++j) {
        for (int i=1;i<=n;++i) {
            if (i==1 && j==1) continue;
            for (int k=0;k<=1;++k) {
                f[i][j][k]=max3(f[i][j][k],f[i][j-1][k]+a[i][j],f[i][j-1][k^1]+a[i][j]);
            }
        }
        for (int i=1;i<=n;++i) {
            if (i==1 && j==1) continue;
            f[i][j][0]=max(f[i][j][0],f[i-1][j][0]+a[i][j]);
        }
        for (int i=n;i;--i) {
            if (i==1 && j==1) continue;
            f[i][j][1]=max(f[i][j][1],f[i+1][j][1]+a[i][j]);
        }
    }
    printf("%lld",max(f[n][m][0],f[n][m][1]));
    return 0;
}