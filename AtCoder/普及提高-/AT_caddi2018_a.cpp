#include <bits/stdc++.h>

#define int long long

using namespace std;

int n,p;
vector<int> ps;
vector<int> cnt;
int ans;

signed main() {
    scanf("%lld %lld",&n,&p);
    if (n==1) {
        printf("%lld\n",p);
        return 0;
    }
    for (int i=2;i*i<=p;++i) {
        if (p%i) continue;
        ps.push_back(i);
        cnt.push_back(0);
        while (p%i==0) {
            p/=i;
            cnt.back()++;
        }
    }
    if (p!=1) {
        ps.push_back(p);
        cnt.push_back(1);
    }
    ans=1;
    for (int i=0;i<cnt.size();++i) {
        while (cnt[i]>=n) {
            cnt[i]-=n;
            ans*=ps[i];
        }
    }
    printf("%lld\n",ans);
    return 0;
}