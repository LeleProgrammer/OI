#include <bits/stdc++.h>
using namespace std;

int n;
int arr[100005][3];
int f[100005][3][2]; // j:10 20 30 k:µÍ¸ßµÍ ¸ßµÍ¸ß
int ans=0;

int main() {
    scanf("%d",&n);
    for (int i=1;i<=n;++i) {
        scanf("%d %d %d",&arr[i][0],&arr[i][1],&arr[i][2]);
    }
    memset(f,0,sizeof(f));
    for (int i=0;i<=2;++i) {
        for (int j=0;j<=2;++j) {
            for (int k=0;k<=1;++k) {
                f[1][j][k]=0;
            }
        }
        f[1][i][0]=arr[1][i];
        f[1][i][1]=arr[1][i];
        for (int j=2;j<=n;++j) {
            f[j][0][1]=max(f[j-1][1][0],f[j-1][2][0])+arr[j][0];
            f[j][1][0]=f[j-1][0][1]+arr[j][1];
            f[j][1][1]=f[j-1][2][0]+arr[j][1];
            f[j][2][0]=max(f[j-1][0][1],f[j-1][1][1])+arr[j][2];
        }
        for (int j=0;j<=2;++j) {
            if (j<i) {
                ans=max(ans,f[n][j][1]);
            } else if (j>i) {
                ans=max(ans,f[n][j][0]);
            }
        }
    }
    printf("%d",ans);
    return 0;
}