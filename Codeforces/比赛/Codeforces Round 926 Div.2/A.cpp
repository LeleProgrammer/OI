#include <bits/stdc++.h>
using namespace std;

int T,n,a;

int main() {
    scanf("%d",&T);
    while (T--) {
        scanf("%d",&n);
        int maxx=0,minn=1000000001;
        for (int i=1;i<=n;++i) {
            scanf("%d",&a);
            maxx=max(maxx,a);
            minn=min(minn,a);
        }
        printf("%d\n",maxx-minn);
    }
    return 0;
}