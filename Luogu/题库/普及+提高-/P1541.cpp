#include <bits/stdc++.h>
using namespace std;

int n,m;
int a[355];
int _1,_2,_3,_4;
int f[45][45][45][45];

int main() {
    scanf("%d %d",&n,&m);
    for (int i=1;i<=n;++i) {
        scanf("%d",&a[i]);
    }
    _1=_2=_3=_4=0;
    int card;
    for (int i=1;i<=m;++i) {
        scanf("%d",&card);
        switch (card) {
            case 1: {
                _1++;
                break;
            }
            case 2: {
                _2++;
                break;
            }
            case 3: {
                _3++;
                break;
            }
            case 4: {
                _4++;
                break;
            }
            default: {
                break;
            }
        }
    }
    memset(f,0,sizeof(f));
    f[0][0][0][0]=a[1];
    for (int i=0;i<=_1;++i) {
        for (int j=0;j<=_2;++j) {
            for (int k=0;k<=_3;++k) {
                for (int p=0;p<=_4;++p) {
                    if (!i && !j && !k && !p) continue;
                    if (i) {
                        f[i][j][k][p]=max(f[i][j][k][p],f[i-1][j][k][p]);
                    }
                    if (j) {
                        f[i][j][k][p]=max(f[i][j][k][p],f[i][j-1][k][p]);
                    }
                    if (k) {
                        f[i][j][k][p]=max(f[i][j][k][p],f[i][j][k-1][p]);
                    }
                    if (p) {
                        f[i][j][k][p]=max(f[i][j][k][p],f[i][j][k][p-1]);
                    }
                    f[i][j][k][p]+=a[1+1*i+2*j+3*k+4*p]; // 这里需要+1
                }
            }
        }
    }
    printf("%d",f[_1][_2][_3][_4]);
    return 0;
}