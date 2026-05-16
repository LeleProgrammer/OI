#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N=50005;

int T,n,m;
int mu[N],G[N],pre[N];
int pri[N],idx;
bool flag[N];

int g(int x,int k) {
    return k/(k/x);
}

void init() {
    mu[1]=1;
    for (int i=2;i<N;++i) {
        if (!flag[i]) pri[++idx]=i,mu[i]=-1;
        for (int j=1;j<=idx && pri[j]*i<N;++j) {
            flag[i*pri[j]]=true;
            if (i%pri[j]==0) break;
            mu[i*pri[j]]=-mu[i];
        }
    }
    for (int i=1;i<N;++i) {
        pre[i]=pre[i-1]+mu[i];
    }
    for (int i=1;i<N;++i) {
        for (int l=1,r;l<=i;l=r+1) {
            r=min(i,g(l,i));
            G[i]+=(r-l+1)*(i/l);
        }
    }
}

int solve() {
    int ans=0;
    int mx=min(n,m);
    for (int l=1,r;l<=mx;l=r+1) {
        r=min(mx,min(g(l,n),g(l,m)));
        ans+=(pre[r]-pre[l-1])*G[n/l]*G[m/l];
    }
    return ans;
}

signed main() {
    init();
    scanf("%lld",&T);
    while (T--) {
        scanf("%lld %lld",&n,&m);
        printf("%lld\n",solve());
    }
    return 0;
}