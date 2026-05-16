#include <bits/stdc++.h>
using namespace std;

int n,r,l2,r2,result=-0x3f3f3f3f;

int dp[405][405];

int main() {
	scanf("%d",&n);
	memset(dp,0,sizeof(dp));
	for (int i=1;i<=n;++i) {
		scanf("%d",&dp[i][i]);
		result=max(result,dp[i][i]);
	}
	for (int len=2;len<=n;++len) {
		for (int l=1;l+len-1<=n;++l) {
			r=l+len-1;
			for (int k=l;k<r;++k) {
				if (dp[l][k]>0 && dp[k+1][r]>0 && dp[l][k]==dp[k+1][r]) {
					dp[l][r]=max(dp[l][r],dp[l][k]+dp[k+1][r]);
				}
			}
			l2=l;r2=r;
			while (l2+1<=r2-1) {
				if (dp[l][l2]==0) {
					++l2;
					continue;
				}
				if (dp[r2][r]==0) {
					--r2;
					continue;
				}
				if (dp[l][l2]<dp[r2][r]) {
					++l2;
					continue;
				}
				if (dp[l][l2]>dp[r2][r]) {
					--r2;
					continue;
				}
				if (dp[l][l2]==dp[r2][r]) {
					if (dp[l2+1][r2-1]==0) {
						++l2;
						--r2;
						continue;
					} else {
						dp[l][r]=max(dp[l][l2]+dp[l2+1][r2-1]+dp[r2][r],dp[l][r]);
						break;
					}
				}
			}
			result=max(result,dp[l][r]);
		}
	}
	printf("%d",result);
	return 0;
}