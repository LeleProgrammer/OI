#include <bits/stdc++.h>
using namespace std;

int n;
int a[100005][3];
int dp[100005][3];

int main() {
    scanf("%d",&n);
    for (int i=1;i<=n;++i) {
        scanf("%d %d %d",&a[i][0],&a[i][1],&a[i][2]);
    }
    memset(dp,0,sizeof(dp));
    dp[1][0]=a[1][0];
    dp[1][1]=a[1][1];
    dp[1][2]=a[1][2];
    for (int i=1;i<=n;++i) {
        for (int j=0;j<=2;++j) {
            for (int p=0;p<=2;++p) {
                if (p==j) continue;
                dp[i][j]=max(dp[i-1][p]+a[i][j],dp[i][j]);
            }
        }
    }
    printf("%d\n",max(max(dp[n][0],dp[n][1]),dp[n][2]));
    return 0;
}