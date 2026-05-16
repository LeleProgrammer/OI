#include <bits/stdc++.h>

#define double long double

using namespace std;

double n,k;

signed main() {
    cin>>n>>k;
    double t=n*n*n;
    double x=0;
    double a=k-1,b=n-k;
    x+=a*b*3*2;
    x+=a*3+b*3;
    x++;
    cout<<fixed<<setprecision(32)<<x/t;
    return 0;
}