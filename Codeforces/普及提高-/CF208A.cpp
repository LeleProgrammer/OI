#include <bits/stdc++.h>
using namespace std;

string sss;
string readin;
string readword;
bool have_space=false;

int main() {
    cin>>sss;
    readin="";
    readword="";
    for (int i=0;i<sss.size();++i) {
        readword.push_back(sss[i]);
        if (sss[i]=='W' && readin.size()==0) readin.push_back(sss[i]);
        else if (sss[i]=='U' && readin.size()==1) readin.push_back(sss[i]);
        else if (sss[i]=='B' && readin.size()==2) {
            readin="";
            if (readword.size()==3) {
                readword="";
                continue;
            }
            if (have_space) printf(" ");
            have_space=true;
            readword.pop_back();readword.pop_back();readword.pop_back();
            cout<<readword;
            readword="";
        } else {
            readin="";
            if (sss[i]=='W') readin.push_back(sss[i]);
        }
    }
    if (readword.size()) {
        if (have_space) printf(" ");
        cout<<readword;
    }
    return 0;
}