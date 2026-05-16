#include <bits/stdc++.h>
using namespace std;

const int N=2005;
const int M=1005;

int n,m;
int a[N][N];
vector<int> b[N][M];
bool c[N][N];

int main() {
    scanf("%d %d",&n,&m);
    for (int i=1;i<=n;++i) {
        for (int j=1;j<=m;++j) {
            scanf("%d",&a[i][j]);
            int sz=b[j][a[i][j]].size();
            for (int p=0;p<sz;++p) {
                c[i][b[j][a[i][j]][p]]^=1;
                // if (p+15<sz) {
                //     c[i][b[j][a[i][j]][++p]]^=1;
                //     c[i][b[j][a[i][j]][++p]]^=1;
                //     c[i][b[j][a[i][j]][++p]]^=1;
                //     c[i][b[j][a[i][j]][++p]]^=1;
                //     c[i][b[j][a[i][j]][++p]]^=1;
                //     c[i][b[j][a[i][j]][++p]]^=1;
                //     c[i][b[j][a[i][j]][++p]]^=1;
                //     c[i][b[j][a[i][j]][++p]]^=1;
                //     c[i][b[j][a[i][j]][++p]]^=1;
                //     c[i][b[j][a[i][j]][++p]]^=1;
                //     c[i][b[j][a[i][j]][++p]]^=1;
                //     c[i][b[j][a[i][j]][++p]]^=1;
                //     c[i][b[j][a[i][j]][++p]]^=1;
                //     c[i][b[j][a[i][j]][++p]]^=1;
                //     c[i][b[j][a[i][j]][++p]]^=1;
                // }
            }
            b[j][a[i][j]].push_back(i);
        }
    }
    int ans=0;
    for (int i=1;i<=n;++i) {
        for (int j=1;j<i;++j) {
            if (c[i][j]) ans++;
        }
    }
    printf("%d",ans);
    return 0;
}