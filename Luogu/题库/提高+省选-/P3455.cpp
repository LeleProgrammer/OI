#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N=50005;

int T,a,b,d;
int pri[N],idx;
int mu[N],pre[N];
bool flag[N];

void init() {
    mu[1]=1;
    for (int i=2;i<N;++i) {
        if (!flag[i]) mu[i]=-1,pri[++idx]=i;
        for (int j=1;j<=idx && i*pri[j]<N;++j) {
            flag[i*pri[j]]=true;
            if (i%pri[j]==0) break;
            mu[i*pri[j]]=-mu[i];
        }
    }
    for (int i=1;i<N;++i) pre[i]=pre[i-1]+mu[i];
}

int g(int x,int k) {
    return k/(k/x);
}

int f(int a,int b,int d) {
    a/=d,b/=d;
    int ans=0,mx=min(a,b);
    for (int l=1,r;l<=mx;l=r+1) {
        r=min(mx,min(g(l,a),g(l,b)));
        ans+=(pre[r]-pre[l-1])*(a/l)*(b/l);
    }
    return ans;
}

signed main() {
    init();
    scanf("%lld",&T);
    while (T--) {
        scanf("%lld %lld %lld",&a,&b,&d);
        printf("%lld\n",f(a,b,d));
    }
    return 0;
}