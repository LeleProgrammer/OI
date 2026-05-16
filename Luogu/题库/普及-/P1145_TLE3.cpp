#include <bits/stdc++.h>
using namespace std;

int k;
queue<bool> q; // 0: bad; 1: good

int main() {
    scanf("%d",&k); // 输入人数
    
    // 构建队列
    for (int i=1;i<=k;++i) {
        q.push(true);
    }
    for (int i=1;i<=k;++i) {
        q.push(false);
    }

    // 初始m
    int m=k+1;

    // 开始数数
    while (true) {
        if (m%(2*k)<=k && m%(2*k)>=1) {
            ++m;
            continue;
        }
        // 数m-1个数
        for (int i=1;i<=m-1;++i) {
            // 出队并再次排到队尾
            q.push(q.front());
            q.pop();
        }
        // 队头就是数到的数
        if (q.front()==false) {
            // 出队
            q.pop();
            if (q.size()==k) {
                printf("%d",m);
                return 0;
            }
        } else {
            // 不能继续了
            while (!q.empty()) {
                q.pop(); // 清空队列
            }
            // 重构队列
            for (int i=1;i<=k;++i) {
                q.push(true);
            }
            for (int i=1;i<=k;++i) {
                q.push(false);
            }
            // 枚举下一个m
            ++m;
        }
    }
}