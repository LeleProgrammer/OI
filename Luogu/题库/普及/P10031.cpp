#include <bits/stdc++.h>

#define int long long

using namespace std;

int t,n;

signed main() {
    scanf("%lld",&t);
    while (t--) {
        scanf("%lld",&n);
        if (n%2==1) printf("%lld\n",n);
        else printf("%lld\n",n^(n/2));
    }
    return 0;
}