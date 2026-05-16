#include <bits/stdc++.h>

#define int long long

using namespace std;

int l,n,val;
double mid;
int minn=0;
int maxx=0;

signed main() {
    scanf("%lld",&l);
    mid=(double((1+l)))/2.0;
    scanf("%lld",&n);
    for (int i=1;i<=n;++i) {
        scanf("%lld",&val);
        if (val<=mid) {
            minn=max(minn,val);
            maxx=max(maxx,l-val+1);
        } else {
            minn=max(minn,l-val+1);
            maxx=max(maxx,val);
        }
    }
    printf("%lld %lld",minn,maxx);
    return 0;
}