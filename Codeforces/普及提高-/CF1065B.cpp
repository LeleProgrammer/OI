#include <bits/stdc++.h>

#define int long long

using namespace std;

int n,m;
int minn,maxx;

int find(int k) {
    int l=0,r=100000;
    while (l<r) {
        int mid=l+r>>1;
        if (mid*(mid-1)/2>=m) r=mid;
        else l=mid+1;
    }
    return r;
}

signed main() {
    scanf("%lld %lld",&n,&m);
    minn=max(0LL,n-(m*2));
    maxx=max(0LL,n-find(m));
    printf("%lld %lld",minn,maxx);
    return 0;
}