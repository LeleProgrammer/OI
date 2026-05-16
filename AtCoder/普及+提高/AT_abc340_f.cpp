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
    scanf("%lld %lld",&a,&b);
    swap(a,b); c=2;
    int x0,y0;
    int d=exgcd(a,-b,x0,y0);
    if (c%d) {
        puts("-1");
        return 0;
    }
    int x1,y1;
    x1=x0*c/d;
    y1=y0*c/d;
    printf("%lld %lld",x1,y1);
    return 0;
}