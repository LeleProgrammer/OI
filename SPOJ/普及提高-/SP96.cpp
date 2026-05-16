#include <bits/stdc++.h>
using namespace std;

int n,m;
int sx,sy,ex,ey;
int gx,gy,gs;
queue<int> x;
queue<int> y;
queue<int> step;
int mem[105][105];
int arr[105][105];

int dx[4]={-1,0,1,0};
int dy[4]={0,-1,0,1};

bool check(int x,int y) {
    if (x>=1 && y>=1 && x<=n && y<=m && arr[x][y]!=-1) {
        return true;
    } else {
        return false;
    }
}

void bfs() {
    while (!x.empty()) {
        gx=x.front();
        gy=y.front();
        gs=step.front();
        x.pop();
        y.pop();
        step.pop();
        if (mem[gx][gy]<=gs) continue;
        mem[gx][gy]=gs;
        if (gx==ex && gy==ey) continue;
        for (int i=0;i<=3;++i) {
            if (check(gx+dx[i],gy+dy[i])) {
                x.push(gx+dx[i]);
                y.push(gy+dy[i]);
                step.push(gs+arr[gx][gy]);
            }
        }
    }
}

int main() {
    while (true) {
        scanf("%d %d",&m,&n);
        if (n==0 && m==0) break;
        for (int i=1;i<=n;++i) {
            for (int j=1;j<=m;++j) {
                char c;
                cin>>c;
                if (c=='X') arr[i][j]=-1;
                else if (c=='S') sx=i,sy=j,arr[i][j]=0;
                else if (c=='D') ex=i,ey=j,arr[i][j]=0;
                else arr[i][j]=c-'0';
            }
        }
        x.push(sx);
        y.push(sy);
        step.push(0);
        memset(mem,0x3f,sizeof(mem));
        bfs();
        printf("%d\n",mem[ex][ey]);
    }
    return 0;
}