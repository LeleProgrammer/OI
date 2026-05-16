#include <bits/stdc++.h>
using namespace std;

int n;
int dp[5005];

int main() {
    scanf("%d",&n);
    dp[0]=0;
    for (int i=1;i<=n;++i) {
        dp[i]=0x3f3f3f3f;
        if (i-3>=0) {
            dp[i]=min(dp[i],dp[i-3]+1);
        }
        if (i-5>=0) {
            dp[i]=min(dp[i],dp[i-5]+1);
        }
    }
    printf("%d",dp[n]!=0x3f3f3f3f?dp[n]:-1);
    return 0;
}