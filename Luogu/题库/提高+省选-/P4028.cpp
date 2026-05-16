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

int T;

int exgcd(int a,int b,int& x,int& y) {
    if (!b) {
        x=1,y=0;
        return a;
    }
    int d=exgcd(b,a%b,y,x);
    y-=a/b*x;
    return d;
}

int bsgs(int a,int b,int p) {
    a=(a%p+p)%p,b=(b%p+p)%p;
    if (1%p==b%p) return 0;
    int k=sqrt(p)+1;
    int ak=1;
    _rep(i,1,k) ak=ak*a%p;
    unordered_map<int,int> hs;
    int i=b;
    _rep(y,0,k-1) hs[i]=y,i=i*a%p;
    i=ak;
    _rep(x,1,k) {
        if (hs.count(i)) return k*x-hs[i];
        i=i*ak%p;
    }
    return -inf;
}

int exbsgs(int a,int b,int p) {
    a=(a%p+p)%p,b=(b%p+p)%p;
    if (1%p==b%p) return 0;
    int x,y;
    int d=exgcd(a,p,x,y);
    if (b%d) return -inf;
    if (d==1) return bsgs(a,b,p);
    b/=d,p/=d;
    exgcd(a/d,p,x,y);
    x=(x%p+p)%p;
    return exbsgs(a,b/d*x,p)+1;
}

signed main() {
    scanf("%lld",&T);
    while (T--) {
        int p,a,b;
        scanf("%lld %lld %lld",&p,&a,&b);
        if (b%p==0) puts("Couldn't Produce!");
        else {
            int ans=exbsgs(a,b,p);
            if (ans<0) puts("Couldn't Produce!");
            else printf("%lld\n",ans);
        }
    }
    return 0;
}