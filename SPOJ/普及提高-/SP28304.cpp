#include <bits/stdc++.h>

#define int long long

using namespace std;

const int p=1000000007;
const int N=1000005;
const int K=1000000;

int n,a,b,d;
int f[N];
int inv[N];

int C(int m,int n) {
    return (f[n]*inv[m]%p)*inv[n-m]%p;
}

int qpow(int base,int ts) {
    if (ts==0) return 0;
    else if (ts==1) return base;
    else if (ts%2) {
        int k=qpow(base,ts/2);
        return (k*k%p)*base%p;
    } else {
        int k=qpow(base,ts/2);
        return k*k%p;
    }
}

signed main() {
    f[1]=1,inv[0]=inv[1]=1;
    for (int i=2;i<=K;++i) f[i]=f[i-1]*i%p;
    for (int i=2;i<=K;++i) inv[i]=(p-(p/i))*inv[p%i]%p;
    for (int i=2;i<=K;++i) inv[i]=inv[i-1]*inv[i]%p;
    while (~scanf("%lld %lld %lld %lld",&n,&a,&b,&d)) {
        printf("%lld\n",C(a,n)*qpow(C(d,b),a)%p);
    }
    return 0;
}