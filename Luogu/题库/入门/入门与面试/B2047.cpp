#include <bits/stdc++.h>
using namespace std;

inline double f(double x) {
    if (x<5) return -x+2.5;
    else if (x<10) return 2-1.5*(x-3)*(x-3);
    else return x/2-1.5;
}

int main() {
    double x;
    cin>>x;
    cout<<fixed<<setprecision(3)<<f(x);
    return 0;
}