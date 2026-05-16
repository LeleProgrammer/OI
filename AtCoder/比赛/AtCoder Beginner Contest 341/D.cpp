#include <bits/stdc++.h>

#define int long long

using namespace std;

int n,m,k;

int gcd(int a,int b) {
    if (a<b) swap(a,b);
    return b==0?a:(gcd(b,a%b));
}

int lcm(int a,int b) {
    return a/gcd(a,b)*b;
}

signed main() {
    scanf("%lld %lld %lld",&n,&m,&k);
    // for (int i=1;i<=lcm(n,m);++i) {
    //     if (i%n==0 && i%m!=0) printf("%lld ",n);
    //     else if (i%m==0 && i%n!=0) printf("%lld ",m);
    // }
    if (n>m) swap(n,m);
    int g=lcm(n,m);
    int a,b,s;
    a=g/n-1;
    b=g/m-1;
    s=a+b;
    int times=k/s;
    k%=s;
    if (k==0) printf("%lld",g*times-n);
    else {
        a=g/n*times;
        b=g/m*times+1;
        int ans;
        while (k) {
            ans=(a+1)*n;
            if (ans>b*m) {
                ans=b*m;
                b++;
            } else {
                a++;
            }
            k--;
        }
        printf("%lld",ans);
    }
    return 0;
}

/*
2 3 4 8 9 10 14 15 16 20 21 22 26 27 28 32 33
2 3 2 2 3 2  2  3  2  2  3  2  2  3  2  2  3
*/