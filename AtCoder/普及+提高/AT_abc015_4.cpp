#include <bits/stdc++.h>
using namespace std;

int w,n,k;
int a[55],b[55];
int dp[55][10005];

int main() {
    scanf("%d %d %d",&w,&n,&k);
    for (int i=1;i<=n;++i) {
        scanf("%d %d",a+i,b+i);
    }
    memset(dp,0,sizeof(dp));
    for (int i=1;i<=n;++i) {
        for (int j=k;j>=1;--j) {
            for (int p=w;p>=a[i];--p) {
                dp[j][p]=max(dp[j][p],dp[j-1][p-a[i]]+b[i]);
            }
        }
    }
    printf("%d",dp[k][w]);
    return 0;
}