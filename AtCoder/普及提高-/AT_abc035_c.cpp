#include <bits/stdc++.h>
using namespace std;

const int N=200005;

int n,k;
int f[N];

struct SegmentTree {
    int l,r;
    int tag;
} tr[N*4];

void pushdown(int u) {
    auto &root=tr[u],&left=tr[u<<1],&right=tr[u<<1|1];
    if (root.tag) {
        left.tag+=root.tag;
        right.tag+=root.tag;
        root.tag=0;
    }
}

void build(int u,int l,int r) {
    tr[u]={l,r,0};
    if (l==r) return;
    int mid=l+r>>1;
    build(u<<1,l,mid);
    build(u<<1|1,mid+1,r);
}

void modify(int u,int l,int r) {
    if (tr[u].l>=l && tr[u].r<=r) {
        tr[u].tag++;
    } else {
        pushdown(u);
        int mid=tr[u].l+tr[u].r>>1;
        if (l<=mid) modify(u<<1,l,r);
        if (r>mid) modify(u<<1|1,l,r);
    }
}

void query(int u,int l,int r) {
    if (l==r) {
        f[l]=tr[u].tag%2;
    } else {
        pushdown(u);
        int mid=l+r>>1;
        query(u<<1,l,mid);
        query(u<<1|1,mid+1,r);
    }
}

int main() {
    scanf("%d %d",&n,&k);
    build(1,1,n);
    while (k--) {
        int a,b;
        scanf("%d %d",&a,&b);
        modify(1,a,b);
    }
    query(1,1,n);
    for (int i=1;i<=n;++i) printf("%d",f[i]);
    putchar(10);
    return 0;
}