#include <bits/stdc++.h>
using namespace std;

// n行 m列
int n,m;

// 储藏室地图
int arr[55][55];

// 用于保存状态
// [[x,y],face]
queue< pair< pair<int,int>,int > > q;

// 读入数据
inline void read() {
    scanf("%d %d",&n,&m);
    // 读入的是格子，而机器人的位置是格点
    // 将读入的格子数据转化成格点存入arr
    memset(arr,0,sizeof(arr));
    int in;
    for (int i=0;i<n;++i) {
        for (int j=0;j<m;++j) {
            scanf("%d",&in);
            if (in==1) {
                arr[i][j]=1;
                arr[i+1][j]=1;
                arr[i][j+1]=1;
                arr[i+1][j+1]=1;
            }
        }
    }
    // 读入机器人位置
    int rbt_x,rbt_y;
}

// 广度优先搜索，BFS
void bfs() {
    ;
}

// 是否移出地图
bool checkBound(int x,int y) {
    ;
}

int main() {
    ;
}