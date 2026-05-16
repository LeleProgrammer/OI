#include <bits/stdc++.h>

#define max3(a,b,c) max(max(a,b),c)

using namespace std;

const int R=105,C=105;

int r,c;
int arr[R][C];
int f[R][C];

int main() {
    scanf("%d %d",&r,&c);
    for (int i=1;i<=r;++i) {
        for (int j=1;j<=c;++j) {
            scanf("%d",&arr[i][j]);
        }
    }
    for (int j=1;j<=c;++j) {
        for (int i=1;i<=r;++i) {
            if (i>j) continue;
            f[i][j]=max3(f[i-1][j-1],f[i][j-1],f[i+1][j-1])+arr[i][j];
        }
    }
    printf("%d",f[r][c]);
    return 0;
}