#include <bits/stdc++.h>
using namespace std;

string dict="1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";

int main() {
    string s;
    while (getline(cin,s)) {
        for (int i=0;i<s.size();++i) {
            if (s[i]==' ') cout<<' ';
            else for (int j=0;j<dict.size();++j) {
                if (dict[j]==s[i]) {
                    cout<<dict[j-1];
                    break;
                }
            }
        }
        cout<<endl;
    }
    return 0;
}