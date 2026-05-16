#include <bits/stdc++.h>
using namespace std;

int n;
int l[1000005];
int r[1000005];

void preorder(int pos) {
    if (!pos) return;
    printf("%d ",pos);
    preorder(l[pos]);
    preorder(r[pos]);
}

void inorder(int pos) {
    if (!pos) return;
    inorder(l[pos]);
    printf("%d ",pos);
    inorder(r[pos]);
}

void postorder(int pos) {
    if (!pos) return;
    postorder(l[pos]);
    postorder(r[pos]);
    printf("%d ",pos);
}

int main() {
    scanf("%d",&n);
    for (int i=1;i<=n;++i) {
        scanf("%d %d",l+i,r+i);
    }
    preorder(1); printf("\n");
    inorder(1); printf("\n");
    postorder(1); printf("\n");
    return 0;
}