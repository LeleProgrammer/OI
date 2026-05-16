#include <bits/stdc++.h>
using namespace std;

int n,m;
char s[2005]; // 字符串
int dp[2005][2005]; // dp数组
int add[128]; // 增加字符的花费（下标用ASCII）
int del[128]; // 删除字符的花费（下标用ASCII）
char c; int a,b; // 辅助输入

int main() {
    scanf("%d %d",&n,&m);
    cin>>s+1;
    for (int i=1;i<=n;++i) {
        cin>>c>>a>>b;
        add[int(c)]=a;
        del[int(c)]=b;
    }
    memset(dp,0x3f,sizeof(dp));
    for (int i=1;i<=m;++i) {
        dp[i][i]=0;
    }
    for (int len=2;len<=m;++len) {
        for (int l=1,r=l+len-1;r<=m;++l,++r) {
            // 对于[l+1,r]和[l,r-1]的区间，只需由增加一个字符和删除一个字符的两者情况选择一个更优的
            // 对于[l+1,r-1]的区间，若l的字符和r的字符相等，[l,r]与[l+1,r-1]相等
            dp[l][r]=min(min(min(dp[l+1][r]+add[s[l]],dp[l+1][r]+del[s[l]]),dp[l][r-1]+add[s[r]]),dp[l][r-1]+del[s[r]]);
            if (s[l]==s[r]) {
                if (len==2) dp[l][r]=0;
                else dp[l][r]=min(dp[l][r],dp[l+1][r-1]);
            }
        }
    }
    printf("%d",dp[1][m]);
    return 0;
}