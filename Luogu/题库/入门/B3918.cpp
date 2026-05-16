#include <bits/stdc++.h>
using namespace std;

int n,m,k;
char arr[105][105];

int main() {
    scanf("%d %d %d",&n,&m,&k);
    for (int i=1;i<=n;++i) {
        for (int j=1;j<=m;++j) {
            scanf(" %c",&arr[i][j]);
        }
    }
    for (int i=1;i<=n;++i) {
        for (int q=1;q<=k;++q) {
            for (int j=1;j<=m;++j) {
                for (int p=1;p<=k;++p) {
                    printf("%c",arr[i][j]);
                }
            }
            putchar(10);
        }
    }
    return 0;
}