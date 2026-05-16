#include <bits/stdc++.h>
using namespace std;

int n;
string s;

int main() {
    scanf("%d",&n);
    while (n--) {
        cin>>s;
        unordered_map< char,int > hs;
        for (char c:s) {
            if (hs.find(c)==hs.end()) hs.insert(make_pair(c,1));
            else hs[c]++;
        }
        if (hs.size()<2) printf("NO\n");
        else if (hs.size()==2) {
            bool yes=true;
            for (auto it=hs.begin();it!=hs.end();++it) {
                if (it->second==1) {
                    yes=false;
                    break;
                }
            }
            if (yes) printf("YES\n");
            else printf("NO\n");
        } else {
            bool yes=true;
            bool haveone=false;
            for (auto it=hs.begin();it!=hs.end();++it) {
                if (it->second==1) {
                    if (!haveone) haveone=true;
                    else {
                        yes=false;
                        break;
                    }
                }
            }
            if (yes) printf("YES\n");
            else printf("NO\n");
        }
    }
    return 0;
}