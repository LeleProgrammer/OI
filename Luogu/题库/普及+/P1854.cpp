#include <bits/stdc++.h>
using namespace std;

int n,m;
int rule[105][105]; // rule[i][j] 花i瓶j 
int dp[105][105]; // dp[i][j] 到瓶i插了j朵花 

// 读入数据 
inline void read() {
	scanf("%d %d",&n,&m);
	for (int i=1;i<=n;++i) {
		for (int j=1;j<=m;++j) {
			scanf("%d",&rule[i][j]);
		}
	}
	memset(dp,-0x3f,sizeof dp);
}

// 输出答案 
inline void output() {
	printf("%d\n",dp[m][n]);
	vector<int> result;
	// 反演状态
	int i=m,j=n;
	while (i>=1 && j>=1) {
		// ij都等于1不特判会T QWQ 
		if (i==1 && j==1) {
			result.push_back(1);
			break;
		}
		if (dp[i][j]==dp[i-1][j]) {
			// 没放
			i--;
			continue;
		}
		if (dp[i][j]==dp[i-1][j-1]+rule[j][i]) {
			// 放了
			result.push_back(i);
			i--;j--;
			continue; 
		}
	}
	reverse(result.begin(),result.end());
	for (int i=0;i<result.size();++i) {
		printf("%d ",result[i]);
	}
}

int main() {
	read();
	// 到第i个花瓶，第0朵花（没插花），初始化为0
	for (int i=1;i<=m;++i) {
		dp[i][0]=0;
		dp[i][1]=rule[1][i];
	}
	// 状态转移
	for (int i=2;i<=m;++i) { // i个花瓶 
		for (int j=1;j<=n;++j) { // j朵花 
			dp[i][j]=max(dp[i-1][j],dp[i-1][j-1]+rule[j][i]);
		}
	}
	output();
	return 0;
}

/*
状态转移方程
dp[i][j]=max(dp[i-1][j],dp[i-1][j-1]+rule[i][j]);
其中
dp[i-1][j]表示上一个花瓶，花朵数量不变，意思就是继承上一个
花瓶的状态，不放新的花。
dp[i-1][j-1]+rule[i][j]表示上一个花瓶，上一朵花的状态，加上第j
朵花得到的新状态，意思就是从上一个花瓶的状态中，插一朵花。 
*/