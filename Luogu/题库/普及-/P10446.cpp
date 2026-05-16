#include <bits/stdc++.h>

#define int long long

using namespace std;

int a,b,p;

int f(int t) {
    if (t==1) return a%p;
    else if (t%2) {
        int k=f(t/2);
        return (k+k+a)%p;
    } else {
        int k=f(t/2);
        return (k+k)%p;
    }
}

signed main() {
    scanf("%lld %lld %lld",&a,&b,&p);
    printf("%lld",f(b));
    return 0;
}