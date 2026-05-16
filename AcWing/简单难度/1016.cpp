#include <bits/stdc++.h>
using namespace std;

const int N=1005;

int n;
int a[N];
int f[N];
int ans;

int main() {
    scanf("%d",&n);
    for (int i=1;i<=n;++i) scanf("%d",&a[i]);
    for (int i=1;i<=n;++i) f[i]=a[i];
    for (int i=2;i<=n;++i) for (int j=1;j<=i-1;++j) if (a[j]<a[i]) f[i]=max(f[i],f[j]+a[i]);
    for (int i=1;i<=n;++i) ans=max(ans,f[i]);
    printf("%d",ans);
    return 0;
}