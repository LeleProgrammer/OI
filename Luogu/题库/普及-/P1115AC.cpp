#include <bits/stdc++.h>
using namespace std;

int n;
int arr[200005],dp[200005];

int main() {
	scanf("%d",&n);
	for (int i=1;i<=n;++i) {
		scanf("%d",&arr[i]);
	}
	dp[0]=0;
	int result=-0x3f3f3f3f;
	for (int i=1;i<=n;++i) {
		dp[i]=max(dp[i-1]+arr[i],arr[i]);
		result=max(result,dp[i]);
	}
	printf("%d",result);
	return 0;
}