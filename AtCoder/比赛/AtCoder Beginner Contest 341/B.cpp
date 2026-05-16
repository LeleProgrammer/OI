#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N=200005;

int n,a[N],t[N],s[N];

signed main() {
    scanf("%lld",&n);
    for (int i=1;i<=n;++i) {
        scanf("%lld",&a[i]);
    }
    for (int i=1;i<=n-1;++i) {
        scanf("%lld %lld",&s[i],&t[i]);
    }
    for (int i=1;i<=n-1;++i) {
        int ts=a[i]/s[i];
        a[i+1]+=ts*t[i];
    }
    printf("%lld",a[n]);
    return 0;
}