#include <bits/stdc++.h>

#define int long long

using namespace std;

int n;
int arr[1005];
int pre[1005];
int sum[1005][1005];
int dp[1005][1005];

signed main() {
	scanf("%lld",&n);
	memset(dp,0x3f,sizeof dp);
	for (int i=1;i<=n;++i) {
		scanf("%lld",arr+i);
		dp[i][i]=0;
	}
	pre[0]=0;
	for (int i=1;i<=n;++i) {
		pre[i]=pre[i-1]+arr[i];
	}
	for (int i=1;i<=n;++i) {
		for (int j=i;j<=n;++j) {
			sum[i][j]=pre[j]-pre[i-1];
		}
	}
	for (int i=1;i<=n;++i) {
		for (int j=1;j+i-1<=n;++j) {
			for (int k=j;k<=j+i-2;++k) {
				dp[j][j+i-1]=min(dp[j][j+i-1],dp[j][k]+dp[k+1][j+i-1]+sum[j][j+i-1]);
			}
		}
	}
	printf("%lld\n",dp[1][n]);
	return 0;
}