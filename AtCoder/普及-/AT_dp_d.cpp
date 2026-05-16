#include <bits/stdc++.h>

#define int long long

using namespace std;

int n,W;
int w[100005];
int v[100005];
int dp[100005];

signed main() {
    scanf("%lld %lld",&n,&W);
    for (int i=1;i<=n;++i) {
        scanf("%lld %lld",w+i,v+i);
    }
    memset(dp,0,sizeof(dp));
    for (int i=1;i<=n;++i) {
        for (int j=W;j>=w[i];--j) {
            dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
        }
    }
    printf("%lld\n",dp[W]);
    return 0;
}