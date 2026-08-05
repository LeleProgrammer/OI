#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N=500005;
const int mod=1e9+7;

int n;
int a[N],b[N],aa[N],aaa[N],bb[N],bbb[N];
int ans;

signed main() {
    scanf("%lld",&n);
    for (int i=1;i<=n;++i) {
        scanf("%lld",&a[i]);
    }
    for (int i=1;i<=n;++i) {
        scanf("%lld",&b[i]);
    }
    for (int i=1;i<=n;++i) {
        aa[i]=aa[i-1]+a[i];
        aa[i]%=mod;
    }
    for (int i=1;i<=n;++i) {
        aaa[i]=aaa[i-1]+aa[i];
        aaa[i]%=mod;
    }
    for (int i=1;i<=n;++i) {
        bb[i]=bb[i-1]+b[i];
        bb[i]%=mod;
    }
    for (int i=1;i<=n;++i) {
        bbb[i]=bbb[i-1]+bb[i];
        bbb[i]%=mod;
    }
    for (int i=1;i<=n;++i) {
        ans+=(((aa[i]*bb[i])%mod)*i)%mod;
        ans%=mod;
    }
    for (int i=1;i<=n;++i) {
        ans-=(aa[i-1]*(bbb[n]-bbb[i-1]))%mod;
        ans%=mod;
    }
    for (int i=1;i<=n;++i) {
        ans-=(bb[i-1]*(aaa[n]-aaa[i-1]))%mod;
        ans%=mod;
    }
    for (int i=1;i<=n;++i) {
        ans+=(((aa[i-1]*bb[i-1])%mod)*(n-i+1))%mod;
        ans%=mod;
    }
    printf("%lld",ans);
    return 0;
}