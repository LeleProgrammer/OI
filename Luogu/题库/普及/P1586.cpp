#include <bits/stdc++.h>
using namespace std;

const int N=32768+100;

int T,n;
int f[10][N];

int main() {
    scanf("%d",&T);
    f[0][0]=1;
    for (int j=1;j*j<=N;++j) {
        for (int k=j*j;k<=N;++k) {
            for (int i=1;i<=4;++i) {
                f[i][k]+=f[i-1][k-j*j];
            }
        }
    }
    while (T--) {
        scanf("%d",&n);
        printf("%d\n",f[1][n]+f[2][n]+f[3][n]+f[4][n]);
    }
    return 0;
}