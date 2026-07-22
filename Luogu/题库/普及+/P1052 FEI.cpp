#include <bits/stdc++.h>
using namespace std;

const int MAX_INT=0x7fffffff;
const int MAX_N=1000000015;

int l,s,t,m;
bool stones[MAX_N]; // 下标从1开始
int dp[MAX_N]; // dp 下标从1开始

/*
状态转移方程：
dp[i]=min{dp[i-t],dp[i-t+1],dp[i-t+2],...,dp[i-s]}+stones[i]
*/

int main() {
    scanf("%d",&l);
    scanf("%d %d %d",&s,&t,&m);
    memset(stones,false,sizeof(stones));
    int tmp;
    for (int i=0;i<m;++i) {
        scanf("%d",&tmp);
        stones[tmp]=true;
    }
    // dp
    dp[1]=0;
    int minimum;
    int result=MAX_INT;
    for (int i=1;i<=l+t;++i) {
        minimum=MAX_INT;
        for (int j=t;j>=s;--j) {
            if (i-j>=1) {
                if (dp[i-j]<minimum && dp[i-j]!=-1) {
                    minimum=dp[i-j];
                }
            }
        }
        if (minimum=MAX_INT) {
            minimum=-1;
            dp[i]=minimum;
        } else {
            dp[i]=minimum+(stones[i]?1:0);
            if (i>=l) {
                if (dp[i]<result) {
                    result=dp[i];
                }
            }
        }
    }
    printf("%d",result);
    return 0;
}