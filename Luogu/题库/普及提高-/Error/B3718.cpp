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

const int N=5000005;
const int mod=998244353;

int T,n,m;
int mul[N];
int m5[N],m6[N];
int invm5[N],invm6[N],invmul[N];
int res;

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
    return x;
}

void init() {
    mul[1]=1;
    _rep(i,2,N-1) mul[i]=(mul[i-1]*i)%mod;
    m5[0]=m6[0]=1;
    _rep(i,1,N-1) m5[i]=(m5[i-1]*5)%mod,m6[i]=(m6[i-1]*6)%mod;
    invmul[1]=inv(mul[1],mod);
    _rep(i,2,N-1) invmul[i]=(invmul[i-1]*i)%mod;
    invm5[0]=invm6[0]=inv(m5[0],mod);
    invm5[1]=inv(m5[1],mod);
    invm6[1]=inv(m6[1],mod);
    _rep(i,2,N-1) invm5[i]=(invm5[i-1]*5)%mod,invm6[i]=(invm6[i-1]*6)%mod;
}

signed main() {
    printf("gu\n");
    init();
    scanf("%lld",&T);
    while (T--) {
        scanf("%lld %lld",&n,&m);
        int up=(mul[n]*m5[n-m])%mod;
        int down=(((invmul[n-m]*invmul[m])%mod)*invm6[n])%mod;
        int ans=up*down;
        ans=(ans%mod+mod)%mod;
        res^=ans;
    }
    printf("%lld",res);
    return 0;
}