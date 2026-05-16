#include <bits/stdc++.h>
using namespace std;

int n;
int arr[100005];
int dp[100005];

int main() {
    scanf("%d",&n);
    for (int i=1;i<=n;++i) {
        scanf("%d",&arr[i]);
    }
    dp[1]=0;
    dp[2]=abs(arr[2]-arr[1]);
    for (int i=3;i<=n;++i) {
        dp[i]=min(dp[i-1]+abs(arr[i]-arr[i-1]),dp[i-2]+abs(arr[i]-arr[i-2]));
    }
    printf("%d",dp[n]);
    return 0;
}