#include <bits/stdc++.h>

#define mod 1000007

using namespace std;

int n,m;
int a[105];
int f[105];

int main() {
    scanf("%d %d",&n,&m);
    for (int i=1;i<=n;++i) {
        scanf("%d",&a[i]);
    }
    memset(f,0,sizeof(f));
    f[0]=1;
    for (int i=1;i<=n;++i) {
        for (int j=m;j>=0;--j) {
            for (int k=1;k<=a[i] && j-k>=0;++k) {
                f[j]+=f[j-k];
                f[j]%=mod;
            }
        }
    }
    printf("%d",f[m]);
    return 0;
}