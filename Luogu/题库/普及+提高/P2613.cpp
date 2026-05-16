#include <bits/stdc++.h>

#define int long long

using namespace std;

int p=19260817;
int a,b;

void readin() {
    string s,t;
    cin>>s>>t;
    for (int i=0;i<s.size();++i) {
        int d=s[i]-'0';
        a=a*10+d;
        a%=p;
    }
    for (int i=0;i<t.size();++i) {
        int d=t[i]-'0';
        b=b*10+d;
        b%=p;
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
    readin();
    swap(a,b);
    swap(b,p);
    int x0,y0;
    int d=exgcd(a,b,x0,y0);
    if (p%d) {
        puts("Angry!");
        return 0;
    }
    int x1,y1;
    x1=x0*p/d;
    y1=y0*p/d;
    int dx;
    dx=b/d;
    int s;
    s=ceil((-x1+1.00)/dx);
    printf("%lld",x1+s*dx);
    return 0;
}

/*
bx === a (mod p)
swap a,b
ax === b (mod p)
ax+py=b
swap b,p
ax+by=p
ax0+by0=d
ax1+by1=p
x=x1+sdx
*/