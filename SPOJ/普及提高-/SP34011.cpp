#include <bits/stdc++.h>

#define int long long

using namespace std;

signed main() {
    int t;
    scanf("%lld",&t);
    for (int i=1;i<=t;++i) {
        int a,b,c;
        scanf("%lld %lld %lld",&a,&b,&c);
        printf("Case %lld: %lld\n",i,a*((b+1)*b/2)*((c+1)*c/2));
    }
    return 0;
}