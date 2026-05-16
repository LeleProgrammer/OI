#include <bits/stdc++.h>
using namespace std;

int T;
int n,k;

int main() {
    scanf("%d",&T);
    while (T--) {
        scanf("%d %d",&n,&k);
        if (k<=(n-1)*2*2) printf("%d\n",k/2+k%2);
        else printf("%d\n",(n-1)*2+(k-(n-1)*2*2));
    }
    return 0;
}