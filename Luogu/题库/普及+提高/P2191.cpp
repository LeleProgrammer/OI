#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N=38;

double n;

int gcd(int a,int b) {
    if (!b) return a;
    return gcd(b,a%b);
}

struct Frac {
    int a,b;
    Frac() {
        this->a=0;
        this->b=1;
    }
    Frac(int a,int b) {
        this->a=a;
        this->b=b;
        assert(b!=0);
    }
    friend Frac operator + (Frac a,Frac b) {
        int g=a.b*b.b;
        a.a*=b.b;
        b.a*=a.b;
        a.a+=b.a;
        a.b=g;
        int d=gcd(a.a,a.b);
        a.a/=d;
        a.b/=d;
        return a;
    }
};

int get_digit(int k) {
    int ans=0;
    while (k) k/=10,ans++;
    return ans;
}

Frac f[N];

signed main() {
    scanf("%lf",&n);
    for (int i=1;i<=n;++i) {
        f[i]=f[i-1]+Frac(n,n-(i-1));
    }
    Frac& ans=f[signed(n)];
    int d=gcd(ans.a,ans.b);
    ans.a/=d,ans.b/=d;
    int k=ans.a/ans.b;
    ans.a-=k*ans.b;
    if (!ans.a) {
        printf("%lld",k);
        return 0;
    }
    int t=get_digit(k);
    int t2=max(get_digit(ans.a),get_digit(ans.b));
    for (int i=1;i<=t;++i) printf(" ");
    printf("%lld\n",ans.a);
    printf("%lld",k);
    for (int i=1;i<=t2;++i) printf("-");
    putchar(10);
    for (int i=1;i<=t;++i) printf(" ");
    printf("%lld",ans.b);
    return 0;
}