#include <bits/stdc++.h>

#define mod 1000000007

using namespace std;

int D,T,M;
int f[3005][1505];

int main() {
    scanf("%d %d %d",&D,&T,&M);
    memset(f,0,sizeof(f)); f[0][M]=1;
    for (int i=1;i<=T;++i) {
        for (int j=0;j<=M;++j) {
            if (i-(M-j)-(M-j)<D) {
                f[i][j]=f[i-1][j]+f[i-1][j+1];
                f[i][j]%=mod;
            }
        }
    }
    printf("%d",f[T][0]);
    return 0;
}