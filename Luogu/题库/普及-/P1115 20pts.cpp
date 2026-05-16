#include <bits/stdc++.h>
using namespace std;

int n;
int arr[100005];
int s[100005];
int dp[100005];

int zdh(int l,int r) { // 从下标l到下标r的最大子段和
    return s[r]-s[l];
}

int main() {
    scanf("%d",&n);
    scanf("%d",arr);
    s[0]=arr[0];
    for (int i=1;i<n;++i) {
        scanf("%d",arr+i);
        s[i]=arr[i]+s[i-1];
    }
    // dp
    int result=-0x7fffffff;
    dp[0]=s[0]; // dp[i] 表示下标0到下标i的地方最大子段和
    for (int i=1;i<n;++i) {
        dp[i]=dp[i-1];
        for (int j=0;j<i;++j) {
            dp[i]=max(dp[i],zdh(j,i)); // 状态转移
        }
        result=max(result,dp[i]);
    }
    printf("%d",result);
    return 0;
}