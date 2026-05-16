#include <bits/stdc++.h>
using namespace std;

const int N=55;
const int MAXHT=405;

int h,t,n;
int hs[N];
int ts[N];
int ks[N];
int dp[N][MAXHT][MAXHT];

int main() {
    scanf("%d %d %d",&h,&t,&n);
    for (int i=1;i<=n;++i) {
        scanf("%d %d %d",hs+i,ts+i,ks+i);
    }
    memset(dp,0,sizeof(dp));
    for (int i=1;i<=n;++i) {
        for (int j=1;j<=h;++j) {
            for (int p=1;p<=t;++p) {
                if (j>=hs[i] && p>=ts[i]) {
                    dp[i][j][p]=max(dp[i-1][j][p],dp[i-1][j-hs[i]][p-ts[i]]+ks[i]);
                } else {
                    dp[i][j][p]=dp[i-1][j][p];
                }
            }
        }
    }
    printf("%d",dp[n][h][t]);
    return 0;
}