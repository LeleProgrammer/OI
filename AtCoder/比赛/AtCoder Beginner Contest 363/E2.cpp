#include <bits/stdc++.h>
using namespace std;

const int N=1005;
const int K=100005;
const int inf=1e9;

typedef pair<int,int> pii;

int n,m,y;
int arr[N][N];
int cnt[K];
int f[N][N];
queue<pii> q;
int dx[4]={-1,0,1,0};
int dy[4]={0,-1,0,1};
bool flag[N][N];

bool check(int x,int y) {
    if (x>=1 && y>=1 && x<=n && y<=m) {
        return true;
    } else {
        return false;
    }
}

void bfs() {
    while (!q.empty()) {
        auto tp=q.front(); q.pop();
        int x=tp.first,y=tp.second;
        flag[x][y]=false;
        for (int i=0;i<4;++i) {
            int nx,ny;
            nx=x+dx[i];
            ny=y+dy[i];
            if (!check(nx,ny)) continue;
            if (arr[nx][ny]<=arr[x][y]) {
                if (f[nx][ny]>arr[x][y]) {
                    f[nx][ny]=arr[x][y];
                    if (!flag[nx][ny]) {
                        q.push({nx,ny});
                        flag[nx][ny]=true;
                    }
                }
            } else {
                if (f[nx][ny]>arr[nx][ny]) {
                    f[nx][ny]=arr[nx][ny];
                    if (!flag[nx][ny]) {
                        q.push({nx,ny});
                        flag[nx][ny]=true;
                    }
                }
            }
        }
    }
}

int main() {
    scanf("%d %d %d",&n,&m,&y);
    for (int i=1;i<=n;++i) {
        for (int j=1;j<=m;++j) {
            scanf("%d",&arr[i][j]);
        }
    }
    for (int i=1;i<=n;++i) {
        for (int j=1;j<=m;++j) {
            f[i][j]=inf;
        }
    }
    for (int i=1;i<=n;++i) {
        for (int j=1;j<=m;++j) {
            if ((i==1 || i==n) && (j==1 || j==m)) {
                f[i][j]=arr[i][j];
                flag[i][j]=true;
                q.push({i,j});
            }
        }
    }
    bfs();
    for (int i=1;i<=n;++i) {
        for (int j=1;j<=m;++j) {
            printf("%d ",f[i][j]);
            // cnt[f[i][j]]++;
        }
        // putchar(10);
    }
    int ans=n*m;
    for (int i=1;i<=y;++i) {
        ans-=cnt[i];
        printf("%d\n",ans);
    }
    return 0;
}

/*
hack:
5 5 10
8 8 8 8 8
8 5 8 5 8
8 3 6 3 8
8 1 2 1 8
8 8 8 8 8
*/