#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N=4005;
const int M=16000005;

int T;
int n;
int a[N],b[N],c[N],d[N];
int l[M],r[M],tot;
int ans;

signed main() {
    scanf("%lld",&T);
    while (T--) {
        scanf("%lld",&n);
        for (int i=1;i<=n;++i) {
            scanf("%lld %lld %lld %lld",&a[i],&b[i],&c[i],&d[i]);
        }
        tot=0;
        for (int i=1;i<=n;++i) {
            for (int j=1;j<=n;++j) {
                int add=a[i]+b[j];
                l[++tot]=add;
            }
        }
        tot=0;
        for (int i=1;i<=n;++i) {
            for (int j=1;j<=n;++j) {
                int add=c[i]+d[j];
                r[++tot]=add;
            }
        }
        sort(r+1,r+1+tot,less<int>());
        ans=0;
        for (int i=1;i<=tot;++i) {
            auto t1=lower_bound(r+1,r+1+tot,-l[i]);
            auto t2=upper_bound(r+1,r+1+tot,-l[i]);
            ans+=(int)(t2-t1);
        }
        printf("%lld\n",ans);
        if (T) putchar(10);
    }
    return 0;
}