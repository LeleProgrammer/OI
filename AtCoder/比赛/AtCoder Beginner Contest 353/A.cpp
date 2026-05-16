#include <bits/stdc++.h>
using namespace std;

int n;
int k;

int main() {
    scanf("%d",&n);
    scanf("%d",&k);
    for (int i=2;i<=n;++i) {
        int t;
        scanf("%d",&t);
        if (t>k) {
            printf("%d",i);
            return 0;
        }
    }
    printf("-1");
    return 0;
}