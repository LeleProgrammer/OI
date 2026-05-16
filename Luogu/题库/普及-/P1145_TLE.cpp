#include <bits/stdc++.h>
using namespace std;

struct Node { // 节点
    bool type; // false: bad; true: good;
    Node* next; // 指针域
};

int k;
int done;
Node* head;
Node* people;

// 初始化
void restore() {
    // 创建链表
    // 头节点
    head=new Node;
    // people 指针先指向头节点
    people=head;
    for (int i=1;i<=k;++i) {
        people->type=true;
        // 下一个节点
        people->next=new Node; // 创建节点
        people=people->next; // 移动到下一个节点
    }
    for (int i=1;i<=k;++i) {
        people->type=false;
        if (i!=k) {
            // 下一个节点
            people->next=new Node; // 创建节点
            people=people->next; // 移动到下一个节点
        }
    }
    people->next=head;
    done=0; // 已经完成了几个查询
    people=head; // 从头节点开始
}

void test(Node* head) {
    Node* people=head;
    while (true) {
        printf("%d\n",people->type);
        people=people->next;
        //printf("Next%d %d\n",people->type,people->checked);
        if (people==head) {
            //printf("End%d %d\n",people->type,people->checked);
            break;
        }
    }
    printf("\n");
    return ;
}

int main() {
    // 输入
    scanf("%d",&k);

    // 初始化
    restore();

    // 开始数数
    int m=k+1; // 设置m的初始值
    while (true) {
        // 数到m-2个数
        for (int i=1;i<=m-2;++i) {
            people=people->next;
        }
        // 此时people指针指向第m-1个数
        if (people->next->type==false) {
            people->next=people->next->next; // 删除第m个节点
            people=people->next;
            ++done; // 完成了一个查询
            if (done==k) { // 数量足够了
                printf("%d",m); // 直接输出结果
                return 0; // 退出程序
            }
        } else {
            // 复原
            restore();
            // 开始下一个m的枚举
            ++m;
        }
    }
    return 0; // 可加可不加，反正也不会到这来
}