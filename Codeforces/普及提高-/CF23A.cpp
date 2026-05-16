#include <bits/stdc++.h>
using namespace std;

string s,sub;

unordered_set<string> hsh;

int ans=0;

int main() {
    cin>>s;
    for (int len=s.size()-1;len>=1;--len) {
        for (int start=0;start+len<=s.size();++start) {
            unordered_set<string>::iterator iter=hsh.find(s.substr(start,len));
            if (iter==hsh.end()) {
                hsh.insert(s.substr(start,len));
            } else {
                ans=len;
                break;
            }
        }
        if (ans) break;
    }
    printf("%d",ans);
    return 0;
}