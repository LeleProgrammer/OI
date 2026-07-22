#include <bits/stdc++.h>
using namespace std;

int n,l,r;
int dp[255][255];
int arr[255];
int ans=0;

int main() {
	scanf("%d",&n);
	for (int i=1;i<=n;++i) {
		scanf("%d",arr+i);
		dp[i][i]=arr[i];
		ans=max(ans,dp[i][i]);
	}
	for (int i=2;i<=n;++i) {
		for (int j=1;j+i-1<=n;++j) {
			l=j;r=i+j-1;
			for (int k=l;k<r;++k) {
				if (dp[l][k]==dp[k+1][r] && dp[l][k]>0) {
					dp[l][r]=max(dp[l][r],dp[l][k]+1);
				}
			}
			ans=max(ans,dp[l][r]);
		}
	}
	printf("%d",ans);
	return 0;
}