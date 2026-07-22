#include <bits/stdc++.h>
using namespace std;

int n;
char s[1000005];
int ne[1000005];

int main() {
    scanf("%d",&n);
    cin>>s+1;
    for (int i=2,j=0;i<=n;++i) {
        while (j && s[i]!=s[j+1]) j=ne[j];
        if (s[i]==s[j+1]) ++j;
        ne[i]=j;
    }
    printf("%d",n-ne[n]);
    return 0;
}