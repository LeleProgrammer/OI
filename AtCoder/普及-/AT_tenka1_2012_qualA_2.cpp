#include <bits/stdc++.h>
using namespace std;

string result="";
string input;

int main() {
    while (cin>>input) {
        result+=input;
        result+=",";
    }
    result.pop_back();
    cout<<result<<endl;
    return 0;
}