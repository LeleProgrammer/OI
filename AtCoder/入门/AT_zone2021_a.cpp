#include <bits/stdc++.h>
using namespace std;

string s;
int cnt=0;

int main() {
    cin>>s;
    for (int i=0;i<s.size()-3;++i) {
        if (s[i]=='Z' && s[i+1]=='O' && s[i+2]=='N' && s[i+3]=='e') cnt++;
    }
    printf("%d\n",cnt);
    return 0;
}