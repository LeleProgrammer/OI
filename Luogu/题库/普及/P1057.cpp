#include <bits/stdc++.h>
using namespace std;

int n,m; // n位同学 传球m次
int dp[35][35]; // dp array

/*
分析
传球可以向左右两位同学其中一个
设1234四人
1<-->2<-->3<-->4 且 1<-->4
1 -- 2
:    :
3 -- 4
dp[i][j]表示第i次传球，球可能出现在第j位同学的情况数量
模拟n=3 m=3时dp数组：
i=0, 1 0 0
i=1, 0 1 1
i=2, 2 1 1
i=3, 2 3 3
所以最终答案为2
j取值时变化：
i=3,
dp_past=dp[i-1]
j=-, dp 2 1 1 dp_past 2 1 1 
j=1, dp 0 3 3 dp_past 2 1 1
j=2, dp 1 2 4 dp_past 2 1 1
j=3, dp 2 3 3 dp_past 2 1 1
所以，需要创建一个dp_past来辅助状态转移
状态转移方程：
dp[i][j]=dp[i][j]-dp_past[i][j] 把球传出去，自己减掉
dp[i][j+1]=dp[i][j+1]+dp_past[i][j] 右边的同学加上去
dp[i][j-1]=dp[i][j-1]+dp_past[i][j] 左边的同学加上去
新的思路：
dp[i][j]=dp[i-1][j-1]+dp[i-1][j+1]
这次这位同学的球是上次左右两位同学球之和
i=3
j=1, dp 0 0 0 last_dp 2 1 1 dp 2 0 0
j=2, dp 2 0 0 last_dp 2 1 1 dp 2 3 0
j=3, dp 2 3 0 last_dp 2 1 1 dp 2 3 3
*/

int main() {
    scanf("%d %d",&n,&m); // 输入n和m
    // 初始化dp
    memset(dp,0,sizeof(dp));
    dp[0][1]=1; // 第0次传球，即初始值
    int left,right; // 左边同学 右边同学
    for (int i=1;i<=m;++i) { // 传球次数i
        for (int j=1;j<=n;++j) { // 处理第j位同学的球
            if (j==1) { // 左边特判
                left=dp[i-1][n];
            } else {
                left=dp[i-1][j-1];
            }
            if (j==n) { // 右边特判
                right=dp[i-1][1];
            } else {
                right=dp[i-1][j+1];
            }
            dp[i][j]=left+right; // 状态转移
        }
    }
    // for (int i=1;i<=m;++i) {
    //     for (int j=1;j<=n;++j) {
    //         printf("%d ",dp[i][j]); // test test
    //     }
    //     printf("\n");
    // }
    printf("%d",dp[m][1]); // 输出
    return 0;
}