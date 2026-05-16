#include <bits/stdc++.h>
using namespace std;

inline double d(double xa,double xb,double ya,double yb) {
    return sqrt(pow(xa-xb,2)+pow(ya-yb,2));
}

int main() {
    double x1,y1,x2,y2,x3,y3;
    cin>>x1>>y1>>x2>>y2>>x3>>y3;
    double a,b,c;
    a=d(x1,x2,y1,y2);
    b=d(x1,x3,y1,y3);
    c=d(x2,x3,y2,y3);
    double p=(a+b+c)/2;
    cout<<fixed<<setprecision(2)<<sqrt(p*(p-a)*(p-b)*(p-c));
    return 0;
}