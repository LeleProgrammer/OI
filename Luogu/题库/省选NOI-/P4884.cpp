#include <bits/stdc++.h>
using namespace std;

#define int long long

#define endl '\n'
#define FRR(file) freopen(file,"r",stdin)
#define FRW(file) freopen(file,"w",stdout)
#define _rep(i,a,b) for (int i=(a);i<=(b);++i)
#define _reps(i,a,b,c) for (int i=(a);i<=(b);c)
#define _rrep(i,a,b) for (int i=(a);i>=(b);--i)
#define _rreps(i,a,b,c) for (int i=(a);i>=(b);c)
#define _iter(i,a) for (auto i=a.begin();i!=a.end();++i)
#define _graph(i,u) for (int i=h[u];~i;i=ne[i])
#define rint register int
#define LL long long
typedef pair<int,int> pii;

const int inf=1e18;

int K,p;

int mul(int a,int b) {
    if (b==0) return 0;
    if (b==1) return a;
    int k=mul(a,b>>1);
    if (b&1) return (((k+k)%p)+a)%p;
    return (k+k)%p;
}

int bsgs(int a,int b,int p) {
    a%=p,b%=p;
    if (1%p==b%p) return 0;
    int k=sqrt(p)+1;
    int ak=1;
    _rep(i,1,k) ak=mul(ak,a)%p;
    unordered_map<int,int> hs;
    int i=b;
    _rep(y,0,k-1) hs[i]=y%p,i=mul(i,a)%p;
    i=ak;
    _rep(x,1,k) {
        if (hs.count(i)) return mul(k,x)-hs[i];
        i=mul(i,ak)%p;
    }
    return -inf;
}

signed main() {
    scanf("%lld %lld",&K,&p);
    int ans=bsgs(10,9*K+1,p);
    if (ans==-inf) puts("I AK IOI");
    else printf("%lld",(ans%p+p)%p);
    return 0;
}