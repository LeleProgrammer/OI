#include <bits/stdc++.h>
using namespace std;

int T,n;
string s;

int main() {
    scanf("%d",&T);
    while (T--) {
        scanf("%d",&n);
        s="";
        bool ok=false;
        for (int a=1;a<=26 && !ok;++a) {
            for (int b=1;b<=26 && !ok;++b) {
                for (int c=1;c<=26 && !ok;++c) {
                    if (a+b+c==n) {
                        printf("%c%c%c\n",a+'a'-1,b+'a'-1,c+'a'-1);
                        ok=true;
                    }
                }
            }
        }
    }
    return 0;
}