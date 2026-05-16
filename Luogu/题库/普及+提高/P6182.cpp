#include <bits/stdc++.h>
using namespace std;

const int MAXN=80005;

int n;
char op[2];
int x;

struct node {
    int v;
    int next;
} root[MAXN*2];

int main() {
    scanf("%d",&n);
    root[0]={-1,0};
    for (int i=1;i<=n;++i) {
        scanf("%s",op);
        if (*op=='a') {
            scanf("%d",&x);
            root[i].v=x;
            root[i].next=i-1;
        } else if (*op=='s') {
            root[i]=root[root[i-1].next];
        } else {
            scanf("%d",&x);
            root[i]=root[x-1];
        }
        printf("%d\n",root[i].v);
    }
    return 0;
}