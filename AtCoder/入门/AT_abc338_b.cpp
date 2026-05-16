#include <bits/stdc++.h>
using namespace std;

string s;
int ts[155];
int maxx=-1;
int maxi=10000;
char ans;

int main() {
    cin>>s;
    for (char c:s) {
        ts[c-'a']++;
        if (ts[c-'a']>maxx) {
            maxx=ts[c-'a'];
            maxi=c-'a';
            ans=c;
        } else if (ts[c-'a']==maxx) {
            if (c-'a'<maxi) {
                maxi=c-'a';
                ans=c;
            }
        }
    }
    printf("%c\n",ans);
    return 0;
}