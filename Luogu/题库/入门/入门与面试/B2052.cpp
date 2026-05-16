#include <bits/stdc++.h>
using namespace std;

int main() {
    int a,b;
    char s;
    cin>>a>>b>>s;
    if (s=='+') {
        cout<<a+b;
    } else if (s=='-') {
        cout<<a-b;
    } else if (s=='*') {
        cout<<a*b;
    } else if (s=='/') {
        if (b==0) {
            cout<<"Divided by zero!";
        } else {
            cout<<a/b;
        }
    } else {
        cout<<"Invalid operator!";
    }
    return 0;
}