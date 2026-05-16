#include <bits/stdc++.h>

#define inf 0x3f3f3f3f

using namespace std;

int n,m;
char arr[2005][2005];
int vis[2005][2005];
int sx,sy,gx,gy,x,y,s;
queue<int> xq,yq,sq;

int dx[4]={-1,0,1,0};
int dy[4]={0,-1,0,1};

bool check(int x,int y) {
    if (x>=1 && y>=1 && x<=n && y<=m && arr[x][y]!='#') {
        return true;
    } else {
        return false;
    }
}

void bfs() {
    while (!xq.empty()) {
        x=xq.front();
        y=yq.front();
        s=sq.front();
        xq.pop();
        yq.pop();
        sq.pop();
        if (vis[x][y]<=s) continue;
        vis[x][y]=s;
        for (int i=0;i<4;++i) {
            if (check(x+dx[i],y+dy[i])) {
                xq.push(x+dx[i]);
                yq.push(y+dy[i]);
                sq.push(s+1);
            }
        }
    }
}

int main() {
    scanf("%d %d",&n,&m);
    for (int i=1;i<=n;++i) {
        for (int j=1;j<=m;++j) {
            scanf(" %c",&arr[i][j]);
            if (arr[i][j]=='S') {
                sx=i,sy=j;
            } else if (arr[i][j]=='G') {
                gx=i,gy=j;
            }
        }
    }
    for (int i=1;i<=n;++i) {
        for (int j=1;j<=m;++j) {
            if (arr[i][j]=='>') {
                arr[i][j]='#';
                for (int p=j+1;p<=m;++p) {
                    if (arr[i][p]=='.') arr[i][p]='#';
                    else break;
                }
            } else if (arr[i][j]=='<') {
                arr[i][j]='#';
                for (int p=j-1;p>=1;--p) {
                    if (arr[i][p]=='.') arr[i][p]='#';
                    else break;
                }
            } else if (arr[i][j]=='v') {
                arr[i][j]='#';
                for (int p=i+1;p<=n;++p) {
                    if (arr[p][j]=='.') arr[p][j]='#';
                    else break;
                }
            } else if (arr[i][j]=='^') {
                arr[i][j]='#';
                for (int p=i-1;p>=1;--p) {
                    if (arr[p][j]=='.') arr[p][j]='#';
                    else break;
                }
            }
        }
    }
    for (int i=1;i<=n;++i) {
        for (int j=1;j<=m;++j) {
            vis[i][j]=inf;
        }
    }
    xq.push(sx);
    yq.push(sy);
    sq.push(0);
    bfs();
    if (vis[gx][gy]==inf) printf("-1\n");
    else printf("%d\n",vis[gx][gy]);
    return 0;
}