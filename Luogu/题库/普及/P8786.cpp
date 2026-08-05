#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N=105,M=105;
const int mod=1000000007;

int n,m;
int f[N+M][N][M];

signed main() {
    scanf("%lld %lld",&n,&m);
    f[0][0][2]=1;
    for (int i=1;i<=n+m;++i) {
        for (int j=0;j<=min(m,i);++j) {
            for (int k=0;k<=m;++k) {
                if (k%2==0) {
                    f[i][j][k]+=f[i-1][j][k/2];
                }
                if (j) f[i][j][k]+=f[i-1][j-1][k+1];
                f[i][j][k]%=mod;
            }
        }
    }
    printf("%lld",f[n+m-1][m-1][1]);
    return 0;
}