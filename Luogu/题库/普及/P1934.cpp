#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N=1005;
const int inf=9000000000000000000LL;

int n,t;
int a[N];
int b[N];
int f[N];

signed main() {
    scanf("%lld %lld",&n,&t);
    for (int i=1;i<=n;++i) {
        scanf("%lld",&a[i]);
        b[i]=b[i-1]+a[i];
        f[i]=inf;
    }
    for (int i=1;i<=n;++i) {
        for (int j=1;j<=i;++j) {
            if (i==j) f[i]=min(f[i],f[i-1]+n*n*a[i]);
            else if (a[i]+a[j]<=t) f[i]=min(f[i],f[j-1]+(a[i]+a[j])*(b[i]-b[j-1]));
        }
    }
    printf("%lld",f[n]);
    return 0;
}