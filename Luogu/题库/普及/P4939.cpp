#include <bits/stdc++.h>
using namespace std;

int n,m;
int op,a,b;

int tr[10000005];

int lowbit(int x) {
    return x & -x;
}

void modify(int x,int k) {
    for (int i=x;i<=n;i+=lowbit(i)) tr[i]+=k;
}

int query(int x) {
    int res=0;
    for (int i=x;i>=1;i-=lowbit(i)) res+=tr[i];
    return res;
}

int main() {
    scanf("%d %d",&n,&m);
    while (m--) {
        scanf("%d %d",&op,&a);
        if (op) {
            printf("%d\n",query(a));
        } else {
            scanf("%d",&b);
            modify(a,1); modify(b+1,-1);
        }
    }
    return 0;
}