#include <bits/stdc++.h>
using namespace std;

int n,k;
__int128_t dp[1005];

inline void write(__int128_t a) {
    if (a<0) {
        putchar('-');
        a*=-1;
    }
    if (a>=10) {
        write(a/10);
    }
    putchar(a%10+'0');
}

int main() {
    scanf("%d %d",&n,&k);
    dp[0]=1;
    for (int i=1;i<=k;++i) {
        for (int j=i;j<=n;++j) {
            dp[j]=dp[j]+dp[j-i];
        }
    }
    write(dp[n]);
    return 0;
}