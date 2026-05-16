#include <bits/stdc++.h>

#define int long long

using namespace std;

int a;
int val=0;

signed main() {
    scanf("%lld",&a);
    while (a--) {
        int x;
        scanf("%lld",&x);
        val^=x;
    }
    printf("%lld 0",val);
    return 0;
}