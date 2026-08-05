#include <bits/stdc++.h>

#define int long long

using namespace std;

const int p=998244353;
const int N=5000005;

int T,n,m;
int ans;
int a[N],inv[N],b[N];

signed main() {
    scanf("%lld %lld",&T,&n);
    a[0]=a[1]=1,inv[1]=1,b[0]=1;
    for (int i=2;i<=n;++i) a[i]=(a[i-1]*i)%p;
    for (int i=2;i<=n;++i) inv[i]=((p-p/i)*inv[p%i])%p;
    for (int i=1;i<=n;++i) b[i]=(b[i-1]*inv[i])%p;
    while (T--) {
        scanf("%lld %lld",&n,&m);
        int k=(((a[n]*b[m])%p)*b[n-m])%p;
        ans^=k;
    }
    printf("%lld",ans);
    return 0;
}