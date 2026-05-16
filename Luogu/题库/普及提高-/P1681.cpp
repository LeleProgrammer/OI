#include <bits/stdc++.h>

#define min3(a,b,c) min(min(a,b),c)

using namespace std;

const int N=1505,M=1505;

int arr[N][M];
int n,m;
int f[N][M][2];
int res;

int main() {
    scanf("%d %d",&n,&m);
    for (int i=1;i<=n;++i) {
        for (int j=1;j<=m;++j) {
            scanf("%d",&arr[i][j]);
        }
    }
    for (int i=1;i<=n;++i) {
        for (int j=1;j<=m;++j) {
            res=max(res,f[i][j][arr[i][j]]=min3(f[i-1][j-1][arr[i][j]],f[i-1][j][arr[i][j]^1],f[i][j-1][arr[i][j]^1])+1);
        }
    }
    printf("%d",res);
    return 0;
}