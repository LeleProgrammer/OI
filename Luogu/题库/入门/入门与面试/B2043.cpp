#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    bool addspace=false;
    bool nothing=true;
    if (n%3==0) {
        cout<<3;
        addspace=true;
        nothing=false;
    }
    if (n%5==0) {
        if (addspace) cout<<" ";
        cout<<5;
        addspace=true;
        nothing=false;
    }
    if (n%7==0) {
        if (addspace) cout<<" ";
        cout<<7;
        nothing=false;
    }
    if (nothing) cout<<n;
    return 0;
}