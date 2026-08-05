#include <bits/stdc++.h>

#define min3(a,b,c) min(min(a,b),c)

using namespace std;

const int N=1005;

int n,t;
int arr[N][N];
int a,b;
int f[N][N];
int ans;

int main() {
    scanf("%d %d",&n,&t);
    while (t--) {
        scanf("%d %d",&a,&b);
        arr[a][b]=1;
    }
    for (int i=1;i<=n;++i) {
        for (int j=1;j<=n;++j) {
            if (!arr[i][j]) f[i][j]=min3(f[i-1][j],f[i][j-1],f[i-1][j-1])+1;
            ans=max(ans,f[i][j]);
        }
    }
    printf("%d",ans);
    return 0;
}