#include <bits/stdc++.h>
using namespace std;

const int MAXR=1e3;
const int MAXC=1e3;

int r,c;
int arr[MAXR][MAXC];

/*
in:
4 5
1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0

dp:
1 0 1 0 0
1 0 1 1 1
1 1 1 2 2
1 0 0 1 0

out:
4
*/

/*
dp
dp[i][j] 表示到arr[i][j]中的最大正方形边长
arr[i][j]是0则忽略
状态转移方程推导：
1. [i-1][j]的范围
2. [i][j-1]的范围
3. [i-1][j-1]的范围
又因为正方形的扩展，两边必须保持1:1的长度
所以用min，用max会出各种畸形图案
所以状态转移方程：
dp[i][j]=min(dp[i-1][j],dp[i][j-1],dp[i-1][j-1])+1
*/
int dp[MAXR][MAXC];

void read() {
    scanf("%d %d",&r,&c);
    for (int i=1;i<=r;++i) {
        for (int j=1;j<=c;++j) {
            scanf("%d",&arr[i][j]);
            if (arr[i][j]==1) {
                dp[i][j]=1;
            }
        }
    }
}

int main() {
    read();
    int maxx=0;
    for (int i=1;i<=r;++i) {
        for (int j=1;j<=c;++j) {
            if (arr[i][j]==1) {
                dp[i][j]=min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1])+1;
            }
            if (dp[i][j]>maxx) {
                maxx=dp[i][j];
            }
        }
    }
    printf("%d",maxx);
    return 0;
}