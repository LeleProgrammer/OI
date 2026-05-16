#include <bits/stdc++.h>
using namespace std;

const int N=505;

int n,m,k;
string op;
char a[N][N];

bool check(int x,int y) {
    if (x>=1 && y>=1 && x<=n && y<=m && a[x][y]!='#') {
        return true;
    } else {
        return false;
    }
}

int main() {
    scanf("%d %d %d",&n,&m,&k);
    cin>>op;
    for (int i=1;i<=n;++i) {
        for (int j=1;j<=m;++j) {
            scanf(" %c",&a[i][j]);
        }
    }
    int ans=0;
    for (int i=1;i<=n;++i) {
        for (int j=1;j<=m;++j) {
            if (a[i][j]=='#') continue;
            int x=i,y=j;
            bool ok=true;
            for (int p=0;p<k;++p) {
                if (op[p]=='L') y--;
                else if (op[p]=='R') y++;
                else if (op[p]=='U') x--;
                else x++;
                if (!check(x,y)) {
                    ok=false;
                    break;
                }
            }
            if (ok) ans++;
        }
    }
    printf("%d",ans);
    return 0;
}