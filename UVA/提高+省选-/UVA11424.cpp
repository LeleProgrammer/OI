#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N=200005;

int n;
int phi[N],pre[N],pri[N],idx;
bool flag[N];

void init() {
    phi[1]=1;
    for (int i=2;i<N;++i) {
        if (!flag[i]) pri[++idx]=i,phi[i]=i-1;
        for (int j=1;j<=idx && i*pri[j]<N;++j) {
            flag[i*pri[j]]=true;
            if (i%pri[j]==0) {
                phi[i*pri[j]]=phi[i]*pri[j];
                break;
            }
            phi[i*pri[j]]=phi[i]*phi[pri[j]];
        }
    }
    for (int i=1;i<N;++i) pre[i]=pre[i-1]+phi[i];
}

int g(int x,int k) {
    return k/(k/x);
}

int solve(int n) {
    int ans=0;
    for (int l=1,r;l<=n;l=r+1) {
        r=min(n,g(l,n));
        ans+=(pre[n/l]*2-1)*((l+r)*(r-l+1)/2);
    }
    return (ans-((1+n)*n/2))/2;
}

signed main() {
    init();
    while (scanf("%lld",&n),n) {
        printf("%lld\n",solve(n));
    }
    return 0;
}