#include <bits/stdc++.h>
using namespace std;

int main() {
    int maxx=0,day=0;
    for (int i=1;i<=7;++i) {
        int a,b;
        scanf("%d %d",&a,&b);
        if (a+b>maxx && a+b>8) maxx=a+b,day=i;
    }
    printf("%d",day);
    return 0;
}