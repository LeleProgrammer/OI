#include <bits/stdc++.h>
using namespace std;

const int N=55;
const double eps=1e-7;

int n;
double a[N][N];

int gauss() {
    int r,c;
    for (r=1,c=1;c<=n;++c) {
        int t=r;
        for (int i=r+1;i<=n;++i) {
            if (abs(a[i][c])>abs(a[t][c])) t=i;
        }
        for (int i=1;i<=n+1;++i) swap(a[r][i],a[t][i]);
        if (abs(a[r][c])<eps) continue;
        for (int i=n+1;i>=c;--i) a[r][i]/=a[r][c];
        for (int i=r+1;i<=n;++i) {
            if (abs(a[i][c])<eps) continue;
            for (int j=n+1;j>=c;--j) {
                a[i][j]-=a[i][c]*a[r][j];
            }
        }
        ++r;
    }
    if (r!=n+1) {
        for (int i=r;i<=n;++i) {
            if (abs(a[i][n+1])>eps) {
                puts("-1");
                return 0;
            }
        }
        puts("0");
        return 0;
    }
    for (int i=n;i>=2;--i) {
        for (int j=i-1;j;--j) {
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
    if (!gauss()) return 0;
    for (int i=1;i<=n;++i) {
        printf("x%d=%.2lf\n",i,a[i][n+1]);
    }
    return 0;
}

/*
in:
4
0 0 2 1 2
0 0 0 1 1
0 0 0 0 0
0 0 1 1 1

ans:
-1
*/