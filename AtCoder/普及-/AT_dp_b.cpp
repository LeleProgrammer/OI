#include <bits/stdc++.h>
using namespace std;

int n,k;
int arr[100005];
int dp[100005];

int main() {
    scanf("%d %d",&n,&k);
    for (int i=1;i<=n;++i) {
        scanf("%d",&arr[i]);
    }
    memset(dp,0x3f,sizeof(dp));
    dp[1]=0;
    for (int i=2;i<=n;++i) {
        for (int j=1;j<=k;++j) {
            if (i-j<=0) break;
            dp[i]=min(dp[i-j]+abs(arr[i]-arr[i-j]),dp[i]);
        }
    }
    printf("%d\n",dp[n]);
    return 0;
}