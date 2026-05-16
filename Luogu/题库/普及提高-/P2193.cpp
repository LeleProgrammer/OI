#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N=2005;
const int P=2005;
const int mod=1000000007;

int n,p;
int f[N][P];
int ans;

signed main() {
    scanf("%lld %lld",&n,&p);
    f[0][1]=1;
    for (int i=1;i<=p;++i) {
        for (int j=1;j<=n;++j) {
            for (int k=1;j*k<=n;++k) {
                f[i][j*k]+=f[i-1][j];
                f[i][j*k]%=mod;
            }
        }
    }
    for (int i=1;i<=n;++i) ans+=f[p][i];
    printf("%lld",ans%mod);
    return 0;
}