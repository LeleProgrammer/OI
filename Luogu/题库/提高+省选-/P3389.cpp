#include <bits/stdc++.h>
using namespace std;

const int N=105;

int n;
double a[N][N];
double eps=1e-6;

int gause() {
    for (int r=1,c=1;r<=n;++r,++c) {
        int t=r;
        for (int i=r+1;i<=n;++i) {
            if (abs(a[i][c])>abs(a[t][c])) t=i;
        }
        for (int i=1;i<=n+1;++i) swap(a[r][i],a[t][i]);
        if (abs(a[r][c])<eps) {
            puts("No Solution");
            return 0;
        }
        for (int i=n+1;i>=c;--i) a[r][i]/=a[r][c];
        for (int i=r+1;i<=n;++i) {
            for (int j=n+1;j>=c;--j) {
                a[i][j]-=a[i][c]*a[r][j];
            }
        }
    }
    for (int i=n;i>=2;--i) {
        for (int j=i-1;j>=1;--j) {
            a[j][n+1]-=a[j][i]*a[i][n+1];
            a[j][i]=0;
        }
    }
    return 1;
}

int main() {
    scanf("%d",&n);
    for (int i=1;i<=n;++i) {
        for (int j=1;j<=n+1;++j) {
            scanf("%lf",&a[i][j]);
        }
    }
    if (!gause()) return 0;
    for (int i=1;i<=n;++i) printf("%.2lf\n",a[i][n+1]);
    return 0;
}