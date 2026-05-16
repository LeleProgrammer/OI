#include <bits/stdc++.h>

#define int long long

using namespace std;

int n;
int cnt;
int last=0;

signed main() {
    scanf("%lld",&n); n++;
    while (n--) {
        int v;
        scanf("%lld",&v);
        if (!last) {
            last=v;
            continue;
        }
        // if (last*v<0) cnt++;
        if ((last<0 && v>0) || (last>0 && v<0)) cnt++;
        last=v;
    }
    printf("%lld",cnt);
    return 0;
}