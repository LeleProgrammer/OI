#include <bits/stdc++.h>
using namespace std;

const int N=105;

int T,n,a[N];

int main() {
    scanf("%d",&T);
    while (T--) {
        scanf("%d",&n);
        for (int i=1;i<=n;++i) {
            scanf("%d",&a[i]);
        }
        int last=0;
        for (int i=1;i<=n;++i) {
            if (!last) {
                last=a[i]+1;
            } else {
                int times=last/a[i];
                if (last%a[i]) times++;
                last=times*a[i]+1;
            }
        }
        printf("%d\n",last-1);
    }
    return 0;
}