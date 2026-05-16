#include <bits/stdc++.h>
using namespace std;

int a,b,c;

int main() {
    scanf("%d %d %d",&a,&b,&c);
    if (b<c && (a>=c || a<b)) puts("Yes");
    else if (b>c && (a>=c && a<b)) puts("Yes");
    else puts("No");
    return 0;
}