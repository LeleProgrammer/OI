#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N=300005;
const int mod=100000000;

int n;
int a[N];
int ans;
int cnt;

bool cmp(const int& a,const int& b) {
    return a<b;
}

signed main() {
    scanf("%lld",&n);
    for (int i=1;i<=n;++i) {
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+1+n,cmp);
    int l=1,r=n;
    while (l<=r) {
        while (l<=r) {
            if (a[l]+a[r]<mod) l++;
            else break;
        }
        if (l>r) break;
        cnt+=r-l;
        r--;
    }
    ans-=cnt*mod;
    for (int i=1;i<=n;++i) {
        ans+=a[i]*(n-1);
    }
    printf("%lld",ans);
    return 0;
}