#include <bits/stdc++.h>

#define mod 1000000007

using namespace std;

int h,w;
char arr[1005][1005];
int dp[1005][1005];

int main() {
    scanf("%d %d",&h,&w);
    for (int i=1;i<=h;++i) {
        cin>>arr[i]+1;
    }
    memset(dp,0,sizeof(dp));
    dp[1][1]=1;
    for (int i=1;i<=h;++i) {
        for (int j=1;j<=w;++j) {
            if (i==1 && j==1) continue;
            if (arr[i][j]=='.') dp[i][j]=dp[i-1][j]+dp[i][j-1];
            dp[i][j]%=mod;
        }
    }
    printf("%d\n",dp[h][w]);
    return 0;
}