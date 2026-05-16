#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N=10000005;

int n;
bool flag[N];
int pri[N],idx;
int phi[N];
int pre[N];

void init() {
    phi[1]=1;
    for (int i=2;i<N;++i) {
        if (!flag[i]) phi[i]=i-1,pri[++idx]=i;
        for (int j=1;j<=idx && i*pri[j]<N;++j) {
            flag[i*pri[j]]=true;
            if (i%pri[j]==0) {
                phi[i*pri[j]]=phi[i]*pri[j];
                break;
            } else phi[i*pri[j]]=phi[i]*phi[pri[j]];
        }
    }
    for (int i=1;i<N;++i) pre[i]=pre[i-1]+phi[i];
}

int solve(int n) {
    int ans=0;
    for (int i=1;i<=idx;++i) {
        if (!pre[n/pri[i]]) break;
        ans+=2*pre[n/pri[i]]-1;
    }
    return ans;
}

signed main() {
    init();
    scanf("%lld",&n);
    printf("%lld",solve(n));
    return 0;
}