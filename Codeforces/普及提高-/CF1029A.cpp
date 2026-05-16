#include <bits/stdc++.h>
using namespace std;

int n,k;
char s[55];
int ne[55];

int main() {
    scanf("%d %d",&n,&k);
    cin>>s+1;
    for (int i=2,j=0;i<=n;++i) {
        while (j && s[i]!=s[j+1]) j=ne[j];
        if (s[i]==s[j+1]) ++j;
        ne[i]=j;
    }
    for (int i=1,j=1;i<=k;++j) {
        printf("%c",s[j]);
        if (j==n) j=ne[j],++i;
    }
    return 0;
}