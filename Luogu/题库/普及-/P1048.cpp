#include <bits/stdc++.h>
using namespace std;

// ×´Ì¬×ªÒÆ·½³Ì
// dp[i][j]=max(dp[i-1][j-time[i]]+value[i],dp[i-1][j])

struct grass {
    int time;
    int value;
} item[10005];

int dp[10005][10005];

int main() {
    int T,M;
    scanf("%d %d",&T,&M);
    for (int i=1;i<=M;++i) {
        scanf("%d %d",&item[i].time,&item[i].value);
    }
    dp[0][0]=0;
    for (int i=1;i<=M;++i) {
        for (int j=1;j<=T;++j) {
            if (j<item[i].time) {
                dp[i][j]=dp[i-1][j];
            } else {
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-item[i].time]+item[i].value);
            }
        }
    }
    printf("%d",dp[M][T]);
    return 0;
}