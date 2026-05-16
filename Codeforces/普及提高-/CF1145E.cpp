#include <bits/stdc++.h>
using namespace std;

int main() {
    for (int i=21;i<=50;++i) {
        if ((min(i,25)+i)%(2+(i%3))>0) printf("1");
        else printf("0");
        printf("\n");
    }
    return 0;
}