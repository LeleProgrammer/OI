#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N=200005;

int T,n,b,x,c[N],sum,ans;

int pw(int a,int b) { // 快速幂
    if (b==0) return 1;
    if (b==1) return a;
    if (b%2) {
        int k=pw(a,b/2);
        return k*k*a;
    }
    int k=pw(a,b/2);
    return k*k;
}

int divv(int a,int k) { // a 分成 k 份，使乘积最大
    int d=a/k;
    int r=a%k;
    int ans=pw(d+1,r)*pw(d,k-r);
    return ans;
}

signed main() {
    scanf("%lld",&T);
    while (T--) {
        scanf("%lld %lld %lld",&n,&b,&x);
        for (int i=1;i<=n;++i) {
            scanf("%lld",&c[i]);
            sum+=c[i];
        }
        ans=0;
        for (int i=2;i<=sum;++i) {
            int r=-(i-1)*x;
            for (int j=1;j<=n;++j) {
                r+=divv(c[j],i)*b;
            }
            ans=max(ans,r);
        }
        printf("%lld\n",ans);
    }
    return 0;
}