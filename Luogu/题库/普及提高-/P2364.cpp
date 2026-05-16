#include <bits/stdc++.h>

#define max3(a,b,c) max(max(a,b),c)

using namespace std;

const int N=105;

int n,m,k;
char a[N],b[N],c[N];
int f[N][N][N];
string res[N][N][N];

int main() {
    scanf("%s %s %s",a+1,b+1,c+1);
    n=strlen(a+1); m=strlen(b+1); k=strlen(c+1);
    f[0][0][0]=1;
    for (int i=1;i<=n;++i) {
        for (int j=1;j<=m;++j) {
            for (int p=1;p<=k;++p) {
                f[i][j][p]=max3(f[i-1][j][p],f[i][j-1][p],f[i][j][p-1]);
                if (f[i][j][p]==f[i-1][j][p]) res[i][j][p]=res[i-1][j][p];
                else if (f[i][j][p]==f[i][j-1][p]) res[i][j][p]=res[i][j-1][p];
                else if (f[i][j][p]==f[i][j][p-1]) res[i][j][p]=res[i][j][p-1];
                if (a[i]==b[j] && a[i]==c[p]) {
                    f[i][j][p]=max(f[i-1][j-1][p-1]+1,f[i][j][p]);
                    if (f[i][j][p]==f[i-1][j-1][p-1]+1) res[i][j][p]=res[i-1][j-1][p-1]+a[i];
                }
            }
        }
    }
    cout<<res[n][m][k];
    return 0;
}