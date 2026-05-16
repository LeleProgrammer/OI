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

const int N=10000005;
const int mod=20101009;

int n,m;
int mu[N],pri[N],idx,pre[N];
bool flag[N];

void init() {
    mu[1]=1;
    _rep(i,2,N-1) {
        if (!flag[i]) pri[++idx]=i,mu[i]=-1;
        _rep(j,1,idx) {
            if (i*pri[j]>=N) break;
            mu[i*pri[j]]=-mu[i];
            flag[i*pri[j]]=true;
            if (i%pri[j]==0) {
                mu[i*pri[j]]=0;
                break;
            }
        }
    }
    _rep(i,1,N-1) pre[i]=(pre[i-1]+mu[i]*i*i)%mod;
}

int calc(int n,int x) {
    return n/(n/x);
}

int g(int n,int m) {
    return (n*(n+1)/2%mod)*(m*(m+1)/2%mod)%mod;
}

int MOD(int x) {
    return (x%mod+mod)%mod;
}

int S(int n,int m) {
    int ans=0;
    int l=1,r=0;
    while (l<=min(n,m)) {
        r=min(calc(n,l),calc(m,l));
        ans=(ans+g(n/l,m/l)*MOD(pre[r]-pre[l-1]))%mod;
        l=r+1;
    }
    return ans;
}

int solve(int n,int m) {
    int ans=0;
    int l=1,r=0;
    while (l<=min(n,m)) {
        r=min(calc(n,l),calc(m,l));
        ans=(ans+S(n/l,m/l)*((l+r)*(r-l+1)/2%mod))%mod;
        l=r+1;
    }
    return ans;
}

signed main() {
    init();
    scanf("%lld %lld",&n,&m);
    printf("%lld",solve(n,m));
    return 0;
}