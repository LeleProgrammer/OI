#include <bits/stdc++.h>
using namespace std;

const int N=120005;

set<string> arr;

int main() {
    string s;
    while (cin>>s) {
        arr.insert(s);
    }
    for (set<string>::iterator it=arr.begin();it!=arr.end();++it) {
        string a,b=*it;
        bool ok=false;
        for (int i=0;i<(*it).size()-1;++i) {
            a.push_back(b[0]);
            b.erase(b.begin());
            if (arr.find(a)!=arr.end() && arr.find(b)!=arr.end()) {
                ok=true;
                break;
            }
        }
        if (ok) {
            cout<<*it<<endl;
        }
    }
    return 0;
}