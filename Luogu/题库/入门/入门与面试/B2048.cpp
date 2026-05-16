#include <bits/stdc++.h>
using namespace std;

int main() {
    int x;
    char c;
    cin>>x>>c;
    int res=8;
    if (x>1000) {
        x-=1000;
        int times=x/500;
        if (x%500) {
            times++;
        }
        res+=times*4;
    }
    if (c=='y') {
        res+=5;
    }
    printf("%d",res);
    return 0;
}