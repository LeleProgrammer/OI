#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N=200005;

int T,n,k;
int a[N];

bool cmp(const int& a,const int& b) {
    return a<b;
}

int get(int k) {
    if (!k) return 0;
    else if (k==1) return 1;
    else return k*2-1;
}

signed main() {
    scanf("%lld",&T);
    while (T--) {
        scanf("%lld %lld",&n,&k);
        for (int i=1;i<=k;++i) {
            scanf("%lld",&a[i]);
        }
        sort(a+1,a+1+k,cmp);
        int now=a[k];
        int ans=0;
        for (int i=1;i<=k-1;++i) {
            int need;
            if (now+a[i]>n) {
                need=n-now;
            } else {
                need=a[i];
            }
            now+=need;
            ans+=get(need);
        }
        printf("%lld\n",ans);
    }
    return 0;
}