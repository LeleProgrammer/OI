#include <bits/stdc++.h>
using namespace std;

int y;

int main() {
    scanf("%d",&y);
    if (y%4) cout<<365;
    else if (y%4==0 && y%100!=0) cout<<366;
    else if (y%100==0 && y%400!=0) cout<<365;
    else if (y%400==0) cout<<366;
    else cout<<365;
    return 0;
}