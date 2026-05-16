#include <bits/stdc++.h>
using namespace std;

int n;
int dp[1005];

int main() {
    scanf("%d",&n);
    dp[1]=1;
    for (int i=2;i<=n;++i) {
        int res=0;
        for (int j=1;j<=i/2;++j) {
            res+=dp[j];
        }
        ++res;
        dp[i]=res;
    }
    printf("%d",dp[n]);
    return 0;
}