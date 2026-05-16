#include <bits/stdc++.h>

#define inf -1000000000

using namespace std;

const int N=400005;

int n,k;
int x[N];

struct SegmentTree {
    int l,r;
    int v;
    int tag;
} tr[N];

int get(int x) {
    if (x>0) return 1;
    else if (x==0) return 0;
    else return -1;
}

void pushup(int u) {
    tr[u].v=tr[u<<1].v*tr[u<<1|1].v;
}

void pushdown(int u) {
    auto &root=tr[u],&left=tr[u<<1],&right=tr[u<<1|1];
    if (root.tag!=inf) {
        left.tag=right.tag=root.tag;
        left.v=right.v=root.tag;
        root.tag=inf;
    }
}

void build(int u,int l,int r) {
    tr[u]={l,r,x[l],inf};
    if (l==r) return;
    int mid=l+r>>1;
    build(u<<1,l,mid);
    build(u<<1|1,mid+1,r);
    pushup(u);
}

void modify(int u,int l,int r,int k) {
    if (tr[u].l>=l && tr[u].r<=r) {
        tr[u].tag=k;
        tr[u].v=k;
    } else {
        pushdown(u);
        int mid=tr[u].l+tr[u].r>>1;
        if (l<=mid) modify(u<<1,l,r,k);
        if (r>mid) modify(u<<1|1,l,r,k);
        pushup(u);
    }
}

int query(int u,int l,int r) {
    if (tr[u].l>=l && tr[u].r<=r) {
        return tr[u].v;
    }
    pushdown(u);
    int mid=tr[u].l+tr[u].r>>1;
    int res=1;
    if (l<=mid) res*=query(u<<1,l,r);
    if (r>mid) res*=query(u<<1|1,l,r);
    return res;
}

int main() {
    while (~scanf("%d %d",&n,&k)) {
        for (int i=1;i<=n;++i) {
            int val;
            scanf("%d",&val);
            x[i]=get(val);
        }
        build(1,1,n);
        while (k--) {
            char op[2];
            scanf("%s",op);
            if (*op=='C') {
                int a,b;
                scanf("%d %d",&a,&b);
                modify(1,a,a,get(b));
            } else {
                int a,b;
                scanf("%d %d",&a,&b);
                int res=query(1,a,b);
                if (res==0) printf("0");
                else if (res>0) printf("+");
                else printf("-");
            }
        }
        putchar(10);
    }
    return 0;
}