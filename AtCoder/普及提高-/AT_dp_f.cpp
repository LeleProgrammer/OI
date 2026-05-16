#include <bits/stdc++.h>
using namespace std;

char s[3005];
char t[3005];

int dp[3005][3005];

string ans;

int main() {
    cin>>s+1;
    cin>>t+1;
    memset(dp,0,sizeof(dp));
    for (int i=1;i<=strlen(s+1);++i) {
        for (int j=1;j<=strlen(t+1);++j) {
            if (s[i]==t[j]) {
                dp[i][j]=max(max(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1]+1);
            } else {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    int i,j;
    i=strlen(s+1);
    j=strlen(t+1);
    while (dp[i][j]) {
        if (s[i]==t[j]) {
            ans.push_back(s[i]);
            --i,--j;
        } else if (dp[i][j]==dp[i-1][j]) {
            --i;
        } else {
            --j;
        }
    }
    reverse(ans.begin(),ans.end());
    cout<<ans<<endl;
    return 0;
}