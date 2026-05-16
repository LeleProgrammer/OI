#include <bits/stdc++.h>
using namespace std;

int a,b,d;

int main() {
    scanf("%d %d %d",&a,&b,&d);
    for (int i=a;i<=b;i+=d) printf("%d ",i);
    putchar(10);
    return 0;
}