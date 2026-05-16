#include <bits/stdc++.h>
using namespace std;

const int N=200005;

int T,n;
int a[N],sum;

int main() {
    scanf("%d",&T);
    while (T--) {
        scanf("%d",&n);
        sum=0;
        for (int i=1;i<=n;++i) {
            scanf("%d",a+i);
            sum+=a[i];
        }
        int avg=sum/n;
        int addon=0;
        bool ok=true;
        for (int i=1;i<=n;++i) {
            addon+=(a[i]-avg);
            if (addon<0) {
                ok=false;
                break;
            }
        }
        if (ok) puts("YES");
        else puts("NO");
    }
    return 0;
}