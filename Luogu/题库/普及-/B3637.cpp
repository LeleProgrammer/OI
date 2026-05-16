#include <bits/stdc++.h>
#define MAXN 5005
using namespace std;

int main() {
    int n,array[MAXN],_max=0,nowmax;
    scanf("%d",&n);
    for (int i=0;i<n;++i) {
        scanf("%d",&array[i]);
    }
    int dp[MAXN];
    dp[0]=1;
    for (int i=0;i<n;++i) {
        nowmax=0;
        for (int j=0;j<i;++j) {
            if (array[j]<array[i] && dp[j]>nowmax) {
                nowmax=dp[j];
            }
        }
        dp[i]=nowmax+1;
        if (dp[i]>_max) {
            _max=dp[i];
        }
    }
    printf("%d",_max);
    return 0;
}