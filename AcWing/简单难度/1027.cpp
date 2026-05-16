#include <bits/stdc++.h>

#define max3(a,b,c) max(max(a,b),c)
#define max4(a,b,c,d) max(max(max(a,b),c),d)

using namespace std;

const int N=15;

int n;
int a[N][N];
int f[N][N][N][N];

int main() {
    scanf("%d",&n);
    while (true) {
        int b,c,d;
        scanf("%d %d %d",&b,&c,&d);
        if (!b && !c && !d) break;
        a[b][c]=d;
    }
    for (int i=1;i<=n;++i) {
        for (int j=1;j<=n;++j) {
            for (int p=1;p<=n;++p) {
                for (int q=1;q<=n;++q) {
                    f[i][j][p][q]=max4(f[i-1][j][p-1][q],f[i-1][j][p][q-1],f[i][j-1][p-1][q],f[i][j-1][p][q-1]);
                    if (i==p && j==q) f[i][j][p][q]+=a[i][j];
                    else f[i][j][p][q]+=a[i][j]+a[p][q];
                }
            }
        }
    }
    printf("%d",f[n][n][n][n]);
    return 0;
}