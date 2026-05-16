#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N=45;

int n;
int f[N];
vector<int> ans;

int qpow(int a,int b) {
    if (b==0) return 1;
    if (b==1) return a;
    if (b%2) {
        int k=qpow(a,b/2);
        return k*k*a;
    } else {
        int k=qpow(a,b/2);
        return k*k;
    }
}

signed main() {
    scanf("%lld",&n);
    if (n<=10) {
        printf("%lld\n",n-1);
        return 0;
    }
    f[1]=10;
    f[2]=9;
    for (int i=4;i<N;i+=2) {
        f[i]=f[i-1]=f[i-2]*10;
        if (f[i]>=1e18) break;
    }
    int k=0,d;
    for (d=0;d<N;++d) {
        if (k+f[d]<n) k+=f[d];
        else break;
    }
    int left=n-k-1;
    int t=qpow(10,d/2+d%2-1)+left;
    printf("%lld",t);
    if (d%2) t/=10;
    while (t) {
        printf("%lld",t%10);
        t/=10;
    }
    putchar(10);
    return 0;
}