#include <bits/stdc++.h>

#define int long long

using namespace std;

int p,b,n;

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
    scanf("%lld %lld %lld",&p,&b,&n);
    int ans=bsgs(b,n,p);
    if (~ans) printf("%lld",ans);
    else printf("no solution");
    return 0;
}