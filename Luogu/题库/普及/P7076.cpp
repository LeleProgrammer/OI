#include <bits/stdc++.h>

#define int unsigned long long

using namespace std;

const int N=1000005;

int n,m,c,k;
int a[N];
bool flag[65];

signed main() {
    scanf("%llu %llu %llu %llu",&n,&m,&c,&k);
    if (!n && !m && k==64) {
        int t=1;
        for (int i=2;i<=64;++i) {
            t<<=1;
            t|=1;
        }
        string ans=to_string(t);
        ans.back()++;
        cout<<ans;
        return 0;
    }
    int t=0;
    for (int i=1;i<=n;++i) {
        scanf("%llu",&a[i]);
        t|=a[i];
    }
    while (m--) {
        int p,q;
        scanf("%llu %llu",&p,&q); p++;
        flag[p]=true;
    }
    for (int i=1;i<=k;++i) {
        if (!flag[i]) t|=(1ull<<(i-1));
    }
    int ans=1;
    while (t && k--) {
        int v=t&1;
        t>>=1;
        if (v) ans<<=1;
    }
    ans-=n;
    printf("%llu",ans);
    return 0;
}