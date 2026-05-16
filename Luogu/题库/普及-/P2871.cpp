#include <bits/stdc++.h>
using namespace std;

int n,m;

int w[3403];
int d[3403];

int dp[12881];

int main() {
	scanf("%d %d",&n,&m);
	for (int i=1;i<=n;++i) {
		scanf("%d %d",&w[i],&d[i]);
	}
	memset(dp,0,sizeof dp);
	for (int i=1;i<=n;++i) {
		for (int j=m;j>=0;--j) {
			if (j<w[i]) {
				dp[j]=dp[j];
			} else {
				dp[j]=max(dp[j-w[i]]+d[i],dp[j]);
			}
		}
	}
	printf("%d",dp[m]);
	return 0;
} 

/*
dp要压一维，不然爆MLE 
*/