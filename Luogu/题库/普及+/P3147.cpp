#include <bits/stdc++.h>
using namespace std;

int dp[105][270000];
int result=0;
int n;

int main() {
    scanf("%d",&n);
    for (int i=1;i<=n;++i) {
        int val;
        scanf("%d",&val);
        dp[val][i]=i+1;
    }
    for (int i=2;i<=(int)(log2(262144)+40);++i) {
        for (int j=1;j<=n;++j) {
            if (!dp[i][j]) {
                dp[i][j]=dp[i-1][dp[i-1][j]];
            }
            result=dp[i][j]?i:result;
        }
    }
    printf("%d",result);
    return 0;
}