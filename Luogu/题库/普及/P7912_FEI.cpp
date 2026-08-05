#include <bits/stdc++.h>
using namespace std;

struct block {
    int start_number;
    int length;
    int type;
    bool exist;
    int next;
} blocks[100005];

int root=0;
int n;

void init() {
    for (int i=0;i<100005;++i) {
        blocks[i].exist=false;
    }
    scanf("%d",&n);
    int type=-1;
    int length=0;
    int start;
    int read;
    int block_num=0;
    for (int i=1;i<=n;++i) {
        if (type==-1) {
            scanf("%d",&read);
            // restore
            type=read;
            ++length;
            start=i;
            continue;
        } else {
            scanf("%d",&read);
            if (read==type) {
                ++length;
            } else {
                // record
                blocks[block_num].exist=true;
                blocks[block_num].length=length;
                blocks[block_num].start_number=start;
                blocks[block_num].type=type;
                ++block_num;
                // restore
                length=1;
                type=read;
                start=i;
            }
        }
    }
    // 最后肯定多出来一个
    // record
    blocks[block_num].exist=true;
    blocks[block_num].length=length;
    blocks[block_num].start_number=start;
    blocks[block_num].type=type;
    ++block_num;
}

void pop() {
    int i=root;
    int last=-1;
    while (true) {
        if (blocks[i].exist==false) {
            break;
        }
        // put out the left one
        printf("%d ",blocks[i].start_number);
        // delete this fruits
        // start_number plus one
        blocks[i].start_number++;
        // length minus one
        blocks[i].length--;
        if (blocks[i].length==0) { // the whole block deleted
            if (last>=0) {
                blocks[last].next=blocks[i].next;
                if (blocks[last].type==blocks[blocks[i].next].type) {
                    blocks[last].length+=blocks[blocks[i].next].length;
                    blocks[last].next=blocks[blocks[i].next].next;
                }
            } else {
                root=blocks[i].next;
            }
        }
        i=blocks[i].next;
    }
    printf("\n");
    return ;
}

int main() {
    init();
    while (blocks[root].exist) {
        pop();
    }
    return 0;
}