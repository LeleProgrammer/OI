#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N=1000005;

int n;
bool flag[N];
int pri[N],idx;

void init() {
    for (int i=2;i<N;++i) {
        if (!flag[i]) pri[++idx]=i;
        for (int j=1;j<=idx && i*pri[j]<N;++j) {
            flag[i*pri[j]]=true;
            if (i%pri[j]==0) break;
        }
    }
}

signed main() {
    init();
    scanf("%lld",&n);
    for (int i=1;i<=idx && pri[i]<=n;++i) {
        int cnt=0;
        for (int j=pri[i];j<=n;j*=pri[i]) cnt+=n/j;
        if (cnt) printf("%lld %lld\n",pri[i],cnt);
    }
    return 0;
}