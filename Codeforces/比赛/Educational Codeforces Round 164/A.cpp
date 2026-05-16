#include <bits/stdc++.h>
using namespace std;

int T,n,m,k;

int main() {
    scanf("%d",&T);
    while (T--) {
        scanf("%d %d %d",&n,&m,&k);
        if (m==1) {
            puts("NO");
            continue;
        }
        if (m==2) {
            int d=n/2+(bool)(n%2);
            int t=n-d;
            if (k>=t) puts("NO");
            else puts("YES");
            continue;
        }
        int d=n/m+(bool)(n%m);
        int t=n-d;
        if (k>=t) puts("NO");
        else puts("YES");
    }
    return 0;
}

/*
7 3
1 1 1 1 2 2 3
*/