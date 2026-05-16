#include <bits/stdc++.h>
using namespace std;

struct Node {
    char l;
    char r;
} tree[129];

void preorder_traversal(char root) {
    printf("%c",root);
    if (tree[root].l!='*') {
        preorder_traversal(tree[root].l);
    }
    if (tree[root].r!='*') {
        preorder_traversal(tree[root].r);
    }
}

int main() {
    int n;
    scanf("%d",&n);
    n--;
    string in;
    char a,b,c;
    cin>>in;
    a=in[0];b=in[1];c=in[2];
    char root=a;
    tree[a]={b,c};
    for (int i=1;i<=n;++i) {
        cin>>in;
        a=in[0];b=in[1];c=in[2];
        tree[a]={b,c};
    }
    preorder_traversal(root);
    return 0;
}