#include <bits/stdc++.h>
using namespace std;

string s;
string t[15]={
    "KIHBR",
    "AKIHBR",
    "KIHABR",
    "KIHBAR",
    "KIHBRA",
    "AKIHBAR",
    "AKIHBAR",
    "AKIHBRA",
    "KIHABAR",
    "KIHABRA",
    "KIHBARA",
    "AKIHABAR",
    "AKIHABRA",
    "KIHABARA",
    "AKIHABARA"
};

int main() {
    cin>>s;
    bool ok=false;
    for (int i=0;i<=14;++i) {
        if (s==t[i]) {
            ok=true;
            break;
        }
    }
    if (ok) puts("YES");
    else puts("NO");
    return 0;
}