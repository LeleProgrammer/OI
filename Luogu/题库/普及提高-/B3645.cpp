#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N=1500005;
const int p=1145141;

int n,q;
int ans;
int a[N];
int pre[N];
int inv[N];

signed main() {
    scanf("%lld %lld",&n,&q);
    for (int i=1;i<=n;++i) scanf("%lld",&a[i]);
    pre[0]=1;
    for (int i=1;i<=n;++i) pre[i]=(pre[i-1]*a[i])%p;
    inv[0]=inv[1]=1;
    for (int i=2;i<p;++i) inv[i]=((p-(p/i))*inv[p%i])%p;
    while (q--) {
        int l,r;
        scanf("%lld %lld",&l,&r);
        int k=(pre[r]*inv[pre[l-1]])%p;
        ans^=k;
    }
    printf("%lld",ans);
    return 0;
}