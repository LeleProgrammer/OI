#include <bits/stdc++.h>

#define int long long

using namespace std;

const int mod=1000000007;

int w,n,k;

int qpow(int base,int ts) {
    if (ts==1) return base;
    else if (ts%2) {
        int k=qpow(base,ts/2);
        return k*k%mod*base%mod;
    } else {
        int k=qpow(base,ts/2);
        return k*k%mod;
    }
}

int exgcd(int a,int b,int& x,int& y) {
    if (!b) {
        x=1,y=0;
        return a;
    }
    int d=exgcd(b,a%b,x,y);
    int t=x;
    x=y;
    y=t-(a/b)*y;
    return d;
}

signed main() {
    scanf("%lld %lld %lld",&w,&n,&k);
    int a=qpow(2,k);
    int b=mod;
    int x0,y0;
    int d=exgcd(a,b,x0,y0);
    int x1,y1;
    x1=x0/d;
    y1=y0/d;
    int dx=b/d;
    int s;
    s=ceil((-x1+1.00)/dx);
    int x;
    x=x1+s*dx;
    printf("%lld",w*x%mod);
    return 0;
}

/*
w/(2^k) mod 1000000007
*/