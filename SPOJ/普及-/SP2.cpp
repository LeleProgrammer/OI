#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N=50005;

int T,m,n;

bool flag[N];
vector<int> ps;

void init() {
    flag[1]=true;
    for (int i=2;i<N;++i) {
        if (!flag[i]) {
            for (int j=2;i*j<N;++j) {
                flag[i*j]=true;
            }
            ps.push_back(i);
        }
    }
}

bool isprime(int k) {
    if (k==1) return false;
    if (k<N) return !flag[k];
    for (int i:ps) if (k%i==0) return false;
    return true;
}

signed main() {
    init();
    scanf("%lld",&T);
    bool ok=false;
    while (T--) {
        if (ok) putchar(10);
        scanf("%lld %lld",&m,&n);
        for (int i=m;i<=n;++i) {
            if (isprime(i)) printf("%lld\n",i);
        }
        ok=true;
    }
    return 0;
}