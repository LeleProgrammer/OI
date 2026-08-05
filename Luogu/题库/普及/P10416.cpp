#include <bits/stdc++.h>

#define int long long

using namespace std;

int T,l,r;

signed main() {
    scanf("%lld",&T);
    while (T--) {
        scanf("%lld %lld",&l,&r);
        if (l*2>r) {
            puts("0");
            continue;
        }
        int a=l*2;
        int b=r-a+1;
        printf("%lld\n",(1ll+b)*b/2ll);
    }
    return 0;
}