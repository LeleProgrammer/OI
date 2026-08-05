// #pragma GCC optimize(2)

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int number;
    int type;
    Node* next;
};

int n;
Node* root=nullptr;

inline void init() {
    scanf("%d",&n);
    Node* ptr=root;
    for (int i=1;i<=n;++i) {
        if (ptr==nullptr) {
            ptr=(Node*)malloc(sizeof(Node));
            root=ptr;
        }
        ptr->number=i;
        scanf("%d",&(ptr->type));
        if (i<n) {
            ptr->next=(Node*)malloc(sizeof(Node));
        } else {
            ptr->next=nullptr;
        }
        ptr=ptr->next;
    }
    return ;
}

void delete_node(int number) {
    printf("%d ",number);
    // search root
    if (root->number==number) {
        root=root->next;
        return ;
    }
    // search from root->next
    /*
    Debug Log: ptr!=nullptr 不可写为 ptr->next!=nullptr
    for (1;2;3) {
        code;
    }
    运行顺序：1->2->code->3->2->code->3->2->code->...
    逻辑：只要ptr的下一个不是空的，就往下一个去
    但因为循环一次结束后ptr已经成为ptr->next了，
    所以此时逻辑中的“ptr的下一个”便是ptr本身
    但又有一个问题就是，for初始化后会进行“2”的判断，
    所以只需要在循环中添加对ptr->next的特判，
    这时候就不把“2”改为ptr->next!=nullptr了，
    因为如果这样的话，每次搜索会忽略链表尾部
    备注：pop中的for循环道理相同，但是在pop中不需要进行
    if (ptr->next==nullptr) 的特判，因为循环中
    没有和ptr->next有关的东西
    */
    for (Node* ptr=root;ptr!=nullptr;ptr=ptr->next) {
        if (ptr->next==nullptr) {
            // 如果自己就是要删除元素
            // 那么这个元素绝对是root
            if (ptr==root) {
                root=nullptr;
            }
            return ;
        }
        if (ptr->next->number==number) {
            ptr->next=ptr->next->next;
            return ;
        }
    }
}

int pop() {
    int type=-1;
    int length=0;
    for (Node* ptr=root;ptr!=nullptr;ptr=ptr->next) {
        ++length;
        if (type!=ptr->type) {
            type=ptr->type;
            delete_node(ptr->number);
        }
    }
    printf("\n");
    return length;
}

int main() {
    init();
    while (pop());
    return 0;
}