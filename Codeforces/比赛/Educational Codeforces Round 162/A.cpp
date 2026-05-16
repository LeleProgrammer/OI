#include <bits/stdc++.h>
using namespace std;

int T,n;
int a[55];
int cnt;

int main() {
    scanf("%d",&T);
    while (T--) {
        scanf("%d",&n);
        cnt=0;
        for (int i=1;i<=n;++i) {
            scanf("%d",&a[i]);
        }
        int l,r;
        for (l=1;l<=n && !a[l];++l);
        for (r=n;r>=1 && !a[r];--r);
        cnt=0;
        for (int i=l;i<=r;++i) {
            if (!a[i]) {
                cnt++;
            }
        }
        printf("%d\n",cnt);
    }
    return 0;
}