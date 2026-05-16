#include <bits/stdc++.h>
using namespace std;

struct Block {
    int length;
    int start;
    int type;
    Block* next;
};

int n;
Block* root=nullptr;

inline void init() {
    root=(Block*)malloc(sizeof(Block));
    root->next=nullptr;
    Block* ptr=root;
    scanf("%d",&n);
    int in;
    int type=-1;
    int length=0;
    int start;
    for (int i=1;i<=n;++i) {
        scanf("%d",&in);
        if (type==-1) {
            type=in;
            ++length;
            start=i;
        } else {
            if (type==in) {
                ++length;
            } else {
                ptr->next=(Block*)malloc(sizeof(Block));
                ptr->next->length=length;
                ptr->next->start=start;
                ptr->next->type=type;
                ptr=ptr->next;
                type=in;
                length=1;
                start=i;
            }
        }
    }
    ptr->next=(Block*)malloc(sizeof(Block));
    ptr->next->length=length;
    ptr->next->start=start;
    ptr->next->type=type;
    ptr->next->next=nullptr;
    return ;
}

void pop() {
    Block* ptr=root;
    int lasttype=-1;
    while (true) {
        if (ptr->next==nullptr) {
            break;
        }
        if (lasttype==ptr->next->type) {
            ptr=ptr->next;
            continue;
        }
        lasttype=ptr->next->type;
        printf("%d ",ptr->next->start);
        ptr->next->start++;
        ptr->next->length--;
        if (ptr->next->length==0) {
            ptr->next=ptr->next->next;
        } else {
            ptr=ptr->next;
        }
    }
    printf("\n");
    return ;
}

// void test() {
//     printf("test: ");
//     Block* ptr=root;
//     while (true) {
//         printf("%d ",ptr->next->start);
//         ptr=ptr->next;
//         if (ptr->next==nullptr) {
//             break;
//         }
//     }
//     printf("\n");
// }

int main() {
    init();
    while (root->next!=nullptr) {
        pop();
    }
    return 0;
}