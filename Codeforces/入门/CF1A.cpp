#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

int main() {
    LL n,m,a;
    scanf("%lld %lld %lld",&n,&m,&a);
    LL l=n/a;
    if (n%a) ++l;
    LL r=m/a;
    if (m%a) ++r;
    printf("%lld",l*r);
    return 0;
}