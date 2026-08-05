#include <bits/stdc++.h>
using namespace std;

struct node {
	int north;
	int south;
	friend bool operator < (const node& a,const node& b) {
		return a.north<b.north;
	}
};

node nodes[200010];

int n,result=1;

int dp[200010];

int main() {
	scanf("%d",&n);
	for (int i=1;i<=n;++i) {
		scanf("%d %d",&nodes[i].south,&nodes[i].north);
	}
	sort(nodes+1,nodes+1+n);
//	for (int i=1;i<=n;++i) {
//		dp[i]=1;
//		for (int j=1;j<i;++j) {
//			if (nodes[i].south>=nodes[j].south) {
//				dp[i]=max(dp[i],dp[j]+1);
//			}
//		}
//		result=max(result,dp[i]);
//	}
	dp[1]=nodes[1].south;
	for (int i=2;i<=n;++i) {
		int tmp=upper_bound(dp+1,dp+result+1,nodes[i].south)-dp;
		dp[tmp]=nodes[i].south;
		if (tmp>result) result++;
	}
	printf("%d",result);
	return 0;
}