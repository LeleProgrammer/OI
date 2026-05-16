#include <bits/stdc++.h>
using namespace std;

const int N=1e4+5;

int v,n,c;
int force[N];
int weight[N];
int dp[N]; // dp[j] 前i个物品，体力为j，填充的最大体积

int main() {
    scanf("%d %d %d",&v,&n,&c);
    for (int i=1;i<=n;++i) {
        scanf("%d %d",weight+i,force+i);
    }
    memset(dp,0,sizeof(dp));
    for (int i=1;i<=n;++i) {
        for (int j=c;j>=force[i];--j) {
            dp[j]=max(dp[j],dp[j-force[i]]+weight[i]);
        }
    }
    for (int i=0;i<=c;++i) {
        if (dp[i]>=v) {
            printf("%d",c-i);
            return 0;
        }
    }
    printf("Impossible");
    return 0;
}