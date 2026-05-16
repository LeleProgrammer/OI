#include <bits/stdc++.h>
using namespace std;

const int N=1005;

int T;
double n;
double f[N];

int main() {
    scanf("%d",&T);
    while (T--) {
        scanf("%lf",&n);
        memset(f,0,sizeof(f));
        for (int i=1;i<=n;++i) {
            f[i]=f[i-1]+(n/(n-(i-1)));
        }
        printf("%.2lf\n",f[int(n)]);
    }
    return 0;
}