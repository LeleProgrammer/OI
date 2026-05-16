#include <bits/stdc++.h>
using namespace std;

int n,m;
int arr[55];
int dp[20005];
int maxi=0;
int summ=0;

int main() {
    scanf("%d %d",&n,&m);
    for (int i=1;i<=n;++i) {
        scanf("%d",arr+i);
        maxi=max(maxi,arr[i]);
        summ+=arr[i];
    }
    if (summ<m) {
        printf("-1\n");
        return 0;
    }
    memset(dp,-1,sizeof(dp));
    dp[0]=1;
    for (int i=1;i<=n;++i) {
        for (int j=m+maxi;j>=arr[i];--j) {
            if (dp[j-arr[i]]!=-1) {
                dp[j]=1;
            }
        }
    }
    for (int i=m;i<=m+maxi;++i) {
        if (dp[i]!=-1) {
            printf("%d\n",i);
            return 0;
        }
    }
    return 0;
}