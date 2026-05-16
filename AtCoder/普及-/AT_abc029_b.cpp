#include <bits/stdc++.h>
using namespace std;

int ans=0;
int n=12;

int main() {
    string s;
    while (n--) {
        cin>>s;
        for (int i=0;i<s.size();++i) {
            if (s[i]=='r') {
                ans++;
                break;
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}