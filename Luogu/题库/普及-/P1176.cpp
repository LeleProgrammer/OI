#include <bits/stdc++.h>
using namespace std;

int n,m;
bool stones[1005][1005];
int dp[1005][1005]; // dp

int main() {
    scanf("%d %d",&n,&m); // input
    memset(stones,false,sizeof(stones)); // init
    memset(dp,0,sizeof(dp)); // init
    int tmpx,tmpy;
    for (int i=0;i<m;++i) {
        scanf("%d %d",&tmpx,&tmpy); // input
        stones[tmpx][tmpy]=true;
    }
    // 动态规划
    // 状态转移方程 dp[i][j]=dp[i-1][j]+dp[i][j-1]+1
    dp[1][1]=1;
    stones[1][1]=true; // 并非障碍物 表示初始位置不需要再遍历
    for (int i=1;i<=n;++i) {
        for (int j=1;j<=n;++j) {
            if (stones[i][j]) {
                continue;
            }
            dp[i][j]=dp[i-1][j]+dp[i][j-1]; // 状态转移
            dp[i][j]%=100003;
        }
    }
    printf("%d",dp[n][n]);
    return 0;
}