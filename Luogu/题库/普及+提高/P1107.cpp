#include <bits/stdc++.h>

#define int long long

using namespace std;

int n,h,delta,m,val;
int arr[2005][5005];
int f[2005][5005];
int rec[5005];

signed main() {
    scanf("%lld %lld %lld",&n,&h,&delta);
    memset(arr,0,sizeof(arr));
    memset(f,0,sizeof(f));
    memset(rec,0,sizeof(rec));
    for (int i=1;i<=n;++i) {
        scanf("%lld",&m);
        for (int j=1;j<=m;++j) {
            scanf("%lld",&val);
            arr[i][val]++;
        }
    }
    for (int i=1;i<=h;++i) {
        for (int j=1;j<=n;++j) {
            if (i==1) {
                f[i][j]=arr[j][i];
            } else if (i-delta>=1) {
                f[i][j]=max(f[i-1][j],rec[i-delta])+arr[j][i];
            } else {
                f[i][j]=f[i-1][j]+arr[j][i];
            }
            rec[i]=max(rec[i],f[i][j]);
        }
    }
    printf("%lld",rec[h]);
    return 0;
}