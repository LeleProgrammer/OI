#include <bits/stdc++.h>

#define int long long

using namespace std;

int n;

int phi(int x) {
    int ans=x;
    for (int i=2;i*i<=x;++i) {
        if (x%i) continue;
        ans-=ans/i;
        while (x%i==0) x/=i;
    }
    if (x>=2) ans-=ans/x;
    return ans;
}

signed main() {
    scanf("%lld",&n);
    int ans=0;
    for (int i=1;i<=sqrt(n);++i) {
        if (n%i) continue;
        ans+=i*phi(n/i);
        if (i*i!=n) ans+=(n/i)*phi(i);
    }
    printf("%lld",ans);
    return 0;
}