#include <bits/stdc++.h>
using namespace std;

bool tri=false;
bool seg=false;

void check(int a,int b,int c) {
    if (a+b>c && a+c>b && b+c>a) tri=true;
    else if (a+b>=c && a+c>=b && b+c>=a) seg=true;
}

int main() {
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    check(a,b,c);
    check(a,b,d);
    check(a,c,d);
    check(b,c,d);
    if (tri) printf("TRIANGLE");
    else if (seg) printf("SEGMENT");
    else printf("IMPOSSIBLE");
    return 0;
}