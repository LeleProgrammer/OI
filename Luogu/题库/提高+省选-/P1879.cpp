#include <bits/stdc++.h>

#define mod 100000000
#define int long long

using namespace std;

int m,n;
int field[15];
int in;
int result=0;

// dp[i][j] 前i行，状态为j
int dp[15][8193];

// 状态是否可行
bool ok[8193];

signed main() {
    scanf("%lld %lld",&m,&n);
    // 读入并压缩状态
    for (int i=1;i<=m;++i) {
        field[i]=0;
        for (int j=1;j<=n;++j) {
            scanf("%lld",&in);
            field[i]=(field[i]<<1)+in;
        }
    }
    // 构建表示状态是否可行的数组（左右没有1相邻）
    for (int i=0;i<=(1<<n)-1;++i) {
        if ((!(i&(i>>1))) && (!(i&(i<<1)))) {
            ok[i]=true;
        } else {
            ok[i]=false;
        }
    }
    // dp数组填充0
    memset(dp,0,sizeof(dp));
    // 第一行的状态初始化
    for (int i=0;i<=(1<<n)-1;++i) {
        // 状态可行（左右没有1相邻，且可以是1的地方是1，不可以是1的地方不是1）
        if (ok[i] && ((field[1]&i)==i)) {
            dp[1][i]=1;
        }
    }
    // 第二行及后面的状态转移
    for (int i=2;i<=m;++i) {
        // 此状态
        for (int j=0;j<=(1<<n)-1;++j) {
            // 状态可行
            if ((j&field[i])==j && ok[j]) {
                // 上一行的状态
                for (int p=0;p<=(1<<n)-1;++p) {
                    // 状态可行（可以是1的地方是1，不可以是1的地方不是1，左右没有1相邻，上下没有1相邻）
                    if ((p&field[i-1])==p && ok[p] && (!(j&p))) {
                        // 状态转移
                        dp[i][j]+=dp[i-1][p];
                        dp[i][j]%=mod;
                    }
                }
            }
        }
    }
    // 最后一行的各种状态统计出来了
    // 最后要把最后一行的这些状态加在一起
    for (int i=0;i<=(1<<n)-1;++i) {
        result+=dp[m][i];
        result%=mod;
    }
    printf("%lld",result);
    return 0;
}