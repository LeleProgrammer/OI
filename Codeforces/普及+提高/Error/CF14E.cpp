#include <bits/stdc++.h>
using namespace std;

int n,T;
int f[25][15][15][3][5]; // f[i][j][k][p][t] 填了第i个数后，有j个突起，有k个凹下，最后的斜坡呈现趋势（0升1降2平），以数字t结尾

int main() {
    scanf("%d %d",&n,&T);
    memset(f,0,sizeof(f));
    for (int j)
    for (int i=1;i<=n;++i) {
        for (int j=0;j<=T;++j) {
            for (int k=0;k<=T-1;++k) {
                for (int l=1;l<=4;++l) {
                    for (int t=1;t<=4;++t) {
                        // 改向上
                        if (t>l) {
                            f[i][j][k][0][t]+=f[i-1][j][k][0][l]+f[i-1][j][k][2][l];
                        }
                        // 改向下
                        if (t<l) {
                            f[i][j][k][1][t]+=f[i-1][j][k][1][l]+f[i-1][j][k][2][l];
                        }
                        // 由往下折向上
                        if (t>l && k>=1) {
                            f[i][j][k][0][t]+=f[i-1][j][k-1][1][l];
                        }
                        // 由往上折向下
                        if (t<l && j>=1) {
                            f[i][j][k][1][t]+=f[i-1][j-1][k][0][l];
                        }
                        // 改平
                        if (t==l) {
                            f[i][j][k][2][t]+=f[i-1][j][k][2][l]+f[i-1][j][k][0][l]+f[i-1][j][k][1][l];
                        }
                    }
                }
            }
        }
    }
    int res=0;
    for (int t=1;t<=4;++t) {
        res+=f[n][T][T-1][0][t]+f[n][T][T-1][1][t]+f[n][T][T-1][2][t];
    }
    printf("%d",res);
    return 0;
}