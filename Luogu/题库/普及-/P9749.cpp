#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N=100005;
const int inf=9e18;

int n,d;
int a[N],b[N];
int minn,dis,ans;

signed main() {
    scanf("%lld %lld",&n,&d);
    for (int i=2;i<=n;++i) scanf("%lld",&a[i]),a[i]+=a[i-1];
    for (int i=1;i<=n;++i) scanf("%lld",&b[i]);
    minn=inf;
    for (int i=1;i<=n;++i) {
        int k=a[i]-dis;
        if (k>0) {
            int need=k/d;
            if (k%d) need++;
            ans+=need*minn;
            dis+=need*d;
        }
        minn=min(minn,b[i]);
    }
    printf("%lld",ans);
    return 0;
}