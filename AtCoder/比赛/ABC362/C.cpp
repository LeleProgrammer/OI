#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N=200005;

int n;
int l[N],r[N];

signed main() {
    scanf("%lld",&n);
    for (int i=1;i<=n;++i) {
        scanf("%lld %lld",&l[i],&r[i]);
    }
    int minSum=0;
    for (int i=1;i<=n;++i) minSum+=l[i];
    int maxSum=0;
    for (int i=1;i<=n;++i) maxSum+=r[i];
    if (minSum<=0 && maxSum>=0) puts("Yes");
    else {
        puts("No");
        return 0;
    }
    int add=0-minSum;
    for (int i=1;i<=n;++i) {
        if (r[i]-l[i]<=add) {
            printf("%d ",r[i]);
            add-=(r[i]-l[i]);
        } else {
            printf("%d ",l[i]+add);
            add=0;
        }
    }
    return 0;
}