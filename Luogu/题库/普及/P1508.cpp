#include <bits/stdc++.h>

#define max3(a,b,c) max(max(a,b),c)

using namespace std;

const int M=205,N=205;

int m,n;
int arr[M][N];
int f[M][N];
bool forbidden[M][N];

int main() {
    scanf("%d %d",&m,&n);
    int mid=n+1>>1;
    for (int i=m;i>=1;--i) {
        for (int j=n;j>=1;--j) {
            scanf("%d",&arr[i][j]);
            if (j-i>mid || j+i<mid) forbidden[i][j]=true;
        }
    }
    int res=-0x7fffffff;
    for (int i=1;i<=m;++i) {
        for (int j=1;j<=n;++j) {
            if (!forbidden[i][j]) {
                f[i][j]=max3(f[i-1][j-1],f[i-1][j],f[i-1][j+1])+arr[i][j];
                if (i==m) res=max(res,f[i][j]);
            }
        }
    }
    printf("%d",res);
    return 0;
}