#include <bits/stdc++.h>

#define int long long

using namespace std;

int v,n;
int arr[26];
int f[10005];

signed main() {
    scanf("%lld %lld",&v,&n);
    for (int i=1;i<=v;++i) {
        scanf("%lld",&arr[i]);
    }
    memset(f,0,sizeof(f));
    f[0]=1;
    for (int i=1;i<=v;++i) {
        for (int j=arr[i];j<=n;++j) {
            f[j]+=f[j-arr[i]];
        }
    }
    printf("%lld",f[n]);
    return 0;
}