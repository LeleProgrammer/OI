#include <bits/stdc++.h>
using namespace std;

int t;
string s;

int main() {
    scanf("%d",&t);
    while (t--) {
        cin>>s;
        while (true) {
            bool did=false;
            if (s.size()<=1) break;
            for (int i=0;i<s.size()-1;++i) {
                if (s[i]=='A' && s[i+1]=='B') {
                    s.erase(s.begin()+i);
                    s.erase(s.begin()+i);
                    --i;
                    did=true;
                    if (s.size()<=1) break;
                }
            }
            if (!did) break;
        }
        while (true) {
            bool did=false;
            if (s.size()<=1) break;
            for (int i=0;i<s.size()-1;++i) {
                if (s[i]=='B' && s[i+1]=='B') {
                    s.erase(s.begin()+i);
                    s.erase(s.begin()+i);
                    --i;
                    did=true;
                    if (s.size()<=1) break;
                }
            }
            if (!did) break;
        }
        printf("%d\n",s.size());
    }
    return 0;
}