#include <bits/stdc++.h>
using namespace std;

const int N=105;

struct node {
    int x,y;
};

int n,t;
bool G[N][N]; // 禁止放置的格子

int dx[4]={-1,0,1,0};
int dy[4]={0,-1,0,1};

node mat[N][N]; // 奇数点匹配的偶数点是谁
bool sta[N][N]; // 奇数点是否被匹配过了

int ans; // 储存结果，可以放几块骨牌

bool check(int x,int y) { // 是否超出范围
    if (x>=1 && y>=1 && x<=n && y<=n) {
        return true;
    } else {
        return false;
    }
}

bool loc(int x,int y) { // 匈牙利算法
    for (int i=0;i<4;++i) { // 枚举与该点相连的边，其实就是四个方向的块
        int nx,ny;
        nx=x+dx[i],ny=y+dy[i]; // 连接的下一个点的 x 和 y
        // 没有越界，格子不被禁止，此轮搜索还未搜过
        if (check(nx,ny) && !G[nx][ny] && !sta[nx][ny]) {
            sta[nx][ny]=true; // 现在搜它，那就搜过了
            if (mat[nx][ny].x==-1 || loc(mat[nx][ny].x,mat[nx][ny].y)) {
                // 匹配成功
                mat[nx][ny]={x,y};
                return true; // 匹配成功就不用再往下找了
            }
        }
    }
    return false; // 四个方向都不能匹配，则失败
}

int main() {
    memset(mat,-1,sizeof(mat)); // 初始化为 -1
    scanf("%d %d",&n,&t);
    while (t--) {
        int a,b;
        scanf("%d %d",&a,&b);
        G[a][b]=true;
    }
    for (int i=1;i<=n;++i) {
        for (int j=1;j<=n;++j) {
            if ((i+j)%2==0 && !G[i][j]) { // 偶数点且此点不是禁止的
                memset(sta,0,sizeof(sta)); // 初始化
                if (loc(i,j)) ans++; // 可以放一块骨牌
            }
        }
    }
    printf("%d",ans);
    return 0;
}