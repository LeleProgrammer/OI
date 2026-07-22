#include <bits/stdc++.h>
using namespace std;

const int MAXN=55;
const int MAXM=55;

// 方格数量
int n,m;

// 机器人初始位置
int rbt_x,rbt_y;

// 目标位置
int target_x,target_y;

// 机器人初始朝向
char rbt_face; // ESWN

// 存储格点数据
int barriers[MAXN][MAXM];

// 队列
// [[x,y],[face,time]]
queue<pair<pair<int,int>,pair<char,int> > > q;

// 记录格点和朝向的局部最优解
int mem[MAXN][MAXM][4];

// 从队列中获取的数据
int gx,gy;
char gface;
int gtime;

// 从NSWE转化成下标
// face to item
int ftoi(char c) {
    int ans;
    switch (c) {
        case 'N': {
            ans=0;
            break;
        }
        case 'S': {
            ans=1;
            break;
        }
        case 'W': {
            ans=2;
            break;
        }
        case 'E': {
            ans=3;
            break;
        }
        default: {
            break;
        }
    }
    return ans;
}

// 初始化
inline void init() {
    scanf("%d %d",&n,&m);
    memset(barriers,0,sizeof(barriers));
    int barrier;
    for (int i=0;i<n;++i) {
        for (int j=0;j<m;++j) {
            // 读入方格数据
            scanf("%d",&barrier);
            // 转换为格点数据写入
            if (barrier==1) {
                // 有障碍则填充四个格点
                barriers[i][j]=1;
                barriers[i+1][j]=1;
                barriers[i][j+1]=1;
                barriers[i+1][j+1]=1;
            }
        }
    }
    // 读入机器人初始位置
    scanf("%d %d",&rbt_x,&rbt_y);
    // 读入目标位置
    scanf("%d %d",&target_x,&target_y);
    // 读入机器人初始朝向
    cin>>rbt_face;
    // 把初始信息添加到队列
    q.push(make_pair(make_pair(rbt_x,rbt_y),make_pair(rbt_face,0)));
    // 初始化格点局部最优解数组
    for (int i=0;i<MAXN;++i) {
        for (int j=0;j<MAXM;++j) {
            for (int f=0;f<4;++f) {
                mem[i][j][f]=0x7fffffff;
            }
        }
    }
    return ;
}

// 是否在界内
bool checkBound(int x,int y) {
    if (x>=1 && y>=1 && x<=n-1 && y<=m-1) { // 机器人不能走墙壁
        return true;
    } else {
        return false;
    }
}

// 是否遇到障碍
bool isBarrier(int x,int y) {
    if (barriers[x][y]) {
        return true;
    } else {
        return false;
    }
}

// 广度优先搜索
void bfs() {
    while (!q.empty()) {
        // 出队
        gx=q.front().first.first;
        gy=q.front().first.second;
        gface=q.front().second.first;
        gtime=q.front().second.second;
        q.pop();
        if (!checkBound(gx,gy)) {
            // 不在界内就不能继续
            continue;
        }
        if (isBarrier(gx,gy)) {
            // 是障碍就不能继续
            continue;
        }
        if (gtime<mem[gx][gy][ftoi(gface)]) {
            // 现在有局部更优解
            // 将局部更优解更新
            mem[gx][gy][ftoi(gface)]=gtime;
            // 五种操作 三种移动 两种转向
            // 三种移动
            if (gface=='N') {
                // 向上移动
                // 移动1~3格
                for (int forward=1;forward<=3;++forward) {
                    if (!isBarrier(gx-forward,gy)) {
                        q.push(make_pair(make_pair(gx-forward,gy),make_pair(gface,gtime+1)));
                    } else {
                        break;
                    }
                }
            } else if (gface=='S') {
                // 向下移动
                // 移动1~3格
                for (int forward=1;forward<=3;++forward) {
                    if (!isBarrier(gx+forward,gy)) {
                        q.push(make_pair(make_pair(gx+forward,gy),make_pair(gface,gtime+1)));
                    } else {
                        break;
                    }
                }
            } else if (gface=='W') {
                // 向左移动
                // 移动1~3格
                for (int forward=1;forward<=3;++forward) {
                    if (!isBarrier(gx,gy-forward)) {
                        q.push(make_pair(make_pair(gx,gy-forward),make_pair(gface,gtime+1)));
                    } else {
                        break;
                    }
                }
            } else {
                // 向右移动
                // 移动1~3格
                for (int forward=1;forward<=3;++forward) {
                    if (!isBarrier(gx,gy+forward)) {
                        q.push(make_pair(make_pair(gx,gy+forward),make_pair(gface,gtime+1)));
                    } else {
                        break;
                    }
                }
            }
            // 两种转向
            if (gface=='N' || gface=='S') {
                q.push(make_pair(make_pair(gx,gy),make_pair('W',gtime+1)));
                q.push(make_pair(make_pair(gx,gy),make_pair('E',gtime+1)));
            } else {
                q.push(make_pair(make_pair(gx,gy),make_pair('N',gtime+1)));
                q.push(make_pair(make_pair(gx,gy),make_pair('S',gtime+1)));
            }
        } else {
            // 之前有局部更优解，忽略
            continue;
        }
    }
    return ;
}

// 输出
inline void output() {
    int result=0x7fffffff;
    for (int face=0;face<4;++face) {
        // 记录最小值
        result=min(result,mem[target_x][target_y][face]);
    }
    // 如果最小值是0x7fffffff，那么没有结果
    if (result==0x7fffffff) {
        result=-1;
    }
    // 输出结果
    printf("%d",result);
}

// 主程序
int main() {
    init();
    bfs();
    output();
    return 0;
}