#include <bits/stdc++.h>

#define int long long

using namespace std;

int n;

int H(int n) {
    int ans=0;
    int i=1,j=1;
    while (i<=n) {
        j=n/(n/i);
        ans=ans+(j-i+1)*(n/i);
        i=j+1;
    }
    return ans;
}

signed main() {
    scanf("%lld",&n);
    while (n--) {
        int v;
        scanf("%lld",&v);
        printf("%lld\n",H(v));
    }
    return 0;
}