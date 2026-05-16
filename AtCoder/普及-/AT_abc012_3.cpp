#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
    scanf("%d",&n);
    n=2025-n;
    for (int i=1;i<=9;++i) {
        if (n%i==0 && n/i<=9) printf("%d x %d\n",i,n/i);
    }
    return 0;
}