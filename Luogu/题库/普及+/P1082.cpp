#include <bits/stdc++.h>

#define int long long

using namespace std;

int a,b,c;

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
    scanf("%lld %lld",&a,&b); c=1;
    int x,y;
    int d=exgcd(a,b,x,y);
    int x1,y1;
    x1=x*c/d;
    y1=y*c/d;
    int dx=b/d;
    int s=ceil((-x1+1.00)/dx);
    printf("%lld",x1+s*dx);
    return 0;
}

// ax == 1 (mod b)
// ax+by=1
// x=x1+sdx
// y=y1-sdy
// x1+sdx>0
// sdx>-x1
// s>-x1/dx
// dx=b/d
// s>=ceil((-x1+1)/dx)