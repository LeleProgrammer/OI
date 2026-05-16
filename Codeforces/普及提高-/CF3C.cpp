#include <bits/stdc++.h>
using namespace std;

int arr[4][4];

int main() {
    for (int i=1;i<=3;++i) {
        for (int j=1;j<=3;++j) {
            scanf(" %c",&arr[i][j]);
        }
    }
    int a=0,b=0;
    for (int i=1;i<=3;++i) {
        for (int j=1;j<=3;++j) {
            if (arr[i][j]=='X') a++;
            else if (arr[i][j]=='0') b++;
        }
    }
    if (!(a==b+1 || a==b)) printf("illegal");
    else {
        bool oka=false;
        for (int i=1;i<=3;++i) {
            if (arr[1][i]=='X' && arr[2][i]=='X' && arr[3][i]=='X') {
                oka=true;
                break;
            }
        }
        for (int i=1;i<=3;++i) {
            if (arr[i][1]=='X' && arr[i][2]=='X' && arr[i][3]=='X') {
                oka=true;
                break;
            }
        }
        if (arr[1][1]=='X' && arr[2][2]=='X' && arr[3][3]=='X') oka=true;
        if (arr[1][3]=='X' && arr[2][2]=='X' && arr[3][1]=='X') oka=true;
        bool okb=false;
        for (int i=1;i<=3;++i) {
            if (arr[1][i]=='0' && arr[2][i]=='0' && arr[3][i]=='0') {
                okb=true;
                break;
            }
        }
        for (int i=1;i<=3;++i) {
            if (arr[i][1]=='0' && arr[i][2]=='0' && arr[i][3]=='0') {
                okb=true;
                break;
            }
        }
        if (arr[1][1]=='0' && arr[2][2]=='0' && arr[3][3]=='0') okb=true;
        if (arr[1][3]=='0' && arr[2][2]=='0' && arr[3][1]=='0') okb=true;
        if (oka && okb) printf("illegal");
        else if (b+1==a && okb) printf("illegal");
        else if (a==b && oka) printf("illegal");
        else if (oka) printf("the first player won");
        else if (okb) printf("the second player won");
        else if (a==b) printf("first");
        else if (a+b==9) printf("draw");
        else printf("second");
    }
    return 0;
}