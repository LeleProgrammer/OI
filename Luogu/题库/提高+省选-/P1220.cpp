#include <bits/stdc++.h>
using namespace std;

int n,c;
int dp[55][55][2];
int pre[55];

struct node {
    int pos,w;
} ls[55];

int main() {
    scanf("%d %d",&n,&c);
    pre[0]=0;
    for (int i=1;i<=n;++i) {
        scanf("%d %d",&ls[i].pos,&ls[i].w);
        dp[i][i][0]=dp[i][i][1]=0;
        pre[i]=pre[i-1]+ls[i].w;
    }
    memset(dp,0x3f,sizeof(dp));
    dp[c][c][0]=dp[c][c][1]=0;
    for (int len=2;len<=n;++len) {
        for (int l=1,r=l+len-1;r<=n;++l,++r) {
            dp[l][r][0]=min(dp[l+1][r][0]+(pre[n]-(pre[r]-pre[l]))*(ls[l+1].pos-ls[l].pos),dp[l+1][r][1]+(pre[n]-(pre[r]-pre[l]))*(ls[r].pos-ls[l].pos));
            dp[l][r][1]=min(dp[l][r-1][0]+(pre[n]-(pre[r-1]-pre[l-1]))*(ls[r].pos-ls[l].pos),dp[l][r-1][1]+(pre[n]-(pre[r-1]-pre[l-1]))*(ls[r].pos-ls[r-1].pos));
        }
    }
    printf("%d",min(dp[1][n][0],dp[1][n][1]));
    return 0;
}