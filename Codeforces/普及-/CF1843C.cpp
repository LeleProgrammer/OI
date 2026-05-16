#include <bits/stdc++.h>

#define int long long

using namespace std;

int n,t;

signed main() {
    scanf("%lld",&t);
    while (t--) {
        scanf("%lld",&n);
        int ans=0;
        while (n) {
            ans+=n;
            n/=2;
        }
        printf("%lld\n",ans);
    }
    return 0;
}