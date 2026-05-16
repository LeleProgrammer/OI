#include <bits/stdc++.h>

#define int unsigned short

using namespace std;

char a[4001],b[4001];
int dp[4001][4001];
int n,m;
int maxx=0;

signed main() {
    cin>>a+1>>b+1;
    n=strlen(a+1);
    m=strlen(b+1);
    memset(dp,0,sizeof(dp));
    for (int i=1;i<=n;++i) {
        for (int j=1;j<=m;++j) {
            if (a[i]==b[j]) {
                dp[i][j]=dp[i-1][j-1]+1;
                maxx=max(maxx,dp[i][j]);
            }
        }
    }
    cout<<maxx<<endl;
    return 0;
}