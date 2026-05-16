#include <bits/stdc++.h>
using namespace std;

string s;
string ans="";

int main() {
    cin>>s;
    int start;
    if (s[0]=='h') {
        ans+="http://";
        start=4;
    } else {
        ans+="ftp://";
        start=3;
    }
    string rec=""; rec+=s[start];
    for (int i=start+1;i<=s.size()-2;++i) {
        if (s[i]=='r' && s[i+1]=='u') {
            ans+=rec;
            ans+=".ru";
            start=i+2;
            break;
        } else {
            rec+=s[i];
        }
    }
    for (int i=start;i<s.size();++i) {
        if (i==start) ans+="/";
        ans+=s[i];
    }
    cout<<ans;
    return 0;
}