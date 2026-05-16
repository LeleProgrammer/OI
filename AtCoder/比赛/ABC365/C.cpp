#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N=200005;

int n,m;
int arr[N];

bool check(int mid) {
    int sum=0;
    for (int i=1;i<=n;++i) {
        sum+=min(mid,arr[i]);
        if (sum>m) return false;
    }
    return true;
}

signed main() {
    scanf("%lld %lld",&n,&m);
    for (int i=1;i<=n;++i) {
        scanf("%lld",&arr[i]);
    }
    if (check(m+1)) {
        puts("infinite");
        return 0;
    }
    int l=0,r=m;
    while (l<r) {
        int mid=(l+r>>1)+1;
        if (check(mid)) l=mid;
        else r=mid-1;
    }
    printf("%lld",l);
    return 0;
}