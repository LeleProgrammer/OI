#include <bits/stdc++.h>
using namespace std;

int main() {
    int a,b,c;
    cin>>a>>b>>c;
    if (((int)(a<60))+((int)(b<60))+((int)(c<60))==1) {
        cout<<1;
    } else {
        cout<<0;
    }
    return 0;
}