#include <bits/stdc++.h>
using namespace std;

string s;

int pairs=0;
int n=0;
int maxx=0;
int count=1;
int countmaxx=0;

int main() {
    cin>>s;
    for (int i=0;i<s.size();++i) {
        if (s[i]=='(') pairs++,n++;
        else if (pairs!=0) {
            pairs--,n++;
            if (pairs==0) {
                maxx=max(maxx,n);
                if (maxx>countmaxx) countmaxx=maxx,::count=1;
                else if (maxx==countmaxx) ::count++;
            }
        }
        else {
            n=0,pairs=0;
            continue;
        }
    }
    if (::count==0) ::count=1;
    printf("%d %d",countmaxx,::count);
    return 0;
}