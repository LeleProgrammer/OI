#include <bits/stdc++.h>
using namespace std;

string s[1000];

int main() {
    for (int i=1;i<=1000;++i) {
        s[i-1]=to_string(i);
    }
    sort(s,s+1000);
    for (int i=0;i<1000;++i) {
        cout<<s[i]<<endl;
    }
    return 0;
}