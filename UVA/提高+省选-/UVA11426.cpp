#include <bits/stdc++.h>
using namespace std;

const int N=4000005;

typedef long long LL;

int n;
int phi[N],pri[N];
LL pre[N];
bool flag[N];
int idx;

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
    for (int i=1;i<N;++i) {
        pre[i]=pre[i-1]+phi[i];
    }
}

int g(int x,int k) {
    return k/(k/x);
}

LL solve(int n) {
    LL ans=0;
    for (LL l=1,r;l<=n;l=r+1) {
        r=min(n,g(l,n));
        ans+=(pre[n/l]*2-1)*(l+r)*(r-l+1)/2;
    }
    return (ans-((n+1LL)*n/2))/2;
}

int main() {
    init();
    while (scanf("%d",&n),n) {
        printf("%lld\n",solve(n));
    }
    return 0;
}