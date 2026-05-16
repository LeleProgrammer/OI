#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    scanf("%d",&n);
    if (n%3==0) printf("YES\n");
    else {
        while (n) {
            if (n%10==3) {
                printf("YES\n");
                return 0;
            }
            n/=10;
        }
        printf("NO\n");
    }
    return 0;
}