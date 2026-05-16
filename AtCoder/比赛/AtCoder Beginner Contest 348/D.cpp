#include <bits/stdc++.h>
using namespace std;

const int N=205;

int n,m,k;
char a[N][N];
int b[N][N];
bool flag[N][N];
int sx,sy,tx,ty;
queue<int> x,y;

int dx[4]={-1,0,1,0};
int dy[4]={0,-1,0,1};

bool check(int x,int y) {
    if (x>=1 && y>=1 && x<=n && y<=m && a[x][y]!='#') {
        return true;
    } else {
        return false;
    }
}

void bfs(int r,int c,int e) {
    x.push(r);
    y.push(c);
    int dis[N][N];
    bool inq[N][N];
    memset(dis,-1,sizeof(dis));
    memset(inq,0,sizeof(inq));
    dis[r][c]=e;
    inq[r][c]=true;
    while (!x.empty()) {
        int gx=x.front(); x.pop();
        int gy=y.front(); y.pop();
        int gs=dis[gx][gy];
        flag[gx][gy]=true;
        inq[r][c]=false;
        if (!gs) continue;
        for (int i=0;i<4;++i) {
            int nx=gx+dx[i];
            int ny=gy+dy[i];
            if (check(nx,ny) && dis[nx][ny]<gs-1) {
                dis[nx][ny]=gs-1;
                if (inq[nx][ny]) continue;
                x.push(nx);
                y.push(ny);
                inq[nx][ny]=true;
            }
        }
    }
}

int main() {
    scanf("%d %d",&n,&m);
    for (int i=1;i<=n;++i) {
        for (int j=1;j<=m;++j) {
            scanf(" %c",&a[i][j]);
            if (a[i][j]=='S') sx=i,sy=j;
            if (a[i][j]=='T') tx=i,ty=j;
        }
    }
    scanf("%d",&k);
    for (int i=1;i<=k;++i) {
        int r,c,e;
        scanf("%d %d %d",&r,&c,&e);
        b[r][c]=e;
    }
    if (!b[sx][sy]) {
        puts("No");
        return 0;
    }
    bfs(sx,sy,b[sx][sy]);
    b[sx][sy]=0;
    k--;
    bool ok;
    while (k && !flag[tx][ty]) {
        ok=false;
        for (int i=1;i<=n;++i) {
            for (int j=1;j<=n;++j) {
                if (b[i][j] && flag[i][j]) {
                    bfs(i,j,b[i][j]);
                    b[i][j]=0;
                    k--;
                    ok=true;
                    break;
                }
            }
        }
        if (!ok) {
            break;
        }
    }
    if (flag[tx][ty]) puts("Yes");
    else puts("No");
    return 0;
}