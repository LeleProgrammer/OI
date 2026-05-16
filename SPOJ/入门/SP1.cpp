#include <bits/stdc++.h>
using namespace std;

int main() {
    bool out=true;
    while (true) {
        int a;
        scanf("%d",&a);
        if (a==42) {
            out=false;
            break;
        } else {
            printf("%d\n",a);
        }
    }
    return 0;
}