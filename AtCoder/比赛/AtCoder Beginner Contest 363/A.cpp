#include <bits/stdc++.h>
using namespace std;

int r;

int main() {
    scanf("%d",&r);
    if (r<=99) printf("%d",100-r);
    else if (r<=199) printf("%d",200-r);
    else if (r<=299) printf("%d",300-r);
    return 0;
}