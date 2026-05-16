#include <bits/stdc++.h>
using namespace std;

char s[1000005];
int ne[1000005];
int n;

int main() {
    while (true) {
        cin>>s+1;
        n=strlen(s+1);
        if (s[1]=='.' && n==1) break;
        if (n==1) {
            printf("%d\n",1);
            continue;
        }
        memset(ne,0,sizeof(ne));
        for (int i=2,j=0;i<=n;++i) {
            while (j && s[j+1]!=s[i]) j=ne[j];
            if (s[j+1]==s[i]) ++j;
            ne[i]=j;
        }
        if (!ne[n]) {
            printf("%d\n",1);
            continue;
        }
        if (!(n%(n-1-ne[n-1]))) {
            printf("%d\n",n/(n-1-ne[n-1]));
        } else {
            printf("%d\n",1);
        }
    }
    return 0;
}