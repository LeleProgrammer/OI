#include <bits/stdc++.h>
using namespace std;

string s;

int cnt[35];
int app[35];

int main() {
    cin>>s;
    for (int i=0;i<s.size();++i) {
        cnt[s[i]-'a']++;
        app[s[i]-'a']=i;
    }
    for (int i=0;i<=25;++i) {
        if (cnt[i]==1) {
            cout<<app[i]+1;
        }
    }
    return 0;
}