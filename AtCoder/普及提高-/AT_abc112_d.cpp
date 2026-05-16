#include <bits/stdc++.h>
using namespace std;

int n,m;

int main() {
    scanf("%d %d",&n,&m);
    for (int i=m/n;i;--i) {
        if (m%i) continue;
        printf("%d\n",i);
        return 0;
    }
    return 0;
}