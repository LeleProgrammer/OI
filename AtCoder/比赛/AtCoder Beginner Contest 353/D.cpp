#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N=200005;
const int mod=998244353;

int n;
int a[N];
int b[N];
int ten[19];
int ans;

int get(int x) {
    int ans=0;
    while (x) {
        x/=10;
        ans++;
    }
    return ans;
}

void init() {
    ten[0]=1;
    for (int i=1;i<=18;++i) {
        ten[i]=ten[i-1]*10LL;
    }
}

signed main() {
    init();
    scanf("%lld",&n);
    for (int i=1;i<=n;++i) {
        scanf("%lld",&a[i]);
    }
    for (int i=n-1;i>=1;--i) {
        b[i]=b[i+1]+ten[get(a[i+1])];
        b[i]%=mod;
    }
    for (int i=1;i<=n-1;++i) {
        ans+=(b[i]*a[i])%mod;
        ans%=mod;
    }
    for (int i=2;i<=n;++i) {
        ans+=a[i]*(i-1);
        ans%=mod;
    }
    printf("%lld",ans);
    return 0;
}