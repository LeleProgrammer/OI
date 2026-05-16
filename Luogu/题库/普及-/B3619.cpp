#include <bits/stdc++.h>
using namespace std;

int n,x;
char s[36]={'0','1','2','3','4','5','6','7','8',
'9','A','B','C','D','E','F','G','H','I','J','K','L',
'M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};

string res="";

int main() {
    scanf("%d %d",&n,&x);
    while (n) {
        res=s[n%x]+res;
        n/=x;
    }
    cout<<res;
    return 0;
}