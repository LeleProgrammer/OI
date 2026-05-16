#include <bits/stdc++.h>

#define int long long

using namespace std;

int T;
int n,k;

signed main() {
    scanf("%lld",&T);
    while (T--) {
        scanf("%lld %lld",&n,&k);
        int odd=(n/2)+(n%2);
        if (k<=odd) {
            printf("%lld\n",k*2-1);
        } else {
            k-=odd;
            for (int i=2;;i<<=1LL) {
                int h=(n+i)/(i*2);
                if (k<=h) {
                    printf("%lld\n",(i*2)*k-i);
                    break;
                }
                k-=h;
            }
        }
    }
    return 0;
}