#include <bits/stdc++.h>

#define int long long

using namespace std;

int a,p,b;

int bsgs(int a,int b,int p) {
    a%=p,b%=p;
    if (1%p==b%p) return 0;
    int k=sqrt(p)+1;
    int ak=1;
    for (int i=1;i<=k;++i) ak*=a,ak%=p;
    unordered_map<int,int> hs;
    for (int y=0,i=b;y<=k-1;++y,i=i*a%p) hs[i]=y;
    for (int x=1,i=ak;x<=k;++x,i=i*ak%p) if (hs.count(i)) return k*x-hs[i];
    return -1;
}

signed main() {
    while (scanf("%lld %lld %lld",&a,&p,&b),a || p || b) {
        int ans=bsgs(a,b,p);
        if (~ans) printf("%lld\n",ans);
        else puts("No Solution");
    }
    return 0;
}