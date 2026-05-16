#include <bits/stdc++.h>
using namespace std;

const int N=2005;

int n,m;
int arr[N][N];
int a[N][N],b[N][N];
int ans;

int main() {
    scanf("%d %d",&n,&m);
    for (int i=1;i<=n;++i) {
        for (int j=1;j<=m;++j) {
            char c;
            scanf(" %c",&c);
            if (c=='.') arr[i][j]=1;
        }
    }
    for (int i=1;i<=n;++i) {
        for (int j=1;j<=m;++j) {
            if (!arr[i][j]) continue;
            int len=0;
            for (int k=j;k<=m;++k) {
                if (!arr[i][k]) break;
                len++;
            }
            for (int k=1;k<=len;++k) {
                a[i][j+k-1]=len;
            }
            j=j+len-1;
        }
    }
    for (int i=1;i<=m;++i) {
        for (int j=1;j<=n;++j) {
            if (!arr[j][i]) continue;
            int len=0;
            for (int k=j;k<=n;++k) {
                if (!arr[k][i]) break;
                len++;
            }
            for (int k=1;k<=len;++k) {
                b[j+k-1][i]=len;
            }
            j=j+len-1;
        }
    }
    for (int i=1;i<=n;++i) {
        for (int j=1;j<=m;++j) {
            ans=max(ans,a[i][j]+b[i][j]-1);
        }
    }
    printf("%d\n",ans);
    return 0;
}

/*
a
0 2 2 0 2 2
5 5 5 5 5 0
4 4 4 4 0 1
0 1 0 3 3 3
b
0 4 3 0 2 1
2 4 3 3 2 0
2 4 3 3 0 2
0 4 0 3 1 2
*/