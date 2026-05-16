#include <bits/stdc++.h>

#define int long long

using namespace std;

int T,k,x,a;
int pw[60];

signed main() {
    scanf("%lld",&T);
    while (T--) {
        scanf("%lld %lld %lld",&k,&x,&a);
        int b=a;
        bool ok=true;
        for (int i=1;i<=x;++i) {
            int need=a+1-b;
            int put=need/(k-1);
            if (need%(k-1)) put++;
            if (put==0) put=1;
            b-=put;
            if (b<=0) ok=false;
        }
        if (!ok) puts("NO");
        else {
            b+=b*(k-1);
            if (b<=a) puts("NO");
            else puts("YES");
        }
    }
    return 0;
}