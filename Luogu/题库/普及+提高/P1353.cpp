#include <bits/stdc++.h>
using namespace std;

int n,m;
int d[10005];
int f[10005][505][2]; // 0:rest 1:run
int ans=0;

int main() {
    scanf("%d %d",&n,&m);
    for (int i=1;i<=n;++i) {
        scanf("%d",&d[i]);
    }
    memset(f,0,sizeof(f));
    for (int i=1;i<=n;++i) {
        for (int j=0;j<=min(m,i);++j) {
            if (j>=1) f[i][j][1]=f[i-1][j-1][1]+d[i];
            if (j==1) f[i][j][1]=max(f[i][j][1],f[i-1][j-1][0]+d[i]);
            f[i][j][0]=max(f[i-1][j+1][0],f[i-1][j+1][1]);
            f[i][0][0]=max(max(f[i-j][j][0],f[i-j][0][0]),f[i][0][0]);
        }
    }
    printf("%d",f[n][0][0]);
    return 0;
}