#include <bits/stdc++.h>
using namespace std;

int n;
char s[15];

void dfs(int pos) {
    if (pos>n) {
        for (int i=1;i<=n;++i) {
            printf("%c",s[i]);
        }
        printf("\n");
        return;
    }
    s[pos]='N';
    dfs(pos+1);
    s[pos]='Y';
    dfs(pos+1);
}

int main() {
    scanf("%d",&n);
    dfs(1);
    return 0;
}