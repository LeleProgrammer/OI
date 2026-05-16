#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N=100005;

int n,a,b;
int w[N];

bool check(int k) {
    int t=k;
    for (int i=1;i<=n;++i) {
        int r=w[i]-k*b;
        if (r<=0) continue;
        t-=r/(a-b);
        if (r%(a-b)) t--;
        if (t<0) return false;
    }
    return true;
}

signed main() {
    scanf("%lld %lld %lld",&n,&a,&b);
    for (int i=1;i<=n;++i) {
        scanf("%lld",&w[i]);
    }
    int l=1,r=1e9;
    while (l<r) {
        int mid=l+r>>1;
        if (check(mid)) r=mid;
        else l=mid+1;
    }
    printf("%lld",l);
    return 0;
}