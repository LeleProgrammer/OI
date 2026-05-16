#include <bits/stdc++.h>
using namespace std;

int n,val;
int root=1;
int cnt=1;

struct node {
    int val;
    int l,r;
} tree[300005]; // 从1开始，0表示空

void add_node(int root,int val) {
    if (val<=tree[root].val) {
        if (tree[root].l==0) {
            ++cnt;
            tree[cnt].val=val;
            tree[root].l=cnt;
            return;
        } else {
            add_node(tree[root].l,val);
        }
    } else {
        if (tree[root].r==0) {
            ++cnt;
            tree[cnt].val=val;
            tree[root].r=cnt;
            return;
        } else {
            add_node(tree[root].r,val);
        }
    }
}

vector<int> result;
int max_depth=0;

void traversal(int root,int depth) {
    if (!root) return;
    traversal(tree[root].l,depth+1);
    traversal(tree[root].r,depth+1);
    result.push_back(tree[root].val);
    max_depth=max(max_depth,depth);
}

int main() {
    scanf("%d",&n);
    scanf("%d",&val);
    tree[root].val=val;
    for (int i=1;i<=n;++i) {
        tree[i].l=tree[i].r=0;
    }
    for (int i=2;i<=n;++i) {
        scanf("%d",&val);
        add_node(root,val);
    }
    traversal(root,1);
    printf("deep=%d\n",max_depth);
    for (int i=0;i<result.size();++i) {
        printf("%d\n",result[i]);
    }
    return 0;
}