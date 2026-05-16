#include <bits/stdc++.h>

#define int long long

using namespace std;

int T,n,a,b;

signed main() {
    scanf("%lld",&T);
    while (T--) {
        scanf("%lld %lld %lld",&n,&a,&b);
        if (a==1) {
            if ((n-1)%b) puts("No");
            else puts("Yes");
        } else {
            int k=1;
            bool ok=false;
            while (k<=n) {
                int d=n-k;
                if (d%b==0) {
                    ok=true;
                    break;
                }
                k*=a;
            }
            if (ok) puts("Yes");
            else puts("No");
        }
    }
    return 0;
}