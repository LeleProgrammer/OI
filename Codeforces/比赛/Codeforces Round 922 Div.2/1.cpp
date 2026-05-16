#include <bits/stdc++.h>
using namespace std;

int T,n,m;

int main() {
    scanf("%d",&T);
    while (T--) {
        scanf("%d %d",&n,&m);
        if (m%2) m--;
        printf("%d\n",n*m/2);
    }
    return 0;
}