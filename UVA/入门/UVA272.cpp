#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    bool left=true;
    while (getline(cin,s)) {
        for (int i=0;i<s.size();++i) {
            if (s[i]=='"' && left) cout<<"``",left=false;
            else if (s[i]=='"' && !left) cout<<"''",left=true;
            else cout<<s[i];
        }
        cout<<endl;
    }
    return 0;
}