#include <bits/stdc++.h>

#define int long long
#define max3(a,b,c) max(max(a,b),c)
#define inf 0x3f3f3f3f3f3f3f3f

using namespace std;

const int N=105;
const int K=N*(N+1)/2;

int n,k;
int arr[N][N];
int f[N][N][K];

signed main() {
    scanf("%lld %lld",&n,&k);
    for (int i=1;i<=n;++i) {
        for (int j=1;j<=i;++j) {
            scanf("%lld",&arr[i][j]);
        }
    }
    for (int i=1;i<=n;++i) {
        for (int j=0;j<=n;++j) {
            for (int p=0;p<=k;++p) {
                f[i][j][p]=-inf;
            }
        }
    }
    for (int i=1;i<=n;++i) {
        for (int j=1;j<=i;++j) {
            for (int p=0;p<=k;++p) {
                f[i][j][p]=max(f[i-1][j][p],f[i-1][j-1][p])+arr[i][j];
                if (p) f[i][j][p]=max3(f[i][j][p],f[i-1][j][p-1]+arr[i][j]*3,f[i-1][j-1][p-1]+arr[i][j]*3);
            }
        }
    }
    int ans=-inf;
    for (int i=1;i<=n;++i) {
        for (int p=0;p<=k;++p) {
            ans=max(ans,f[n][i][p]);
        }
    }
    printf("%lld",ans);
    return 0;
}