#include <bits/stdc++.h>
using namespace std;

const int N=60005;

int n,s,m;

struct SegmentTree {
    int l,r;
    int add;
    int max;
} tr[N*4];

void pushup(int u) {
    tr[u].max=max(tr[u<<1].max,tr[u<<1|1].max);
}

void pushdown(int u) {
    auto &root=tr[u],&left=tr[u<<1],&right=tr[u<<1|1];
    if (root.add) {
        left.add+=root.add;
        right.add+=root.add;
        left.max+=root.add;
        right.max+=root.add;
        root.add=0;
    }
}

void build(int u,int l,int r) {
    tr[u]={l,r,0,0};
    if (l==r) return;
    int mid=l+r>>1;
    build(u<<1,l,mid);
    build(u<<1|1,mid+1,r);
    pushup(u);
}

void modify(int u,int l,int r,int k) {
    if (tr[u].l>=l && tr[u].r<=r) {
        tr[u].add+=k;
        tr[u].max+=k;
    } else {
        pushdown(u);
        int mid=tr[u].l+tr[u].r>>1;
        if (l<=mid) modify(u<<1,l,r,k);
        if (r>mid) modify(u<<1|1,l,r,k);
        pushup(u);
    }
}

int query(int u,int l,int r) {
    if (tr[u].l>=l && tr[u].r<=r) return tr[u].max;
    pushdown(u);
    int mid=tr[u].l+tr[u].r>>1;
    int ans=0;
    if (l<=mid) ans=max(ans,query(u<<1,l,r));
    if (r>mid) ans=max(ans,query(u<<1|1,l,r));
    return ans;
}

int main() {
    scanf("%d %d %d",&n,&s,&m);
    build(1,1,n);
    while (m--) {
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        int t=query(1,a,b-1);
        if (t+c>s) {
            puts("N");
            continue;
        }
        modify(1,a,b-1,c);
        puts("T");
        continue;
    }
    return 0;
}