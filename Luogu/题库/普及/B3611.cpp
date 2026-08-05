#include <bits/stdc++.h>
using namespace std;

const int N=105;

int n;
int G[105][105];

int main() {
    scanf("%d",&n);
    for (int i=1;i<=n;++i) {
        for (int j=1;j<=n;++j) {
            scanf("%d",&G[i][j]);
        }
    }
    for (int k=1;k<=n;++k) {
        for (int i=1;i<=n;++i) {
            for (int j=1;j<=n;++j) {
                G[i][j]|=(G[i][k]&G[k][j]);
            }
        }
    }
    for (int i=1;i<=n;++i) {
        for (int j=1;j<=n;++j) {
            printf("%d ",G[i][j]);
        }
        putchar(10);
    }
    return 0;
}