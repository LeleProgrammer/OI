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

int k;
int a[N],b[N];

__int128 exgcd(__int128 a,__int128 b,__int128& x,__int128& y) {
    if (!b) {
        x=1,y=0;
        return a;
    }
    int d=exgcd(b,a%b,y,x);
    y-=a/b*x;
    return d;
}

__int128 crt() {
    __int128 n=1;
    _rep(i,1,k) n*=b[i];
    __int128 ans=0;
    _rep(i,1,k) {
        __int128 m=n/b[i];
        __int128 x,y;
        exgcd(m,b[i],x,y);
        x=(x%b[i]+b[i])%b[i];
        ans+=(a[i]*m%n)*x;
        ans%=n;
    }
    return ans;
}

void print(__int128 k) {
    if (!k) return;
    print(k/10);
    printf("%lld",(int)(k%10));
}

signed main() {
    scanf("%lld",&k);
    _rep(i,1,k) scanf("%lld",&a[i]);
    _rep(i,1,k) scanf("%lld",&b[i]);
    int ans=crt();
    if (ans) print(crt());
    else puts("0");
    return 0;
}