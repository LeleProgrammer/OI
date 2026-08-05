#include <bits/stdc++.h>
using namespace std;

int n,m;
int c,a,b;

struct node {
    int l;
    int r;
    int cnt;
    int swi;
} tr[400020];

void pushup(int u) {
    tr[u].cnt=tr[u<<1].cnt+tr[u<<1|1].cnt;
}

void pushdown(int u) {
    if (!tr[u].swi) return;
    auto &root=tr[u],&left=tr[u<<1],&right=tr[u<<1|1];
    left.swi=(left.swi+root.swi)%2;
    right.swi=(right.swi+root.swi)%2;
    left.cnt=left.r-left.l+1-left.cnt;
    right.cnt=right.r-right.l+1-right.cnt;
    root.swi=0;
}

void build(int u,int l,int r) {
    tr[u]={l,r,0,0};
    if (l==r) return;
    int mid=l+r>>1;
    build(u<<1,l,mid);
    build(u<<1|1,mid+1,r);
}

void modify(int u,int l,int r) {
    if (tr[u].l>=l && tr[u].r<=r) {
        tr[u].swi++; tr[u].swi%=2;
        tr[u].cnt=tr[u].r-tr[u].l+1-tr[u].cnt;
    } else {
        pushdown(u);
        int mid=tr[u].l+tr[u].r>>1;
        if (l<=mid) modify(u<<1,l,r);
        if (r>=mid+1) modify(u<<1|1,l,r);
        pushup(u);
    }
}

int query(int u,int l,int r) {
    if (tr[u].l>=l && tr[u].r<=r) return tr[u].cnt;
    pushdown(u);
    int mid=tr[u].l+tr[u].r>>1;
    int res=0;
    if (l<=mid) res+=query(u<<1,l,r);
    if (r>=mid+1) res+=query(u<<1|1,l,r);
    return res;
}

int main() {
    scanf("%d %d",&n,&m);
    build(1,1,n);
    while (m--) {
        scanf("%d %d %d",&c,&a,&b);
        if (!c) {
            modify(1,a,b);
        } else {
            printf("%d\n",query(1,a,b));
        }
    }
    return 0;
}