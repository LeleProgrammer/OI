#include <bits/stdc++.h>

#define inf 0x3f3f3f3f

using namespace std;

int n;
int a[1005];
int b[1005];
int f[1005][6005];

int main() {
    scanf("%d",&n);
    for (int i=1;i<=n;++i) {
        scanf("%d",&a[i]);
    }
    for (int i=1;i<=n;++i) {
        scanf("%d",&b[i]);
    }
    for (int i=1;i<=n;++i) {
        for (int j=0;j<=6000;++j) {
            f[i][j]=inf;
        }
    }
    f[1][abs(a[1]-b[1])]=0;
    for (int i=1;i<=n;++i) {
        for (int j=abs(a[i]-b[i]);j<=6000;++j) {
            f[i][j]=min(f[i-1][abs(j-(a[i]-b[i]))],f[i-1][abs(j-(b[i]-a[i]))]+1);
        }
    }
    for (int i=0;i<=6000;++i) {
        if (f[n][i]!=inf) {
            printf("%d",f[n][i]);
            return 0;
        }
    }
    return 0;
}