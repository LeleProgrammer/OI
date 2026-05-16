#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N=1005;
const int mod=10007;

int a,b,k,n,m;
int arr[N][N];

signed main() {
    scanf("%lld %lld %lld %lld %lld",&a,&b,&k,&n,&m);
    k++,n++,m++;
    arr[1][1]=1;
    for (int i=2;i<=k;++i) {
        for (int j=1;j<=i;++j) {
            arr[i][j]=(arr[i-1][j-1]*b+arr[i-1][j]*a)%mod;
        }
    }
    printf("%lld",arr[k][m]);
    return 0;
}