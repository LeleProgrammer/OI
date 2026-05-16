#include <bits/stdc++.h>
using namespace std;

const int N=100005;

int T,n,m,k;

int main() {
    scanf("%d",&T);
    while (T--) {
        scanf("%d %d %d",&n,&m,&k);
        for (int i=n;i>=k;--i) printf("%d ",i);
        for (int i=m+1;i<=k-1;++i) printf("%d ",i);
        for (int i=1;i<=m;++i) printf("%d ",i);
        putchar(10);
    }
    return 0;
}