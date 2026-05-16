#include <bits/stdc++.h>
using namespace std;

const int maxmn=2e3;
const int maxk=2e3;

int dp[maxmn][maxmn];
int volumn[maxk][maxmn];
int value[maxk][maxmn];
int s[maxk];

int main() {
    int m,n;
    scanf("%d %d",&m,&n);
    int a,b,c;
    memset(dp,0,sizeof(dp));
    memset(volumn,0,sizeof(volumn));
    memset(value,0,sizeof(value));
    memset(s,0,sizeof(s));
    for (int i=1;i<=n;++i) {
        scanf("%d %d %d",&a,&b,&c);
        s[c]++;
        volumn[c][s[c]]=a;
        value[c][s[c]]=b;
    }
    int result=0;
    for (int i=1;i<=n;++i) {
        for (int j=0;j<=m;++j) {
            for (int k=1;k<=s[i];++k) {
                if (j-volumn[i][k]>=0) {
                    dp[i][j]=max(dp[i][j],dp[i-1][j-volumn[i][k]]+value[i][k]);
                }
                dp[i][j]=max(dp[i-1][j],dp[i][j]);
                result=max(result,dp[i][j]);
            }
        }
    }
    printf("%d",result);
    return 0;
}