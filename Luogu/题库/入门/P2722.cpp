#include <bits/stdc++.h>
using namespace std;

int m,n;

int sco[10005];
int tme[10005];

int dp[100005];

int main() {
	scanf("%d %d",&m,&n);
	for (int i=1;i<=n;++i) {
		scanf("%d %d",sco+i,tme+i);
	}
	memset(dp,0,sizeof dp);
	for (int i=1;i<=n;++i) {
		for (int j=tme[i];j<=m;++j) {
			dp[j]=max(dp[j],dp[j-tme[i]]+sco[i]);
		}
	}
	printf("%d",dp[m]);
	return 0;
}