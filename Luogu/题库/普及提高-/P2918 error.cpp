#include <bits/stdc++.h>
using namespace std;

int n,h;
int p[105];
int c[105];
int dp[50005];
int res=0x3f3f3f3f;

int main() {
    scanf("%d %d",&n,&h);
    for (int i=1;i<=n;++i) {
        scanf("%d %d",p+i,c+i);
    }
    for (int i=1;i<=h;++i) dp[i]=0x3f3f3f3f;
    dp[0]=0;
    for (int i=1;i<=n;++i) {
        for (int j=p[i];j<=h;++j) {
            dp[j]=min(dp[j],dp[j-p[i]]+c[i]);
        }
    }
    printf("%d",dp[h]);
    return 0;
}