#include <bits/stdc++.h>

#define inf 2147483647
#define int long long

using namespace std;

const int N=2000005;

int T;
int n;
int a[N];
map< int,int > hs;

signed main() {
    scanf("%lld",&T);
    while (T--) {
        scanf("%lld",&n);
        hs.clear();
        int ans=0;
        for (int i=1;i<=n;++i) {
            scanf("%lld",&a[i]);
            hs[a[i]]++;
        }
        for (auto it1=hs.begin();it1!=hs.end();++it1) {
            if (it1->second==0) continue;
            int need=inf^(it1->first);
            auto it2=hs.find(need);
            if (it2!=hs.end()) {
                ans+=max(it1->second,it2->second);
                it1->second=0;
                it2->second=0;
            } else {
                ans+=it1->second;
                it1->second=0;
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}