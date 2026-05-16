#include <bits/stdc++.h>

#define int long long

using namespace std;

int n,summ;
int f[825];

signed main() {
    memset(f,0,sizeof(f));
    f[0]=1;
    scanf("%lld",&n);
    summ=(1+n)*n/2;
    if (summ%2) {
        printf("0");
        return 0;
    }
    summ/=2;
    for (int i=1;i<=n;++i) {
        for (int j=summ;j>=i;--j) {
            f[j]+=f[j-i];
        }
    }
    printf("%lld",f[summ]/2);
    return 0;
}