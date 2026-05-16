#include <bits/stdc++.h>
using namespace std;

int n,M,T;

int mn[205];
int tme[205];

int dp[105][205][205];

int main() {
	scanf("%d %d %d",&n,&M,&T);
	for (int i=1;i<=n;++i) {
		scanf("%d %d",mn+i,tme+i);
	}
	memset(dp,0,sizeof dp);
	int res=0;
	for (int i=1;i<=n;++i) {
		for (int j=1;j<=M;++j) {
			for (int k=1;k<=T;++k) {
				if (j-mn[i]<0 || k-tme[i]<0) {
					dp[i][j][k]=dp[i-1][j][k];
				} else {
					dp[i][j][k]=max(dp[i-1][j][k],dp[i-1][j-mn[i]][k-tme[i]]+1);
				}
				res=max(dp[i][j][k],res);
			}
		}
	}
	printf("%d",res);
	return 0;
}