#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("P9754_18.in","r",stdin);
    freopen("P9754.out","w",stdout);
    int n;
    cin>>n;
    string s;
    while (getline(cin,s)) {
        if (isdigit(s[0])) {
            cout<<s<<endl;
        }
    }
    return 0;
}