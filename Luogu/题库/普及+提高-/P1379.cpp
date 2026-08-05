#include <bits/stdc++.h>
using namespace std;

typedef pair<int,string> pis;
typedef pair<string,char> psc;
typedef pair<int,int> pii;

// bfs 四个方向及其对应的字符
int dx[4]={-1,0,1,0};
int dy[4]={0,-1,0,1};
char op[4]={'u','l','d','r'};

// 输入以及没有'0'的输入
string in,in_no_0;

// 终点
string dest="123804765";

// A* 算法 优先队列 <估计值，对应的字符串>
priority_queue< pis,vector<pis>,greater<pis> > q;

// 记录真实距离
unordered_map< string,int > dis;

// 检查是否越界
bool check(int x,int y) {
    if (x>=0 && y>=0 && x<=2 && y<=2) {
        return true;
    } else {
        return false;
    }
}

// 估价函数，最坏情况就是所有数到它们应该在的位置的曼哈顿距离之和
int predict(string s) {
    int dis_sum=0;
    for (int i=0;i<=8;++i) {
        if (s[i]=='0') continue;
        int num=s[i]-'1';
        dis_sum+=abs(i/3-num/3)+abs(i%3-num%3);
    }
    return dis_sum;
}

// A* 算法
int A_star(string start) {
    // 先放入起点
    q.push(make_pair(predict(start),start));
    // 初始步数为 0
    dis[start]=0;
    // 广搜
    while (!q.empty()) {
        // 出队
        auto tp=q.top(); q.pop();
        // 获取当前状态
        string curr=tp.second;
        // 如果已经到了终点就退出
        if (curr==dest) break;
        // 寻找当前状态的空位 0 在哪里
        int x,y;
        for (int i=0;i<=8;++i) {
            if (curr[i]=='0') {
                x=i/3,y=i%3;
                break;
            }
        }
        // 向四个方向扩展
        string origin=curr;
        for (int i=0;i<=3;++i) {
            int nx,ny;
            nx=x+dx[i],ny=y+dy[i];
            if (check(nx,ny)) {
                swap(curr[nx*3+ny],curr[x*3+y]);
                // 之前没搜过，或者之前搜的不是最优解
                if (dis.count(curr)==0 || dis[curr]>dis[origin]+1) {
                    dis[curr]=dis[origin]+1;
                    q.push(make_pair(dis[curr]+predict(curr),curr));
                }
                swap(curr[nx*3+ny],curr[x*3+y]);
            }
        }
    }
    return dis[dest];
}

int main() {
    for (int i=0;i<=8;++i) {
        char c;
        scanf(" %c",&c);
        in.push_back(c);
        if (c!='0') in_no_0.push_back(c);
    }
    printf("%d",A_star(in));
    return 0;
}