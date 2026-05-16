#include <bits/stdc++.h>
using namespace std;

int main() {
    double x,a,y,b;
    cin>>x>>a>>y>>b;
    cout<<fixed<<setprecision(2)<<abs(x*a-y*b)/abs(a-b);
    return 0;
}