#include <bits/stdc++.h>
using namespace std;

int n,m;
int pre[2510];
int dp[2510];

inline int zdh(int l,int r) {
	return abs(pre[r]-pre[l-1]);
}

int main() {
	memset(dp,0x3f,sizeof dp);
	scanf("%d %d",&n,&m);
	int tmp;
	for (int i=1;i<=n;++i) {
		scanf("%d",&tmp);
		if (tmp==2) {
			tmp=-1;
		}
		pre[i]=pre[i-1]+tmp; 
	}
	dp[0]=0;dp[1]=1; 
	for (int i=1;i<=n;++i) {
		for (int j=1;j<=i;++j) {
			if (zdh(j,i)==i-j+1 || zdh(j,i)<=m) {
				dp[i]=min(dp[i],dp[j-1]+1);
			}
		}
	}
	printf("%d",dp[n]);
	return 0;
}