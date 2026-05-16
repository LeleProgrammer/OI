#include <bits/stdc++.h>

#define int long long

using namespace std;

int f[105][105];

signed main() {
    for (int i=0;i<=100;++i) {
        f[i][0]=1;
        for (int j=1;j<=i;++j) {
            f[i][j]=f[i-1][j]+f[i-1][j-1];
        }
    }
    int n,m;
    while (true) {
        scanf("%lld %lld",&n,&m);
        if (n==0 && m==0) break;
        printf("%lld things taken %lld at a time is %lld exactly.\n",n,m,f[n][m]);
    }
    return 0;
}