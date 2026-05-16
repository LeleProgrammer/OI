#include <bits/stdc++.h>
using namespace std;

int arr[9][9];
int ans;

int dx[8]={-1,-2,-2,-1,1,2,2,1};
int dy[8]={-2,-1,1,2,2,1,-1,-2};

bool check(int x,int y) {
    if (x>=1 && y>=1 && x<=8 && y<=8) {
        return true;
    } else {
        return false;
    }
}

int main() {
    char s[3];
    scanf("%s",s);
    int x,y;
    x=s[0]-'a'+1,y=s[1]-'0';
    arr[x][y]=1;
    for (int i=1;i<=8;++i) arr[x][i]=1;
    for (int i=1;i<=8;++i) arr[i][y]=1;
    for (int i=0;i<=7;++i) if (check(x+dx[i],y+dy[i])) arr[x+dx[i]][y+dy[i]]=1;
    scanf("%s",s);
    x=s[0]-'a'+1,y=s[1]-'0';
    arr[x][y]=1;
    for (int i=0;i<=7;++i) if (check(x+dx[i],y+dy[i])) arr[x+dx[i]][y+dy[i]]=1;
    for (int i=1;i<=8;++i) {
        for (int j=1;j<=8;++j) {
            if (!arr[i][j]) ans++;
        }
    }
    printf("%d",ans);
    return 0;
}