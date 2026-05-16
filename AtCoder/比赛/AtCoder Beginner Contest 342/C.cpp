#include <bits/stdc++.h>
using namespace std;

const int N=200005;

int n;
char s[N];
int q;

int p[35];

int main() {
    scanf("%d",&n);
    scanf("%s",s+1);
    scanf("%d",&q);
    for (int i=0;i<=25;++i) p[i]=i;
    while (q--) {
        char a,b;
        scanf(" %c %c",&a,&b);
        for (int i=0;i<=25;++i) {
            if (p[i]==a-'a') p[i]=b-'a';
        }
    }
    for (int i=1;i<=n;++i) {
        printf("%c",p[s[i]-'a']+'a');
    }
    return 0;
}