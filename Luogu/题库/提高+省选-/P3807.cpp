#include <bits/stdc++.h>
using namespace std;

#define int long long

#define endl '\n'
#define FRR(file) freopen(file,"r",stdin)
#define FRW(file) freopen(file,"w",stdout)
#define TIMESTAMP cerr<<fixed<<setprecision(3)<<clock()*1.0/CLOCKS_PER_SEC<<"s"<<endl;
#define _rep(i,a,b) for (int i=(a);i<=(b);++i)
#define _reps(i,a,b,c) for (int i=(a);i<=(b);c)
#define _rrep(i,a,b) for (int i=(a);i>=(b);--i)
#define _rreps(i,a,b,c) for (int i=(a);i>=(b);c)
#define _iter(i,a) for (auto i=a.begin();i!=a.end();++i)
#define _graph(i,u) for (int i=h[u];~i;i=ne[i])
#define rint register int
#define LL long long
typedef pair<int,int> pii;

const int N=100005;

int T,n,m,p;
int f[N];

int exgcd(int a,int b,int& x,int& y) {
    if (!b) {
        x=1,y=0;
        return a;
    }
    int d=exgcd(b,a%b,y,x);
    y-=a/b*x;
    return d;
}

int inv(int a,int p) {
    int x,y;
    exgcd(a,p,x,y);
    return (x%p+p)%p;
}

int C(int a,int b) {
    if (a<b) return 0;
    return (f[a]*inv(f[b],p)%p)*inv(f[a-b],p)%p;
}

int lucas(int a,int b) {
    if (!b) return 1;
    return lucas(a/p,b/p)*C(a%p,b%p)%p;
}

signed main() {
    scanf("%lld",&T);
    while (T--) {
        scanf("%lld %lld %lld",&n,&m,&p);
        f[0]=1;
        _rep(i,1,N-1) f[i]=(f[i-1]*i)%p;
        printf("%lld\n",lucas(n+m,n));
    }
    return 0;
}