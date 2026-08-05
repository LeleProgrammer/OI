#include <bits/stdc++.h>
using namespace std;

int n;
int h[405],c[405],a[405];

int dp[405][40005];

int res=0;

int main() {
    scanf("%d",&n);
    for (int i=1;i<=n;++i) {
        scanf("%d %d %d",h+i,a+i,c+i);
    }
    memset(dp,0,sizeof(dp));
    for (int i=1;i<=n;++i) {
        for (int k=0;k<=c[i];++k) {
            for (int j=h[i]*k;j<=a[i];++j) {
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-h[i]*k]+h[i]*k);
                res=max(res,dp[i][j]);
            }
        }
    }
    printf("%d",res);
    return 0;
}