#include <bits/stdc++.h>
using namespace std;

int n;

int in[105];

struct ball {
    int a,b;
} arr[210][210];

int dp[210][210];

int maxx=-0x3f3f3f3f;

int main() {
    scanf("%d",&n);
    for (int i=1;i<=n;++i) {
        scanf("%d",in+i);
        in[i+n]=in[i];
    }
    memset(dp,-0x3f,sizeof(dp));
    for (int i=1;i<=n*2-1;++i) {
        arr[i][i].a=in[i];
        arr[i][i].b=in[i+1];
        dp[i][i]=0;
    }
    for (int start=1;start<=n;++start) {
        for (int len=2;len<=n;++len) {
            for (int l=start,r=l+len-1;r<=start+n-1;++l,++r) {
                for (int k=l;k<=r-1;++k) {
                    if (dp[l][k]+dp[k+1][r]+arr[l][k].a*arr[l][k].b*arr[k+1][r].b>dp[l][r]) {
                        dp[l][r]=dp[l][k]+dp[k+1][r]+arr[l][k].a*arr[l][k].b*arr[k+1][r].b;
                        arr[l][r].a=arr[l][k].a;
                        arr[l][r].b=arr[k+1][r].b;
                    }
                }
            }
        }
        maxx=max(maxx,dp[start][start+n-1]);
    }
    printf("%d",maxx);
    return 0;
}