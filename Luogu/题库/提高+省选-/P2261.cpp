#include <bits/stdc++.h>

#define int long long

using namespace std;

int n,k;
int ans;

int g(int x,int k) {
    return k/(k/x);
}

signed main() {
    scanf("%lld %lld",&n,&k);
    ans+=n*k;
    int mx=min(n,k);
    for (int l=1,r;l<=mx;l=r+1) {
        r=min(n,g(l,k));
        ans-=((r-l+1)*(l+r)/2)*(k/l);
    }
    printf("%lld",ans);
    return 0;
}