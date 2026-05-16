#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,l,r;
    scanf("%d %d %d",&n,&l,&r);
    if (l/n==r/n) {
        printf("%d",r%n);
    } else { // l/n+kkkk==r/n
        printf("%d",n-1);
    }
    return 0;
}