#include <bits/stdc++.h>
using namespace std;

int n;
int c[505];

int dp[505][505];

int main() {
	scanf("%d",&n);
	memset(dp,0x3f,sizeof dp);
	for (int i=1;i<=n;++i) {
		scanf("%d",c+i);
		dp[i][i]=1;
	}
	// 2
	for (int i=1;i<n;++i) {
		dp[i][i+1]=1;
		if (c[i]!=c[i+1]) {
			dp[i][i+1]++;
		}
	}
	int l,r;
	for (int i=3;i<=n;++i) {
		for (int j=1;j+i-1<=n;++j) {
			l=j;r=i+j-1;
			if (c[l]==c[r]) {
				dp[l][r]=dp[l+1][r-1];
			}
			for (int k=l;k<r;++k) {
				dp[l][r]=min(dp[l][r],dp[l][k]+dp[k+1][r]);
			}
		}
	}
	printf("%d",dp[1][n]);
	return 0;
}