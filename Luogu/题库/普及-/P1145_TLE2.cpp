#include <bits/stdc++.h>
using namespace std;

struct Node { // 节点
    bool type; // false: bad; true: good;
    bool checked; // 标记是否被查询过
    Node* next; // 指针域
};

// 填充所有节点的checked为false
// 只需要传入一个头节点指针就可以填充了
void fill_checked_with_false(Node* head) {
    Node* people=head; // 从head头节点开始
    while (true) {
        people->checked=false;
        people=people->next;
        // 循环链表 people再一次等于head头节点的时候
        // 说明已经完成一轮填充了
        if (people==head) {
            break; // 退出循环
        }
    }
    return ; // 结束填充
}

// 测试用的
// void test(Node* head) {
//     Node* people=head;
//     while (true) {
//         printf("%d %d\n",people->type,people->checked);
//         people=people->next;
//         //printf("Next%d %d\n",people->type,people->checked);
//         if (people==head) {
//             //printf("End%d %d\n",people->type,people->checked);
//             break;
//         }
//     }
//     printf("\n");
//     return ;
// }

int main() {
    // 输入
    int k; // k人
    scanf("%d",&k);

    // 创建链表
    // 头节点
    Node* head=new Node;
    // people 指针先指向头节点
    Node* people=head;
    for (int i=1;i<=k;++i) {
        people->type=true;
        people->checked=false;
        // 下一个节点
        people->next=new Node; // 创建节点
        people=people->next; // 移动到下一个节点
    }
    for (int i=1;i<=k;++i) {
        people->type=false;
        people->checked=false;
        if (i!=k) {
            // 下一个节点
            people->next=new Node; // 创建节点
            people=people->next; // 移动到下一个节点
        }
    }
    people->next=head;
    // Don't do this: people->next=head->next;
    // Don't do this: people->type=head->type;
    // Don't do this: people->checked=head->checked;
    /*
    重大事件！！！！！！！
    这个错误改了半个下午哒！！！！！！！！！！！！
    不许删掉这个注释！！！！！！！！
    上面，people三行赋值不行，这样这个循环的头节点的地址和head的地址不一样，
    然后就会导致fill_checked_with_false方法中people枚举一圈之后people==head为false，
    最后无法跳出while循环！！！！！！！！！！！！！
    修改修改！！！！！！！！！！！！！！！！！！！
    改完也不要删！！！！！！！！！！！
    千万不要删！！！！！！！！！！！！！！！
    还有上面的for循环，里面最后一次枚举不能再创建并移动到下一个节点！！！！！！！！！！！
    这里给两种修改方式：
    1. 上面for循环中最后一次枚举不能执行创建节点和移动到下一个节点，
    然后for循环下面people->next=head，people下一个节点直接指向head头节点。
    2. 上面for循环的节点创建和people指针的移动保留，
    然后for循环下面，注释里的三行Don't do this给它加回来，
    最后再写一行head=people，既然要创建新节点，那么就算两个节点内容一致，
    两个节点的内存地址是不同的，所以干脆直接head头节点原来的地址不要它了，
    把head头节点设置为people，把头节点换成新的。
    这里为了方便直接用第一种修改方式改好~~~
    最后再说一遍，这一堆注释不许删掉！！！！！！！！！！！！
    */

    // 开始数数
    int m=k+1; // 设置m的初始值
    int done=0; // 已经完成了几个查询
    while (true) {
        // 数到m-1个数
        for (int i=1;i<=m-1;++i) {
            people=people->next;
            while (people->checked) {
                people=people->next;
            }
        }
        // 此时people指针指向第m个数
        if (people->type==false) {
            people->checked=true; // 查询过了
            ++done; // 完成了一个查询
            // Don't do this: people=people->next; // people要往后推一位
            // 这里people可能不仅仅往后推一位
            // 因为有可能下一位也是查询过的了
            while (people->checked) {
                people=people->next; // 往后推
            }
            if (done==k) { // 数量足够了
                printf("%d",m); // 直接输出结果
                return 0; // 退出程序
            }
        } else {
            // 填充
            fill_checked_with_false(head);
            // 开始下一个m的枚举
            ++m;
            // 把people设置为head头节点
            people=head;
            // done初始化
            done=0;
        }
    }
    return 0; // 可加可不加，反正也不会到这来
}