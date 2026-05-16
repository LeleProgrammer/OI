#include <bits/stdc++.h>
using namespace std;

int T,l,r;

int main() {
    scanf("%d",&T);
    while (T--) {
        scanf("%d %d",&l,&r);
        if (l==1 && r==1) {
            puts("1");
            continue;
        }
        printf("%d\n",r-l);
    }
    return 0;
}