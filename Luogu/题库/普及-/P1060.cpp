#include <bits/stdc++.h>
using namespace std;

int n,m;
int dp[30005];
int w[30005];
int v[30005];
int ans=0;

int main() {
    scanf("%d %d",&n,&m);
    for (int i=1;i<=m;++i) {
        scanf("%d %d",v+i,w+i);
    }
    memset(dp,0,sizeof(dp));
    for (int i=1;i<=m;++i) {
        for (int j=n;j>v[i];--j) {
            dp[j]=max(dp[j],dp[j-v[i]]+v[i]*w[i]);
            ans=max(ans,dp[j]);
        }
    }
    printf("%d",ans);
    return 0;
}