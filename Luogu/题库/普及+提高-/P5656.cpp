#include <bits/stdc++.h>

#define int long long

using namespace std;

int T;
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
    scanf("%lld",&T);
    while (T--) {
        scanf("%lld %lld %lld",&a,&b,&c);
        int x0=0,y0=0;
        int d=exgcd(a,b,x0,y0);
        if (c%d) {
            puts("-1");
            continue;
        }
        int x1,y1;
        x1=x0*c/d;
        y1=y0*c/d;
        int dx,dy;
        dx=b/d;
        dy=a/d;
        int l,r;
        l=ceil((-x1+1.00)/dx);
        r=floor((y1-1.00)/dy);
        if (l>r) {
            printf("%lld %lld\n",x1+l*dx,y1-r*dy);
            continue;
        }
        printf("%lld ",r-l+1);
        printf("%lld ",x1+dx*l);
        printf("%lld ",y1-dy*r);
        printf("%lld ",x1+dx*r);
        printf("%lld",y1-dy*l);
        putchar(10);
    }
    return 0;
}