#include <bits/stdc++.h>

#define inf 0x3f3f3f3f

using namespace std;

int n;
int sx,sy,sz;
int ex,ey,ez;
int v;
int gx,gy,gz,gs;

bool bar[105][105][105];

int dx[6]={-1,0,1,0,0,0};
int dy[6]={0,-1,0,1,0,0};
int dz[6]={0,0,0,0,1,-1};

queue<int> x;
queue<int> y;
queue<int> z;
queue<int> s;

int ans[105][105][105];

bool check(int x,int y,int z,int s) {
    if (x>=1 && y>=1 && z>=1 && x<=n && y<=n && z<=n && !bar[x][y][z] && s<ans[x][y][z]) {
        return true;
    } else {
        return false;
    }
}

void bfs() {
    while (!x.empty()) {
        gx=x.front();
        gy=y.front();
        gz=z.front();
        gs=s.front();
        x.pop();
        y.pop();
        z.pop();
        s.pop();
        if (gs>=ans[gx][gy][gz]) continue;
        ans[gx][gy][gz]=gs;
        for (int i=0;i<=5;++i) {
            if (check(gx+dx[i],gy+dy[i],gz+dz[i],gs)) {
                x.push(gx+dx[i]);
                y.push(gy+dy[i]);
                z.push(gz+dz[i]);
                s.push(gs+1);
            }
        }
    }
}

int main() {
    scanf("%d",&n);
    scanf("%d %d %d",&sx,&sy,&sz);
    scanf("%d %d %d",&ex,&ey,&ez);
    memset(bar,false,sizeof(bar));
    for (int i=1;i<=n;++i) {
        for (int j=1;j<=n;++j) {
            for (int k=1;k<=n;++k) {
                ans[i][j][k]=inf;
            }
        }
    }
    for (int i=1;i<=n;++i) {
        for (int j=1;j<=n;++j) {
            for (int k=1;k<=n;++k) {
                scanf("%1d",&v);
                if (v) bar[j][k][i]=true;
            }
        }
    }
    x.push(sx);
    y.push(sy);
    z.push(sz);
    s.push(0);
    bfs();
    if (ans[ex][ey][ez]==inf) printf("-1");
    else printf("%d",ans[ex][ey][ez]);
    return 0;
}