#include <bits/stdc++.h>
using namespace std;

int m,n;
int arr[205][205];
int dp[55][55][55][55]={0};

int maxx(int a,int b,int c,int d) {
	int res=a;
	res=max(res,b);
	res=max(res,c);
	res=max(res,d);
	return res;
}

int main() {
	scanf("%d %d",&m,&n);
	for (int i=1;i<=m;++i) {
		for (int j=1;j<=n;++j) {
			scanf("%d",&arr[i][j]);
		}
	}
	for (int i=1;i<=m;++i) {
		for (int j=1;j<=n;++j) {
			for (int p=1;p<=m;++p) {
				for (int q=j+1;q<=n;++q) {
					dp[i][j][p][q]=maxx(dp[i-1][j][p-1][q],dp[i-1][j][p][q-1],dp[i][j-1][p-1][q],dp[i][j-1][p][q-1])+arr[i][j]+arr[p][q];
				}
			}
		}
	}
	printf("%d",dp[m][n-1][m-1][n]);
	return 0;
}