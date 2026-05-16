#include <bits/stdc++.h>
using namespace std;

int n;
int divide[3];
int dp[4005];

int main() {
    scanf("%d %d %d %d",&n,divide,divide+1,divide+2);
    memset(dp,-0x3f,sizeof(dp));
    dp[0]=0;
    for (int i=0;i<=2;++i) {
        for (int j=divide[i];j<=n;++j) {
            dp[j]=max(dp[j],dp[j-divide[i]]+1);
        }
    }
    printf("%d",dp[n]);
    return 0;
}