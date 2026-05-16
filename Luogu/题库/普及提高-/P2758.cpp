#include <bits/stdc++.h>
using namespace std;

char a[2005];
char b[2005];
int f[2005][2005];
int n,m;

int main() {
    scanf("%s",a+1);
    scanf("%s",b+1);
    n=strlen(a+1);
    m=strlen(b+1);
    memset(f,0,sizeof(f));
    for (int i=1;i<=n;++i) {
        f[i][0]=i;
    }
    for (int j=1;j<=m;++j) {
        f[0][j]=j;
    }
    for (int i=1;i<=n;++i) {
        for (int j=1;j<=m;++j) {
            if (a[i]==b[j]) f[i][j]=f[i-1][j-1];
            else f[i][j]=min(min(f[i-1][j],f[i][j-1]),f[i-1][j-1])+1;
        }
    }
    printf("%d",f[n][m]);
    return 0;
}