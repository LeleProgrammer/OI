#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N=2000005;

int n;
int pri[N],idx;
int phi[N],pre[N];
bool flag[N];
int ans;

void init() {
    phi[1]=1;
    for (int i=2;i<N;++i) {
        if (!flag[i]) pri[++idx]=i,phi[i]=i-1;
        for (int j=1;j<=idx && pri[j]*i<N;++j) {
            flag[i*pri[j]]=true;
            if (i%pri[j]==0) {
                phi[i*pri[j]]=phi[i]*pri[j];
                break;
            } else phi[i*pri[j]]=phi[i]*phi[pri[j]];
        }
    }
    for (int i=1;i<N;++i) pre[i]=pre[i-1]+phi[i];
}

signed main() {
    init();
    scanf("%lld",&n);
    for (int i=1;i<=n;++i) ans+=(2*pre[n/i]-1)*i;
    ans=ans-(1+n)*n/2;
    ans/=2;
    printf("%lld",ans);
    return 0;
}