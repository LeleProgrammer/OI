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

const int N=15;

int n;
int a[N],b[N];

int exgcd(int a,int b,int& x,int& y) {
    if (!b) {
        x=1,y=0;
        return a;
    }
    int d=exgcd(b,a%b,y,x);
    y-=a/b*x;
    return x;
}

int mul(int a,int b,int mod) {
    if (!b) return 0;
    if (b==1) return a;
    int k=mul(a,b>>1,mod);
    if (b&1) return (k*2+a)%mod;
    else return k*2%mod;
}

int CRT() {
    int ans=0;
    int nn=1;
    _rep(i,1,n) nn*=b[i];
    _rep(i,1,n) {
        int m=nn/b[i];
        int x,y;
        exgcd(m,b[i],x,y);
        x=(x%b[i]+b[i])%b[i];
        ans=(ans+mul(mul(a[i],m,nn),x,nn))%nn;
    }
    ans=(ans%nn+nn)%nn;
    return ans;
}

signed main() {
    scanf("%lld",&n);
    _rep(i,1,n) scanf("%lld %lld",&b[i],&a[i]);
    printf("%lld",CRT());
    return 0;
}