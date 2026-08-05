#include <bits/stdc++.h>
using namespace std;

int d,g;
int dp[105][1005]; // 前i个物品，高度为j，所能拥有的最大能量
int maxx,earliest;

struct node {
    int t,f,h;
    friend bool operator < (const node& a,const node& b) {
        return a.t<b.t;
    }
} ts[105];

int main() {
    scanf("%d %d",&d,&g);
    for (int i=1;i<=g;++i) {
        scanf("%d %d %d",&ts[i].t,&ts[i].f,&ts[i].h);
    }
    sort(ts+1,ts+1+g);
    memset(dp,-1,sizeof(dp));
    dp[0][0]=10;
    maxx=10;
    earliest=0x3f3f3f3f;
    for (int i=0;i<=g;++i) {
        for (int j=0;j<=d;++j) {
            if (dp[i][j]<0) continue;
            if (dp[i][j]-(ts[i+1].t-ts[i].t)>=0) {
                if (j+ts[i+1].h>=d) {
                    printf("%d",ts[i+1].t);
                    return 0;
                }
                dp[i+1][j]=max(dp[i+1][j],dp[i][j]+ts[i+1].f-(ts[i+1].t-ts[i].t));
                dp[i+1][j+ts[i+1].h]=dp[i][j]-(ts[i+1].t-ts[i].t);
            }
        }
        if (dp[i][0]>=0) maxx=max(maxx,dp[i][0]+ts[i].t);
    }
    printf("%d",maxx);
    return 0;
}