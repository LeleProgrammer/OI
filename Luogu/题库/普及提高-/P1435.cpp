#include <bits/stdc++.h>
using namespace std;

char s1[5005],s2[5005];

int dp[5005],old_dp[5005];

int main() {
	scanf("%s",s1+1);
	for (int i=1;i<=strlen(s1+1);++i) {
		s2[i]=s1[strlen(s1+1)+1-i];
	}
	for (int i=1;i<=strlen(s1+1);++i) {
		for (int j=1;j<=strlen(s1+1);++j) {
			if (s1[i]==s2[j]) {
				dp[j]=old_dp[j-1]+1;
			} else {
				dp[j]=max(old_dp[j],dp[j-1]);
			}
		}
		memcpy(old_dp,dp,sizeof dp);
	}
	int n=strlen(s1+1);
	printf("%d",n-dp[n]);
	return 0;
}