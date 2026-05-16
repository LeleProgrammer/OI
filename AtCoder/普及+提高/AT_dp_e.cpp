#include <bits/stdc++.h>

#define int long long

using namespace std;

int n,W;
const int MAXW=1e3*1e2+5;
int w[MAXW];
int v[MAXW];
int dp[MAXW];

signed main() {
    scanf("%lld %lld",&n,&W);
    for (int i=1;i<=n;++i) {
        scanf("%lld %lld",v+i,w+i);
    }
    for (int i=1;i<=MAXW;++i) dp[i]=0x7f7f7f7f;
    for (int i=1;i<=n;++i) {
        for (int j=MAXW-5;j>=w[i];--j) {
            dp[j]=min(dp[j],dp[j-w[i]]+v[i]);
        }
    }
    for (int j=MAXW-5;j>=0;--j) {
        if (W>=dp[j]) {
            printf("%lld\n",j);
            return 0;
        }
    }
    return 0;
}