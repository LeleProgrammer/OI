#include <bits/stdc++.h>
using namespace std;

int cnt;

int main() {
    string s;
    getline(cin,s);
    for (int i=0;i<s.size();++i) {
        if (s[i]==' ' || s[i]=='\n') continue;
        cnt++;
    }
    printf("%d",cnt);
    return 0;
}