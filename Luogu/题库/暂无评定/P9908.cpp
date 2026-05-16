#include <bits/stdc++.h>
using namespace std;

int n,m;
char arr[55][55];
int ans=0;

bool check(int x,int y) {
    if (x>=1 && y>=1 && x<=n && y<=m) {
        return true;
    } else {
        return false;
    }
}

int search(int mode,int x,int y) {
    int ans=0;
    if (mode==1) { // 左上角的那一条
        while (check(x,y) && arr[x][y]=='\\') x--,y--,ans++;
    } else if (mode==2) { // 正上方
        while (check(x,y) && arr[x][y]=='|') x--,ans++;
    } else if (mode==3) { // 右上方
        while (check(x,y) && arr[x][y]=='/') x--,y++,ans++;
    } else if (mode==4) { // 左边
        while (check(x,y) && arr[x][y]=='-') y--,ans++;
    } else if (mode==5) { // 右边
        while (check(x,y) && arr[x][y]=='-') y++,ans++;
    } else if (mode==6) { // 左下
        while (check(x,y) && arr[x][y]=='/') x++,y--,ans++;
    } else if (mode==7) { // 正下方
        while (check(x,y) && arr[x][y]=='|') x++,ans++;
    } else if (mode==8) { // 右下
        while (check(x,y) && arr[x][y]=='\\') x++,y++,ans++;
    }
    return ans;
}

int dx[8]={-1,-1,-1,0,0,1,1,1};
int dy[8]={-1,0,1,-1,1,-1,0,1};

int main() {
    scanf("%d %d",&n,&m);
    for (int i=1;i<=n;++i) {
        for (int j=1;j<=m;++j) {
            scanf(" %c",&arr[i][j]);
        }
    }
    for (int i=1;i<=n;++i) {
        for (int j=1;j<=m;++j) {
            if (arr[i][j]=='+') {
                int sz=0x3f3f3f3f;
                for (int p=1;p<=8;++p) {
                    sz=min(sz,search(p,i+dx[p-1],j+dy[p-1]));
                }
                ans=max(ans,sz);
            }
        }
    }
    printf("%d",ans);
    return 0;
}