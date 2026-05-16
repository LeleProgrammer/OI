#include <bits/stdc++.h>
using namespace std;

int dp[1000005];

int n;

int main() {
    scanf("%d",&n);
    memset(dp,0,sizeof(dp));
    dp[0]=1;
    for (int i=4;i<=5;++i) {
        for (int j=i;j<=n;++j) {
            dp[j]+=dp[j-i];
        }
    }
    printf("%d",dp[n]);
    return 0;
}