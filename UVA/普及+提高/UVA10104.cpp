#include <bits/stdc++.h>

#define int long long

using namespace std;

int a,b;
int x,y;

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
    while (cin>>a>>b) {
        exgcd(a,b,x,y);
        printf("%lld %lld %lld\n",x,y,a*x+b*y);
    }
    return 0;
}