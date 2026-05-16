#include <bits/stdc++.h>
using namespace std;

string s;

int n;

int dp[1005][1005];

int main() {
    cin>>s;
    n=s.length();
    s=" "+s;
    for (int i=1;i<=n;++i) dp[i][i]=0;
    for (int i=1;i<=n-1;++i) if (s[i]==s[i+1]) dp[i][i+1]=0;
    for (int len=1;len<=n;++len) {
        for (int l=1,r=l+len-1;r<=n;++l,++r) {
            dp[l][r]=0x3f3f3f3f;
            if (s[l]==s[r]) dp[l][r]=dp[l+1][r-1];
            dp[l][r]=min(dp[l][r],dp[l+1][r]+1);
            dp[l][r]=min(dp[l][r],dp[l][r-1]+1);
        }
    }
    printf("%d",dp[1][n]);
    return 0;
}