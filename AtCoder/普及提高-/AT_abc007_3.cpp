#include <bits/stdc++.h>
using namespace std;

int res[55][55];

int n,m,sx,sy,gx,gy;

bool road[55][55];

queue<int> x;
queue<int> y;
queue<int> step;

int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};

bool check(int x,int y) {
    if (x>=1 && y>=1 && road[x][y]) return true;
    else return false;
}

void bfs() {
    int getx,gety,getstep;
    while (!x.empty()) {
        getx=x.front();
        gety=y.front();
        getstep=step.front();
        x.pop();
        y.pop();
        step.pop();
        if (getstep>=res[getx][gety]) continue;
        res[getx][gety]=getstep;
        for (int i=0;i<4;++i) {
            if (check(getx+dx[i],gety+dy[i])) {
                x.push(getx+dx[i]);
                y.push(gety+dy[i]);
                step.push(getstep+1);
            }
        }
    }
}

int main() {
    scanf("%d %d",&n,&m);
    scanf("%d %d",&sx,&sy);
    scanf("%d %d",&gx,&gy);
    for (int i=1;i<=n;++i) {
        for (int j=1;j<=m;++j) {
            char c;
            cin>>c;
            if (c=='#') road[i][j]=false;
            else road[i][j]=true;
            res[i][j]=0x3f3f3f3f;
        }
    }
    x.push(sx);
    y.push(sy);
    step.push(0);
    bfs();
    printf("%d\n",res[gx][gy]);
    return 0;
}