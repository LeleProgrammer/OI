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

const int N=1000005;

int n,m;
int f[N],l[N],r[N],mul[N];

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
    x=(x%p+p)%p;
    return x;
}

int C(int a,int b) {
    if (a<b) return 0;
    // cout<<a<<" "<<b<<" "<<mul[a]<<" "<<mul[b]<<" "<<mul[a-b]<<endl;
    return (mul[a]*inv(mul[b],m)%m)*inv(mul[a-b],m)%m;
}

int lucas(int a,int b) {
    if (!b) return 1;
    if (a<N && b<N && b<m) return C(a,b);
    return lucas(a/m,b/m)*lucas(a%m,b%m)%m;
}

signed main() {
    scanf("%lld %lld",&n,&m);
    mul[0]=1;
    _rep(i,1,N-1) mul[i]=(mul[i-1]*i)%m;
    _rep(i,2,n) {
        int j=i;
        while (j>3) j/=2;
        if (j==2) l[i]=l[i-1]+1,r[i]=r[i-1];
        else r[i]=r[i-1]+1,l[i]=l[i-1];
    }
    f[0]=f[1]=1;
    _rep(i,2,n) f[i]=(lucas(i-1,l[i])*f[l[i]]%m)*f[r[i]]%m;
    // _rep(i,1,n) printf("%lld\n",f[i]);
    printf("%lld",f[n]);
    return 0;
}