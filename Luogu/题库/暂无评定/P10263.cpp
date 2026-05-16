#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N=1000005;

int n,m,k;
int a[N],b[N];
int ans;

signed main() {
    scanf("%lld %lld %lld",&n,&m,&k);
    for (int i=1;i<=max(n,m);++i) {
        for (int j=i;j<=k;j+=i) {
            if (i<=n) a[j]++;
            if (i<=m) b[j]++;
        }
    }
    for (int i=1;i<=k;++i) {
        ans+=a[i]*b[i]*i;
    }
    printf("%lld",ans);
    return 0;
}