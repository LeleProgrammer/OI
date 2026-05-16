#include <bits/stdc++.h>
using namespace std;

const int maxk=55;
const int maxv=5005;
const int maxn=205;

int k,v,n;

int dp[maxv][maxk];
int volumn[maxn];
int value[maxn];
int tmp[maxk];

int main() {
    scanf("%d %d %d",&k,&v,&n);
    for (int i=1;i<=n;++i) {
        scanf("%d %d",&volumn[i],&value[i]);
    }
    for (int i=0;i<maxv;++i) {
        for (int j=0;j<maxk;++j) {
            dp[i][j]=-0x7fffffff;
        }
    }
    dp[0][1]=0;
    for (int i=1;i<=n;++i) {
        for (int j=v;j>=volumn[i];--j) {
            int a,b;
            a=b=1;
            for (int kk=1;kk<=k;++kk) {
                if (dp[j][a]>dp[j-volumn[i]][b]+value[i]) {
                    tmp[kk]=dp[j][a];
                    ++a;
                } else {
                    tmp[kk]=dp[j-volumn[i]][b]+value[i];
                    ++b;
                }
            }
            for (int kk=1;kk<=k;++kk) {
                dp[j][kk]=tmp[kk];
            }
        }
    }
    int result=0;
    for (int kk=1;kk<=k;++kk) {
        result+=dp[v][kk];
    }
    printf("%d",result);
    return 0;
}