#include <bits/stdc++.h>

#define int long long

using namespace std;

int n;

signed main() {
    scanf("%lld",&n);
    int sum=1;
    if (n==1) sum=0;
    for (int i=2;i<=sqrt(n);++i) {
        if (n%i) continue;
        sum+=i;
        if (n/i==i) continue;
        sum+=(n/i);
    }
    if (sum==n) puts("Perfect");
    else if (sum<n) puts("Deficient");
    else puts("Abundant");
    return 0;
}