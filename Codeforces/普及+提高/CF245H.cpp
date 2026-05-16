#include <bits/stdc++.h>
using namespace std;

string ins,s;

int dp[5005][5005];

int n,q;

int is_huiwen[5005][5005];

bool check_huiwen(int l,int r) {
	if (is_huiwen[l][r]!=-1) {
		return is_huiwen[l][r];
	}
	if (l==r) {
		is_huiwen[l][r]=1;
		return is_huiwen[l][r];
	}
	else if (l+1==r) {
		if (s[l]==s[r]) {
			is_huiwen[l][r]=1;
			return is_huiwen[l][r];
		} else {
			is_huiwen[l][r]=0;
			return is_huiwen[l][r];
		}
	}
	if (s[l]!=s[r]) {
		is_huiwen[l][r]=0;
		return is_huiwen[l][r];
	}
	is_huiwen[l][r]=check_huiwen(l+1,r-1);
	return is_huiwen[l][r];
}

int main() {
	cin>>ins>>q;
	n=ins.size();
	s=" "+ins;
	memset(is_huiwen,-1,sizeof is_huiwen);
	for (int i=1;i<=n;++i) {
		dp[i][i]=1;
	}
	for (int i=1;i<=n-1;++i) {
		if (s[i]==s[i+1]) {
			dp[i][i+1]=3;
		} else {
			dp[i][i+1]=2;
		}
	}
//	for (int l=n-2;l>=1;--l) {
//		for (int r=l+2;r<=n;++r) {
//			dp[l][r]=dp[l+1][r]+dp[l][r-1]-dp[l+1][r-1];
//			if (check_huiwen(l,r)) dp[l][r]++;
//		}
//	}
	int r;
	for (int len=3;len<=n;++len) {
		for (int l=1;l+len-1<=n;++l) {
			r=l+len-1;
			dp[l][r]=dp[l+1][r]+dp[l][r-1]-dp[l+1][r-1];
			if (check_huiwen(l,r)) dp[l][r]++;
		}
	}
	for (int i=1;i<=q;++i) {
		int l,r;
		scanf("%d %d",&l,&r);
		printf("%d\n",dp[l][r]);
	}
//	for (int i=1;i<=n;++i) {
//		for (int j=i;j<=n;++j) {
//			cout<<is_huiwen[i][j]<<' ';
//		}
//		cout<<endl;
//	}
	return 0;
} 