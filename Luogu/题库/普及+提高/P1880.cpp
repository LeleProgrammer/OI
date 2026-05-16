#include <bits/stdc++.h>
using namespace std;

int n;

int arr[210];
int dp[2][210][210];
int pre[210];
int sum[210][210];

int minn=0x3f3f3f3f;
int maxx=-0x3f3f3f3f;

int main() {
    scanf("%d",&n);
    for (int i=1;i<=n;++i) {
        scanf("%d",arr+i);
        arr[i+n]=arr[i];
    }
    pre[0]=0;
    for (int i=1;i<=n*2;++i) {
        pre[i]=pre[i-1]+arr[i];
    }
    for (int i=1;i<=n*2;++i) {
        for (int j=i;j<=n*2;++j) {
            sum[i][j]=pre[j]-pre[i-1];
        }
    }
    memset(dp[1],-0x3f,sizeof(dp[1]));
    memset(dp[0],0x3f,sizeof(dp[0]));
    for (int i=1;i<=n*2;++i) {
        dp[0][i][i]=dp[1][i][i]=0;
    }
    for (int start=1;start<=n;++start) {
        for (int len=2;len<=n;++len) {
            for (int l=start,r=l+len-1;r<=start+n-1;++l,++r) {
                for (int k=l;k<=r-1;++k) {
                    dp[0][l][r]=min(dp[0][l][r],dp[0][l][k]+dp[0][k+1][r]+sum[l][r]);
                    dp[1][l][r]=max(dp[1][l][r],dp[1][l][k]+dp[1][k+1][r]+sum[l][r]);
                }
            }
        }
    }
    for (int i=1;i<=n;++i) {
        minn=min(minn,dp[0][i][i+n-1]);
        maxx=max(maxx,dp[1][i][i+n-1]);
    }
    printf("%d\n",minn);
    printf("%d\n",maxx);
    return 0;
}