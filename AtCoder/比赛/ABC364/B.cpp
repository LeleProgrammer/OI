#include <bits/stdc++.h>
using namespace std;

const int N=55;

int n,m;
int arr[N][N];
int x,y;
string op;

int main() {
    scanf("%d %d",&n,&m);
    scanf("%d %d",&x,&y);
    for (int i=1;i<=n;++i) {
        for (int j=1;j<=m;++j) {
            char c;
            scanf(" %c",&c);
            if (c=='.') arr[i][j]=0;
            else arr[i][j]=1;
        }
    }
    cin>>op;
    for (char c:op) {
        if (c=='U' && x>1 && !arr[x-1][y]) x--;
        else if (c=='D' && x<n && !arr[x+1][y]) x++;
        else if (c=='L' && y>1 && !arr[x][y-1]) y--;
        else if (c=='R' && y<m && !arr[x][y+1]) y++;
    }
    printf("%d %d",x,y);
    return 0;
}