#include <bits/stdc++.h>

#define int long long

using namespace std;

int n;
int k=1;

int gcd(int a,int b) {
    if (a<b) swap(a,b);
    if (!b) return a;
    return gcd(b,a%b);
}

int lcm(int a,int b) {
    return a/gcd(a,b)*b;
}

signed main() {
    scanf("%lld",&n);
    while (n--) {
        int v;
        scanf("%lld",&v);
        k=lcm(k,v);
    }
    printf("%lld\n",k);
    return 0;
}