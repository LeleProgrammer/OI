#include <bits/stdc++.h>
using namespace std;

int main() {
    double a,b,c;
    cin>>a>>b>>c;
    if (b*b-4*a*c<0) {
        printf("No answer!");
        return 0;
    }
    double x1,x2;
    x1=((-b)+(double)(sqrt(b*b-4*a*c)))/(2*a);
    x2=((-b)-(double)(sqrt(b*b-4*a*c)))/(2*a);
    if (x1==x2) {
        printf("x1=x2=%.5f",x1);
    } else if (x1<x2) {
        printf("x1=%.5f;x2=%.5f",x1,x2);
    } else {
        printf("x1=%.5f;x2=%.5f",x2,x1);
    }
    return 0;
}