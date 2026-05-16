#include <bits/stdc++.h>
using namespace std;

int T,n;
char a[10][10];

int main() {
    scanf("%d",&T);
    while (T--) {
        scanf("%d",&n);
        for (int i=1;i<=n;++i) {
            for (int j=1;j<=n;++j) {
                scanf(" %c",&a[i][j]);
            }
        }
    }
}