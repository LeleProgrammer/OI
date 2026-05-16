#include <bits/stdc++.h>
using namespace std;

const int N=1005;
const int M=100005;
const int inf=1e9;

int n,m,y;
int arr[N][N];
int f[N][N];
int cnt[M];

int min4(int a,int b,int c,int d) {
    return min(min(min(a,b),c),d);
}

int main() {
    scanf("%d %d %d",&n,&m,&y);
    for (int i=1;i<=n;++i) {
        for (int j=1;j<=m;++j) {
            scanf("%d",&arr[i][j]);
        }
    }
    for (int i=1;i<=n;++i) {
        for (int j=1;j<=m;++j) {
            f[i][j]=inf;
        }
    }
    for (int i=1;i<=n;++i) {
        for (int j=1;j<=m;++j) {
            f[i][j]=min(f[i][j],max(min4(f[i-1][j],f[i][j-1],f[i+1][j],f[i][j+1]),arr[i][j]));
        }
    }
    for (int i=n;i;--i) {
        for (int j=m;j;--j) {
            f[i][j]=min(f[i][j],max(min4(f[i-1][j],f[i][j-1],f[i+1][j],f[i][j+1]),arr[i][j]));
        }
    }
    for (int i=1;i<=n;++i) {
        for (int j=m;j;--j) {
            f[i][j]=min(f[i][j],max(min4(f[i-1][j],f[i][j-1],f[i+1][j],f[i][j+1]),arr[i][j]));
        }
    }
    for (int i=n;i;--i) {
        for (int j=1;j<=m;++j) {
            f[i][j]=min(f[i][j],max(min4(f[i-1][j],f[i][j-1],f[i+1][j],f[i][j+1]),arr[i][j]));
        }
    }
    for (int i=1;i<=n;++i) {
        for (int j=1;j<=m;++j) {
            // printf("%d ",f[i][j]);
            cnt[f[i][j]]++;
        }
        // putchar(10);
    }
    int ans=n*m;
    for (int i=1;i<=y;++i) {
        ans-=cnt[i];
        printf("%d\n",ans);
    }
    return 0;
}

/*
hack:
5 5 10
8 8 8 8 8
8 5 8 5 8
8 3 6 3 8
8 1 2 1 8
8 8 8 8 8
*/