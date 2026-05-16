#include <bits/stdc++.h>
using namespace std;

int n,m;
int dp[10005];
int arr[105];

int main() {
    scanf("%d %d",&n,&m);
    for (int i=1;i<=n;++i) {
        scanf("%d",&arr[i]);
    }
    memset(dp,0,sizeof(dp));
    for (int i=1;i<=n;++i) {
        for (int j=m;j>=1;--j) {
            if (j==arr[i]) {
                dp[j]++;
            } else if (j>arr[i]) {
                dp[j]+=dp[j-arr[i]];
            }
        }
    }
    printf("%d",dp[m]);
    return 0;
}