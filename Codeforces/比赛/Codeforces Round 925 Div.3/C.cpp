#include <bits/stdc++.h>
using namespace std;

const int N=200005;

int T,n;
int a[N];

int main() {
    scanf("%d",&T);
    while (T--) {
        scanf("%d",&n);
        for (int i=1;i<=n;++i) {
            scanf("%d",&a[i]);
        }
        int l,r;
        for (l=2;a[l-1]==a[l] && l<=n;++l);
        --l;
        for (r=2;a[n-r+1]==a[n-r+2] && r<=n;++r);
        --r;
        int ans;
        if (a[l]==a[n-r+1]) {
            if ((l+r)>=n) ans=0;
            else ans=n-l-r;
        }
        else ans=n-max(l,r);
        printf("%d\n",ans);
    }
    return 0;
}