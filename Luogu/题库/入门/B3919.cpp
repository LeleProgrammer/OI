#include <bits/stdc++.h>

#define int long long

using namespace std;

int n,q,k;
int ans=0;

signed main() {
    scanf("%lld %lld",&n,&q);
    while (q--) {
        scanf("%lld",&k);
        if ((n>>(k-1))&1==1) continue;
        int t=1LL<<(k-1);
        int tmp=n%(1LL<<k);
        ans+=t-tmp;
        n>>=k;
        n<<=k;
        n+=t;
    }
    printf("%lld",ans);
    return 0;
}