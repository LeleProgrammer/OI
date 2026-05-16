#include <bits/stdc++.h>
using namespace std;

string x;

int main() {
    cin>>x;
    while (x[0]=='0') x.erase(x.begin());
    while (x.back()=='0') x.pop_back();
    if (x.back()=='.') x.pop_back();
    if (x.size()==0) printf("0");
    else if (x[0]=='.') cout<<0<<x;
    else cout<<x;
    return 0;
}