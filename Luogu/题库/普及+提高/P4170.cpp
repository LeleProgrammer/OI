#include <bits/stdc++.h>
using namespace std;

string s;

int dp[55][55];

int main() {
	cin>>s;
	memset(dp,0x7f,sizeof dp);
	for (int i=1;i<=s.size();++i) {
		dp[i][i]=1;
	}
	int l,r;
	for (int i=2;i<=s.size();++i) {
		for (int j=1;j+i-1<=s.size();++j) {
			l=j;r=j+i-1;
			if (s[l-1]==s[r-1]) {
				dp[l][r]=min(dp[l+1][r],dp[l][r-1]);
			} else {
				for (int k=l;k<r;++k) {
					dp[l][r]=min(dp[l][r],dp[l][k]+dp[k+1][r]);
				}
			}
		}
	}
	cout<<dp[1][s.size()];
	return 0;
}