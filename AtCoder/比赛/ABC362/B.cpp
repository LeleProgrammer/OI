#include <bits/stdc++.h>
using namespace std;

int xa,xb,xc,ya,yb,yc;

int main() {
    cin>>xa>>ya>>xb>>yb>>xc>>yc;
    if ((xa==xb && xa==xc) ||( ya==yb && yc==ya)) {
        puts("No");
        return 0;
    }
    int ab=(xa-xb)*(xa-xb)+(ya-yb)*(ya-yb);
    int ac=(xa-xc)*(xa-xc)+(ya-yc)*(ya-yc);
    int bc=(xb-xc)*(xb-xc)+(yb-yc)*(yb-yc);
    if (ab+ac==bc || ab+bc==ac || ac+bc==ab) {
        puts("Yes");
    } else puts("No");
    return 0;
}