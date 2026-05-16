#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N=100005;
const int M=100005;

int T,n,x;
int arr[N];
unordered_set<int> t;

signed main() {
    scanf("%lld",&T);
    while (T--) {
        t.clear();
        scanf("%lld %lld",&n,&x);
        for (int i=1;i<=n;++i) {
            scanf("%lld",&arr[i]);
            if (x%arr[i]) {
                arr[i]=0;
            }
        }
        int ans=1;
        bool ok=true;
        for (int i=1;i<=n;++i) {
            if (!arr[i]) continue;
            for (auto it=t.begin();it!=t.end();++it) {
                if ((*it)*arr[i]>x) continue;
                if ((*it)*arr[i]==x) {
                    ok=false;
                    break;
                }
                t.insert((*it)*arr[i]);
            }
            t.insert(arr[i]);
            if (!ok) {
                t.clear();
                ans++;
                i--;
                ok=true;
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}

/*
< 7 primes
< 17 factors

1
5 24
2 2 2 3 6
*/