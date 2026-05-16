#include <bits/stdc++.h>

#define int long long

using namespace std;

int n,m;
int dp[35][35];

signed main() {
    scanf("%lld %lld",&n,&m);
    memset(dp,0,sizeof(dp));
    dp[1][1]=1;
    for (int i=1;i<=n;++i) {
        for (int j=1;j<=m;++j) {
            if (i==1 && j==1) continue;
            if (i%2==0 && j%2==0) continue;
            dp[i][j]=dp[i-1][j]+dp[i][j-1];
        }
    }
    printf("%d",dp[n][m]);
    return 0;
}