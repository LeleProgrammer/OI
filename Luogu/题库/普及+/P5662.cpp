#include <bits/stdc++.h>
using namespace std;

int T,N,M;

int item[105][105];

int dp[10005];

void init() {
    scanf("%d %d %d",&T,&N,&M);
    for (int i=1;i<=T;++i) {
        for (int j=1;j<=N;++j) {
            scanf("%d",&item[i][j]);
        }
    }
}

int main() {
    init();
    for (int i=1;i<T;++i) {
        memset(dp,0,sizeof(dp));
        for (int j=1;j<=N;++j) {
            for (int k=1;k<=M;++k) {
                if (k-item[i][j]>=0) {
                    dp[k]=max(dp[k],dp[k-item[i][j]]+item[i+1][j]-item[i][j]);
                }
            }
        }
        M+=dp[M];
    }
    printf("%d",M);
    return 0;
}