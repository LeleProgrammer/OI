#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin>>s;
    int len=0;
    bool ok=true;
    if (s[0]=='@') ok=false;
    int start=0;
    while (start<s.size() && s[start]!='@') ++start;
    if (start==s.size() || start==s.size()-1) ok=false;
    for (int i=start+1;i<s.size() && ok;++i) {
        if (s[i]=='@') {
            if (len<2) {
                ok=false;
                break;
            }
            len=0;
        } else {
            len++;
        }
    }
    if (len<1) {
        ok=false;
    }
    if (!ok) {
        printf("No solution");
    } else {
        string now="";
        bool comma=false;
        int ats=0;
        int doneats=0;
        for (int i=0;i<s.size();++i) if (s[i]=='@') ++ats;
        if (ats==1) {
            cout<<s;
            return 0;
        }
        for (int i=0;i<s.size();++i) {
            if (s[i]=='@') {
                doneats++;
                if (doneats==ats) {
                    for (;i<s.size();++i) {
                        now+=s[i];
                    }
                    cout<<","<<now;
                    break;
                } else {
                    now+=s[i];
                    now+=s[i+1];
                    ++i;
                    if (comma) cout<<",";
                    cout<<now;
                    comma=true;
                    now="";
                }
            } else {
                now+=s[i];
            }
        }
    }
    return 0;
}