#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N=35;

int n;
int a[N];
int f[N][N];

void dfs(int l,int r) {
    if (l==r) {
        printf("%lld ",l);
        return;
    }
    if (f[l][r]==f[l][l]+f[l+1][r]) {
        printf("%lld ",l);
        dfs(l+1,r);
        return;
    }
    if (f[l][r]==f[l][r-1]+f[r][r]) {
        printf("%lld ",r);
        dfs(l,r-1);
        return;
    }
    for (int k=l+1;k<=r-1;++k) {
        if (f[l][r]==f[l][k-1]*f[k+1][r]+a[k]) {
            printf("%lld ",k);
            dfs(l,k-1);
            dfs(k+1,r);
        }
    }
}

signed main() {
    scanf("%lld",&n);
    for (int i=1;i<=n;++i) {
        scanf("%lld",&a[i]);
    }
    for (int i=1;i<=n;++i) {
        f[i][i]=a[i];
    }
    for (int i=1;i<=n-1;++i) {
        f[i][i+1]=a[i]+a[i+1];
    }
    for (int len=3;len<=n;++len) {
        for (int i=1,j=i+len-1;j<=n;++i,++j) {
            f[i][j]=max(f[i][i]+f[i+1][j],f[i][j-1]+f[j][j]);
            for (int k=i+1;k<=j-1;++k) {
                f[i][j]=max(f[i][j],f[i][k-1]*f[k+1][j]+a[k]);
            }
        }
    }
    printf("%lld\n",f[1][n]);
    dfs(1,n);
    return 0;
}