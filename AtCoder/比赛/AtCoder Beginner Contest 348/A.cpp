#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
    scanf("%d",&n);
    for (int i=1;i<=n;++i) {
        if (i%3==0) printf("x");
        else printf("o");
    }
    return 0;
}