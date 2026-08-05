#include <bits/stdc++.h>
using namespace std;

int n;
stack<int> s;
stack<int> help; // 存编号
int result[1000005];

int main() {
    memset(result,0,sizeof(0)); // 填充0 以防万一
    scanf("%d",&n); // 输入奶牛数量
    int cow;
    for (int i=1;i<=n;++i) { // i表示已经输入几只牛
        scanf("%d",&cow);
        if (s.empty()) {
            s.push(cow); // 没牛？入栈。
            help.push(i);
        } else {
            if (s.top()>=cow) {
                s.push(cow); // 身高向栈顶递减，入栈
                help.push(i);
            } else { // 身高无法递减了，开始比较
                while (true) { // 循环
                    if (s.empty()) { // 没牛了还怎么比较。。
                        s.push(cow);
                        help.push(i);
                        break; // 退出
                    }
                    if (s.top()<cow) { // 栈顶的牛比即将入栈的牛矮
                        s.pop(); // 移出栈顶的牛，这只牛的result就在help栈顶
                        result[help.top()]=i; // 得出第j头牛的result
                        help.pop(); // 牛都没了还有编号？
                    } else {
                        s.push(cow); // 身高符合了就可以加进去了
                        help.push(i);
                        break; // 退出
                    }
                }
            }
        }
    }
    for (int i=1;i<=n;++i) { // 下标从1开始，可以输出了
        printf("%d\n",result[i]);
    }
    return 0;
}