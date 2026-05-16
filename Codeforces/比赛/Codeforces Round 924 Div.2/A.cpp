#include <bits/stdc++.h>
using namespace std;

int T,a,b;

int main() {
    scanf("%d",&T);
    while (T--) {
        scanf("%d %d",&a,&b);
        if ((a==1 && b==2) || (b==1 && a==2)) puts("No");
        else if ((a%2==1 && a*2==b) || (b%2==1 && b*2==a)) puts("No");
        else if (a%2==0 || b%2==0) puts("Yes");
        else puts("No");
    }
    return 0;
}