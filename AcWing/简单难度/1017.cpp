#include <bits/stdc++.h>
using namespace std;

const int N=105;

int T,n;
int a[N];
int f[N];
int g[N];

int main() {
    scanf("%d",&T);
    while (T--) {
        scanf("%d",&n);
        for (int i=1;i<=n;++i) {
            scanf("%d",&a[i]);
        }
        f[1]=1;
        for (int i=2;i<=n;++i) {
            f[i]=1;
            for (int j=1;j<=i-1;++j) {
                if (a[j]>a[i]) f[i]=max(f[i],f[j]+1);
            }
        }
        g[n]=1;
        for (int i=n-1;i>=1;--i) {
            g[i]=1;
            for (int j=n;j>=i+1;--j) {
                if (a[j]>a[i]) g[i]=max(g[i],g[j]+1);
            }
        }
        int ans=0;
        for (int i=1;i<=n;++i) {
            ans=max(max(ans,f[i]),g[i]);
        }
        printf("%d\n",ans);
    }
    return 0;
}