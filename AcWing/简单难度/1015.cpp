#include <bits/stdc++.h>
using namespace std;

const int N=105;

int T;
int n,m;
int a[N][N];
int f[N][N];

int main() {
    scanf("%d",&T);
    while (T--) {
        scanf("%d %d",&n,&m);
        for (int i=1;i<=n;++i) {
            for (int j=1;j<=m;++j) {
                scanf("%d",&a[i][j]);
            }
        }
        memset(f,0,sizeof(f));
        for (int i=1;i<=n;++i) {
            for (int j=1;j<=m;++j) {
                f[i][j]=max(f[i-1][j],f[i][j-1])+a[i][j];
            }
        }
        printf("%d\n",f[n][m]);
    }
    return 0;
}