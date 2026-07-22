#include <bits/stdc++.h>
using namespace std;

const int MAXN=200000;

int n,l,r;
int arr[MAXN*2+5];
int dp[MAXN*2+5];

int main() {
    scanf("%d %d %d",&n,&l,&r);
    for (int i=1;i<=n+1;++i) {
        scanf("%d",&arr[i]);
    }
    // dp
    // 状态转移方程 dp[i]=max(dp[i-r],dp[i-r+1],...,dp[i-l])+arr[i];
    memset(dp,0,sizeof(dp));
    int maxx;
    dp[1]=arr[1];
    // 枚举格子
    for (int i=2;i<=n;++i) {
        maxx=-0x7fffffff;
        for (int j=(i-r>=1?i-r:1);j<=i-l;++j) {
            //if (dp[j]==-0x7fffffff+1) continue;
            maxx=max(maxx,dp[j]);
        }
        if (maxx==-0x7fffffff) {
            dp[i]=-0x7fffffff;
            continue; // 位置不可能在这
        }
        dp[i]=maxx+arr[i];
    }
    // 有可能跳出图外
    // 记录result
    int result=-0x7fffffff;
    for (int i=n+1;i<=n+r;++i) {
        maxx=-0x7fffffff;
        for (int j=(i-r>=1?i-r:0);j<=i-l;++j) {
            //if (dp[j]==-0x7fffffff+1) continue;
            maxx=max(maxx,dp[j]);
        }
        if (maxx==-0x7fffffff) {
            dp[i]=-0x7fffffff;
            continue; // 位置不可能在这
        }
        dp[i]=maxx+arr[i];
        result=max(result,dp[i]);
    }
    printf("%d\n",result);
    return 0;
}

// 开O2才AC，否则9~12TLE