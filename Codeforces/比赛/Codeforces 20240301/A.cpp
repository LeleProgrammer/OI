#include <bits/stdc++.h>
using namespace std;

const int N=105;

int T,n;
int a[N];

int main() {
    scanf("%d",&T);
    while (T--) {
        scanf("%d",&n);
        for (int i=1;i<=n;++i) {
            scanf("%d",&a[i]);
        }
        sort(a+1,a+1+n);
        printf("%d\n",abs(a[n]-a[1])+abs(a[1]-a[n-1])+abs(a[n-1]-a[2])+abs(a[2]-a[n]));
    }
    return 0;
}