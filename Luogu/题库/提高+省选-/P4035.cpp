#include <bits/stdc++.h>
using namespace std;

const int N=15;

int n;
double arr[N][N],a[N][N];

void gauss() {
    for (int r=1,c=1;r<=n;++r,++c) {
        int t=r;
        for (int i=r+1;i<=n;++i) {
            if (abs(a[i][c])>abs(a[t][c])) t=i;
        }
        for (int i=1;i<=n+1;++i) {
            swap(a[r][i],a[t][i]);
        }
        for (int i=n+1;i>=c;--i) {
            a[r][i]/=a[r][c];
        }
        for (int i=r+1;i<=n;++i) {
            for (int j=n+1;j>=c;--j) {
                a[i][j]-=a[i][c]*a[r][j];
            }
        }
    }
    for (int i=n;i>=2;--i) {
        for (int j=i-1;j;--j) {
            a[j][n+1]-=a[j][i]*a[i][n+1];
            a[j][i]=0;
        }
    }
}

int main() {
    scanf("%d",&n);
    for (int i=1;i<=n+1;++i) {
        for (int j=1;j<=n;++j) {
            scanf("%lf",&arr[i][j]);
        }
    }
    for (int i=1;i<=n;++i) {
        for (int j=1;j<=n;++j) {
            a[i][j]=2*(arr[i+1][j]-arr[1][j]);
            a[i][n+1]+=arr[i+1][j]*arr[i+1][j]-arr[1][j]*arr[1][j];
        }
    }
    gauss();
    for (int i=1;i<=n;++i) {
        printf("%.3lf ",a[i][n+1]);
    }
    return 0;
}