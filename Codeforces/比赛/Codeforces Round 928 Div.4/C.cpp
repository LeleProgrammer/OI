#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N=200005;

int T,n;
int f[N];
int s[N];

signed main() {
    for (int i=1;i<=200000;++i) {
        f[i]=f[i/10]+(i%10);
        s[i]=s[i-1]+f[i];
    }
    scanf("%lld",&T);
    while (T--) {
        scanf("%lld",&n);
        printf("%lld\n",s[n]);
    }
    return 0;
}