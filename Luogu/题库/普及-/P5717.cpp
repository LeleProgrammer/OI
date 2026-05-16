#include <bits/stdc++.h>
using namespace std;

int main() {
    int a,b,c;
    cin>>a>>b>>c;
    if (a>b) swap(a,b);
    if (b>c) swap(b,c);
    if (a>b) swap(a,b);
    if (b>c) swap(b,c);
    if (a+b<=c) cout<<"Not triangle\n";
    else {
        if (a*a+b*b==c*c) {
            cout<<"Right triangle\n";
        }
        if (a*a+b*b>c*c) {
            cout<<"Acute triangle\n";
        }
        if (a*a+b*b<c*c) {
            cout<<"Obtuse triangle\n";
        }
        if (a==b || b==c || a==c) {
            cout<<"Isosceles triangle\n";
        }
        if (a==b && b==c && a==c) {
            cout<<"Equilateral triangle\n";
        }
    }
    return 0;
}