#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N=85;
const int p=998244353;
const int inf=1e18;

int n;
int arr[N];
map<pair<int,int>,int> f[N];
int ans[N];

signed main() {
    scanf("%lld",&n);
    for (int i=1;i<=n;++i) scanf("%lld",&arr[i]);
    for (int i=1;i<=n;++i) {
        f[i].insert({{1,inf},1});
        for (int j=1;j<=i-1;++j) {
            for (auto it=f[j].begin();it!=f[j].end();++it) {
                if (it->first.second==inf) {
                    if (f[i].find({it->first.first+1,arr[i]-arr[j]})==f[i].end()) {
                        f[i].insert({{it->first.first+1,arr[i]-arr[j]},it->second});
                        f[i][{it->first.first+1,arr[i]-arr[j]}]%=p;
                    } else {
                        f[i][{it->first.first+1,arr[i]-arr[j]}]+=it->second;
                        f[i][{it->first.first+1,arr[i]-arr[j]}]%=p;
                    }
                    continue;
                } else if (it->first.second!=arr[i]-arr[j]) continue;
                if (f[i].find({it->first.first+1,arr[i]-arr[j]})==f[i].end()) {
                    f[i].insert({{it->first.first+1,arr[i]-arr[j]},it->second});
                    f[i][{it->first.first+1,arr[i]-arr[j]}]%=p;
                } else {
                    f[i][{it->first.first+1,arr[i]-arr[j]}]+=it->second;
                    f[i][{it->first.first+1,arr[i]-arr[j]}]%=p;
                }
            }
        }
    }
    for (int i=1;i<=n;++i) {
        for (auto it=f[i].begin();it!=f[i].end();++it) {
            // printf("%lld %lld %lld %lld\n",i,it->first.first,it->first.second,it->second);
            ans[it->first.first]+=it->second;
            ans[it->first.first]%=p;
        }
    }
    for (int i=1;i<=n;++i) printf("%lld ",ans[i]);
    return 0;
}