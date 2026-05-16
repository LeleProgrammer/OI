#include <bits/stdc++.h>
using namespace std;

int t;
int p,a,b,c;

int main() {
    scanf("%d",&t);
    while (t--) {
        scanf("%d %d %d %d",&p,&a,&b,&c);
        if (c>=p) printf("No\n");
        else if (c==0) printf("Yes\n");
        else if (b%p==0 || !b) printf("No\n");
        else printf("Yes\n");
    }
    return 0;
}