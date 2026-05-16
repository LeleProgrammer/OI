#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    int a,b,c;
    a=n/100;
    n%=100;
    b=n/10;
    n%=10;
    c=n;
    cout<<c<<b<<a;
    return 0;
}