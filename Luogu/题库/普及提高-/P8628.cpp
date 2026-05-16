#include <bits/stdc++.h>

#define inf 0x3f3f3f3f

using namespace std;

int n;
char arr[105][105];
int dis[105][105];
int ax,ay,bx,by;

int dx[4]={-1,0,1,0};
int dy[4]={0,-1,0,1};

queue<int> x;
queue<int> y;
queue<int> s;
int gx,gy,gs;

bool check(int x,int y,char c) {
    if (x>=1 && y>=1 && x<=n && y<=n && c!=arr[x][y]) {
        return true;
    } else {
        return false;
    }
}

void bfs() {
    while (!x.empty()) {
        gx=x.front();
        gy=y.front();
        gs=s.front();
        x.pop();
        y.pop();
        s.pop();
        if (dis[gx][gy]<=gs) continue;
        dis[gx][gy]=gs;
        for (int i=0;i<4;++i) {
            if (check(gx+dx[i],gy+dy[i],arr[gx][gy])) {
                x.push(gx+dx[i]);
                y.push(gy+dy[i]);
                s.push(gs+1);
            }
        }
    }
}

int main() {
    for (int i=0;i<=104;++i) {
        for (int j=0;j<=104;++j) {
            dis[i][j]=inf;
        }
    }
    scanf("%d",&n);
    for (int i=1;i<=n;++i) {
        for (int j=1;j<=n;++j) {
            scanf(" %c",&arr[i][j]);
            if (arr[i][j]=='A') ax=i,ay=j;
            else if (arr[i][j]=='B') bx=i,by=j;
        }
    }
    x.push(ax);
    y.push(ay);
    s.push(0);
    bfs();
    if (dis[bx][by]==inf) printf("-1");
    else printf("%d",dis[bx][by]);
    return 0;
}