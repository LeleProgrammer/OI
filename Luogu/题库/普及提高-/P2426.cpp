#include <bits/stdc++.h>
using namespace std;

const int N=105;

int n;
int a[N];
int f[N];
int g[N];

int main() {
    scanf("%d",&n);
    for (int i=1;i<=n;++i) scanf("%d",&a[i]);
    for (int i=1;i<=n;++i) {
        for (int j=1;j<=i;++j) {
            if (j==i) f[i]=max(f[i],f[j-1]+a[i]);
            else f[i]=max(f[i],f[j-1]+abs(a[i]-a[j])*(i-j+1));
        }
    }
    for (int i=n;i>=1;--i) {
        for (int j=n;j>=i;--j) {
            if (j==i) g[i]=max(g[i],g[j+1]+a[i]);
            else g[i]=max(g[i],g[j+1]+abs(a[i]-a[j])*(j-i+1));
        }
    }
    int ans=0;
    for (int i=0;i<=n;++i) {
        ans=max(ans,f[i]+g[i+1]);
    }
    printf("%d",ans);
    return 0;
}