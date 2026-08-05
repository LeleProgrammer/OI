#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N=55;

int n;
int f[N][N];

signed main() {
    scanf("%lld",&n);
    f[1][1]=1;
    for (int i=2;i<=n*2;++i) {
        for (int j=0;j<=min(i,n);++j) {
            f[i][j]=((j-1>=0)?f[i-1][j-1]:0)+(f[i-1][j+1]);
        }
    }
    printf("%lld",f[n*2][0]);
    return 0;
}