#include <bits/stdc++.h>
using namespace std;

int n;
int add;

int main() {
    for (int i=1;i<=12;++i) {
        int k;
        scanf("%d",&k);
        n+=300;
        n-=k;
        if (n<0) {
            printf("-%d",i);
            return 0;
        }
        add+=100*(n/100);
        n%=100;
    }
    printf("%d",n+add*12/10);
    return 0;
}