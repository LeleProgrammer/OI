#include <bits/stdc++.h>
using namespace std;

int V,n;
int dp[35][20005];
int volumn[35];

int main() {
    scanf("%d",&V);
    scanf("%d",&n);
    for (int i=1;i<=n;++i) {
        scanf("%d",&volumn[i]);
    }
    int maxx=0;
    memset(dp,0,sizeof(dp));
    for (int i=1;i<=n;++i) {
        for (int j=0;j<=V;++j) {
            if (j-volumn[i]>=0) {
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-volumn[i]]+volumn[i]);
            } else {
                dp[i][j]=dp[i-1][j];
            }
            maxx=max(dp[i][j],maxx);
        }
    }
    printf("%d",V-maxx);
    return 0;
}