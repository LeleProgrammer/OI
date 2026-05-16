#include <bits/stdc++.h>
using namespace std;

int T,n,k;

int main() {
    scanf("%d",&T);
    while (T--) {
        scanf("%d %d",&n,&k);
        for (int i=1;i<=n;++i) {
            for (int j=0;j<k;++j) {
                printf("%c",char(j+'a'));
            }
        }
        putchar(10);
    }
    return 0;
}