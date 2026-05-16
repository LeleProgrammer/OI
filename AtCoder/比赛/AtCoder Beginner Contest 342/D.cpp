#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N=200005;

int n;
int a[N];

unordered_map<int,int> hs;

int rem(int k) {
    for (int i=2;i<=sqrt(k)+1;++i) {
        while (k%(i*i)==0) {
            k/=i*i;
        }
    }
    return k;
}

signed main() {
    scanf("%lld",&n);
    for (int i=1;i<=n;++i) {
        scanf("%lld",&a[i]);
        hs[rem(a[i])]++;
    }
    int ans=0;
    for (auto it=hs.begin();it!=hs.end();++it) {
        if (it->first==0) continue;
        int v=it->second;
        ans+=v*(v-1)/2;
        // cout<<it->first<<" "<<it->second<<" "<<ans<<endl;
    }
    for (int i=0;i<hs[0];++i) {
        ans+=(n-i-1);
    }
    // for (int i=1;i<hs[1];++i) {
    //     ans+=(n-i-1);
    // }
    printf("%lld",ans);
    return 0;
}