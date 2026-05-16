#include <bits/stdc++.h>
using namespace std;

int arr[1005][1005];
int dp[1005][1005]; // dp

int main() {
    int r;
    scanf("%d",&r);
    for (int i=1;i<=r;++i) {
        for (int j=1;j<=i;++j) {
            scanf("%d",&(arr[i][j])); // input
        }
    }
    for (int i=0;i<1005;++i) {
        for (int j=0;j<1005;++j) {
            dp[i][j]=-0x7fffffff; // fill
        }
    }
    // 动态规划
    // 状态转移方程 dp[i][j]=max(dp[i-1][j],dp[i-1][j-1])+arr[i][j]
    for (int i=1;i<=r;++i) {
        for (int j=1;j<=i;++j) {
            int left=dp[i-1][j];
            int right=dp[i-1][j-1];
            if (left==-0x7fffffff && right!=-0x7fffffff) {
                dp[i][j]=right+arr[i][j];
            } else if (left!=-0x7fffffff && right==-0x7fffffff) {
                dp[i][j]=left+arr[i][j];
            } else if (left!=-0x7fffffff && right!=-0x7fffffff) {
                dp[i][j]=max(left,right)+arr[i][j];
            } else {
                dp[i][j]=arr[i][j];
            }
        }
    }
    int maxx=-0x7fffffff;
    for (int j=1;j<=r;++j) {
        if (dp[r][j]>maxx) {
            maxx=dp[r][j];
        }
    }
    printf("%d",maxx);
    return 0;
}