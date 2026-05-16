#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N=505;

int n;
int f[N][N];

signed main() {
    scanf("%lld",&n);
    f[0][0]=1;
    for (int i=1;i<=n;++i) {
        for (int j=1;j<=i;++j) {
            for (int k=0;k<j;++k) {
                f[i][j]+=f[i-j][k];
            }
        }
    }
    int ans=0;
    for (int i=1;i<=n-1;++i) {
        ans+=f[n][i];
    }
    printf("%lld",ans);
    return 0;
}