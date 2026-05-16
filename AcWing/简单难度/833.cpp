#include <bits/stdc++.h>
using namespace std;

char p[100005];
char s[1000005];
int ne[100005];
int n,m;

int main() {
    scanf("%d",&n); cin>>p+1;
    scanf("%d",&m); cin>>s+1;
    for (int i=2,j=0;i<=n;++i) {
        while (j && p[i]!=p[j+1]) j=ne[j];
        if (p[j+1]==p[i]) ++j;
        ne[i]=j;
    }
    for (int i=1,j=0;i<=m;++i) {
        while (j && p[j+1]!=s[i]) j=ne[j];
        if (p[j+1]==s[i]) ++j;
        if (j==n) {
            printf("%d ",i-n);
            j=ne[j];
        }
    }
    return 0;
}