#include <bits/stdc++.h>
using namespace std;

queue<int> q;

int main() {
    int k,m;
    scanf("%d",&k); // 输入人数
    scanf("%d",&m); // 数数个数
    
    // 构建队列
    for (int i=1;i<=k;++i) {
        q.push(i);
    }

    // 开始数数
    while (true) {
        // 数m-1个数
        for (int i=1;i<=m-1;++i) {
            // 出队并再次排到队尾
            q.push(q.front());
            q.pop();
        }
        // 队头就是数到的数
        // 输出
        printf("%d ",q.front());
        // 出队
        q.pop();
        if (q.size()==1) {
            printf("%d",q.front());
            return 0;
        }
    }
    return 0; // 可加可不加
}