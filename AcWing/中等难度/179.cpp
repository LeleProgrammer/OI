#include <bits/stdc++.h>
using namespace std;

typedef pair<int,string> pis;
typedef pair<string,char> psc;
typedef pair<int,int> pii;

// bfs 四个方向及其对应的字符
int dx[4]={-1,0,1,0};
int dy[4]={0,-1,0,1};
char op[4]={'u','l','d','r'};

// 输入以及没有'x'的输入
string in,in_no_x;

// 终点
string dest="12345678x";

// A* 算法 优先队列 <估计值，对应的字符串>
priority_queue< pis,vector<pis>,greater<pis> > q;

// 记录真实距离
unordered_map< string,int > dis;

// 上一状态的字符串以及上一状态是如何变换为当前状态的
unordered_map< string,psc > previous;

// 检查是否越界
bool check(int x,int y) {
    if (x>=0 && y>=0 && x<=2 && y<=2) {
        return true;
    } else {
        return false;
    }
}

// 求逆序对个数
int find_rev(string s) {
    int ans=0;
    for (int i=0;i<8;++i) {
        for (int j=i+1;j<8;++j) {
            if (s[i]>s[j]) {
                ans++;
            }
        }
    }
    return ans;
}

// 估价函数，最坏情况就是所有数到它们应该在的位置的曼哈顿距离之和
int predict(string s) {
    int dis_sum=0;
    for (int i=0;i<=8;++i) {
        if (s[i]=='x') continue;
        int num=s[i]-'1';
        dis_sum+=abs(i/3-num/3)+abs(i%3-num%3);
    }
    return dis_sum;
}

// A* 算法
string A_star(string start) {
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
        // 寻找当前状态的空位 x 在哪里
        int x,y;
        for (int i=0;i<=8;++i) {
            if (curr[i]=='x') {
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
                    previous[curr]=make_pair(origin,op[i]);
                    q.push(make_pair(dis[curr]+predict(curr),curr));
                }
                swap(curr[nx*3+ny],curr[x*3+y]);
            }
        }
    }
    // 最后反推回去找路径，找完把路径再反过来
    string res="";
    string now=dest;
    while (now!=start) {
        res.push_back(previous[now].second);
        now=previous[now].first;
    }
    reverse(res.begin(),res.end());
    return res;
}

int main() {
    for (int i=0;i<=8;++i) {
        char c;
        scanf(" %c",&c);
        in.push_back(c);
        if (c!='x') in_no_x.push_back(c);
    }
    // 逆序对数量是奇数则无解
    if (find_rev(in_no_x)%2) puts("unsolvable");
    else cout<<A_star(in);
    return 0;
}