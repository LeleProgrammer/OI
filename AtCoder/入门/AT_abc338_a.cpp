#include <bits/stdc++.h>
using namespace std;

string s;

int main() {
    cin>>s;
    if (!isupper(s[0])) printf("No\n");
    else {
        bool ok=true;
        for (int i=1;i<s.size();++i) {
            if (!islower(s[i])) {
                ok=false;
                break;
            }
        }
        if (ok) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}