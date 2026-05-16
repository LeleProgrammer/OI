#include <bits/stdc++.h>

#define int long long
#define inf 1000000000000000000

using namespace std;

const int N=50005;
const int M=505;

int n,m;
int a[M];
int b[N];
int f[N*2];

signed main() {
    scanf("%lld %lld",&n,&m);
    for (int i=1;i<=m;++i) scanf("%lld",a+i);
    for (int i=1;i<=n;++i) scanf("%lld",b+i);
    for (int i=1;i<=n*2;++i) f[i]=-inf;
    f[1]=b[1];
    for (int i=2;i<=n*2;++i) {
        for (int j=1;j<=m;++j) {
            if (i-a[j]>=1 && i-a[j]<=n) {
                f[i]=max(f[i],f[i-a[j]]+b[i]);
            }
        }
    }
    int ans=-inf;
    for (int i=n+1;i<=2*n;++i) ans=max(ans,f[i]);
    printf("%lld",ans);
    return 0;
}