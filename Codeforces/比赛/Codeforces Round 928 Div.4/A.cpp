#include <bits/stdc++.h>
using namespace std;

int T;

int main() {
    scanf("%d",&T);
    while (T--) {
        string s;
        cin>>s;
        int a=0,b=0;
        for (char c:s) {
            if (c=='A') a++;
            else b++;
        }
        if (a>b) printf("A\n");
        else printf("B\n");
    }
    return 0;
}