#include <bits/stdc++.h>

#define int long long

using namespace std;

int n,k;
int two[205]; // 分解因数中2的个数
int five[205]; // 分解因数中5的个数
int val; // 辅助输入
int dp[205][10005]; // dp[j][g] 前i个数，取j个数，取了g个5
int res=0; // 结果

signed main() {
    cin>>n>>k;
    memset(two,0,sizeof(two));
    memset(five,0,sizeof(five));
    for (int i=1;i<=n;++i) {
        cin>>val;
        while (val%2==0 && val!=0) val/=2,two[i]++;
        while (val%5==0 && val!=0) val/=5,five[i]++;
    }
    memset(dp,-0x3f,sizeof(dp));
    dp[0][0]=0;
    for (int i=1;i<=n;++i) {
        for (int j=i;j>=1;--j) {
            for (int g=10000;g>=five[i];--g) {
                dp[j][g]=max(dp[j][g],dp[j-1][g-five[i]]+two[i]);
            }
        }
    }
    for (int g=10000;g>=0;--g) {
        res=max(res,min(g,dp[k][g]));
    }
    cout<<res;
    return 0;
}