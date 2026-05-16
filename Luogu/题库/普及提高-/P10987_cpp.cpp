#include <bits/stdc++.h>
using namespace std;

const int N=1005;
const int inf=2e9;

int n,a,b;
int w[N];
int f[N][N];
int ans=-inf;

int main() {
    scanf("%d %d %d",&n,&a,&b);
    for (int i=1;i<=n;++i) scanf("%d",&w[i]);
    for (int i=0;i<=a;++i) for (int j=0;j<=b;++j) f[i][j]=-inf;
    f[0][0]=0;
    for (int i=1;i<=n;++i) {
        for (int j=a;~j;--j) {
            for (int k=b;~k;--k) {
                if (j-w[i]>=0) f[j][k]=max(f[j][k],f[j-w[i]][k]+w[i]);
                if (k-w[i]>=0) f[j][k]=max(f[j][k],f[j][k-w[i]]+w[i]);
                ans=max(ans,f[j][k]);
            }
        }
    }
    printf("%d",ans);
    return 0;
}