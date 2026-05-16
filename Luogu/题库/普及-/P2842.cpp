#include <bits/stdc++.h>
using namespace std;

int n,w;
int arr[1005];
int dp[10005];

int main() {
    scanf("%d %d",&n,&w);
    for (int i=1;i<=n;++i) scanf("%d",arr+i);
    memset(dp,0x3f,sizeof(dp));
    dp[0]=0;
    for (int i=1;i<=w;++i) {
        for (int j=1;j<=n;++j) {
            if (i-arr[j]>=0) dp[i]=min(dp[i],dp[i-arr[j]]+1);
        }
    }
    printf("%d",dp[w]);
    return 0;
}