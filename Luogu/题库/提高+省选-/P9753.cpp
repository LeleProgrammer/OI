#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N=2000005;

int n;
int f[N],g[N];
char arr[N];

signed main() {
    scanf("%lld",&n);
    scanf("%s",arr+1);
    for (int i=1;i<=n;++i) {
        int j;
        for (j=i-1;j>=1;j=g[j]-1) {
            if (arr[i]==arr[j]) break;
        }
        g[i]=j;
        if (j>=1) f[i]=f[j-1]+1;
    }
    int ans=0;
    for (int i=1;i<=n;++i) {
        ans+=f[i];
    }
    printf("%lld",ans);
    return 0;
}