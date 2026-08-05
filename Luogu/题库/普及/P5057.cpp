#include <bits/stdc++.h>
using namespace std;

const int N=100005;
const int M=500005;

int n,m,t,l,r,i;

struct node {
    int l,r;
    int cnt;
    int rev;
} tr[N*4];

void pushup(int u) {
    tr[u].cnt=tr[u<<1].cnt+tr[u<<1|1].cnt;
}

void pushdown(int u) {
    auto &root=tr[u],&left=tr[u<<1],&right=tr[u<<1|1];
    if (root.rev) {
        left.rev^=1; right.rev^=1;
        left.cnt=(left.r-left.l+1)-left.cnt;
        right.cnt=(right.r-right.l+1)-right.cnt;
        root.rev=0;
    }
}

void build(int u,int l,int r) {
    tr[u]={l,r,0,0};
    if (l==r) return;
    int mid=l+r>>1;
    build(u<<1,l,mid); build(u<<1|1,mid+1,r);
}

void modify(int u,int l,int r) {
    if (tr[u].l>=l && tr[u].r<=r) {
        tr[u].rev^=1;
        tr[u].cnt=(tr[u].r-tr[u].l+1)-tr[u].cnt;
    } else {
        pushdown(u);
        int mid=tr[u].l+tr[u].r>>1;
        if (l<=mid) modify(u<<1,l,r);
        if (r>mid) modify(u<<1|1,l,r);
        pushup(u);
    }
}

int query(int u,int l,int r) {
    if (tr[u].l>=l && tr[u].r<=r) return tr[u].cnt;
    pushdown(u);
    int mid=tr[u].l+tr[u].r>>1;
    int res=0;
    if (l<=mid) res+=query(u<<1,l,r);
    if (r>mid) res+=query(u<<1|1,l,r);
    return res;
}

int main() {
    scanf("%d %d",&n,&m);
    build(1,1,n);
    while (m--) {
        scanf("%d",&t);
        if (t==1) {
            scanf("%d %d",&l,&r);
            modify(1,l,r);
        } else {
            scanf("%d",&i);
            printf("%d\n",query(1,i,i));
        }
    }
    return 0;
}