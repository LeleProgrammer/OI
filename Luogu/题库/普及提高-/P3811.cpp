#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N=3000005;

int n,p;
int a[N];

signed main() {
    scanf("%d %d",&n,&p);
    a[1]=1;
    for (int i=2;i<=n;++i) {
        a[i]=((p-p/i)*(a[p%i]))%p;
    }
    for (int i=1;i<=n;++i) {
        printf("%lld\n",a[i]);
    }
    return 0;
}