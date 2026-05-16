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

int T,op,y,z,p;

int qpow(int a,int b) {
    if (!b) return 1;
    if (b==1) return a;
    int k=qpow(a,b>>1);
    if (b&1) return (k*k%p)*a%p;
    return k*k%p;
}

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
    return exbsgs(a,b/d*((x%p+p)%p),p);
}

signed main() {
    scanf("%lld %lld",&T,&op);
    while (T--) {
        scanf("%lld %lld %lld",&y,&z,&p);
        if (op==1) printf("%lld\n",qpow(y,z)%p);
        else if (op==2) {
            int x,y2;
            int d=exgcd(y,p,x,y2);
            if (z%d) puts("Orz, I cannot find x!");
            else {
                int t=p/d;
                x=x*z/d;
                printf("%lld\n",(x%t+t)%t);
            }
        } else {
            if (z%p==0) {
                if (y%p==0) puts("1");
                else puts("Orz, I cannot find x!");
                continue;
            }
            int ans=exbsgs(y,z,p);
            if (ans<0) puts("Orz, I cannot find x!");
            else printf("%lld\n",ans);
        }
    }
    return 0;
}