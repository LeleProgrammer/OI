#include <bits/stdc++.h>
using namespace std;

const int N=50005;

int n,q;
int arr[N];

struct SegmentTree {
    int l,r;
    int sum;
    int lmax;
    int mmax;
    int rmax;
} tr[N*4];

void pushup(int u) {
    auto &root=tr[u],&left=tr[u<<1],&right=tr[u<<1|1];
    root.sum=left.sum+right.sum;
    root.mmax=max(max(left.mmax,right.mmax),left.rmax+right.lmax);
    root.lmax=max(left.lmax,left.sum+right.lmax);
    root.rmax=max(right.rmax,right.sum+left.rmax);
}

void build(int u,int l,int r) {
    tr[u]={l,r,arr[l],arr[l],arr[l],arr[l]};
    if (l==r) return;
    int mid=l+r>>1;
    build(u<<1,l,mid); build(u<<1|1,mid+1,r);
    pushup(u);
}

void modify(int u,int pos,int k) {
    if (tr[u].l==pos && tr[u].r==pos) {
        tr[u].sum=tr[u].lmax=tr[u].mmax=tr[u].rmax=k;
    } else {
        int mid=tr[u].l+tr[u].r>>1;
        if (pos<=mid) modify(u<<1,pos,k);
        else modify(u<<1|1,pos,k);
        pushup(u);
    }
}

SegmentTree query(int u,int l,int r) {
    if (tr[u].l>=l && tr[u].r<=r) return tr[u];
    int mid=tr[u].l+tr[u].r>>1;
    if (l<=mid && r>mid) {
        SegmentTree left=query(u<<1,l,r);
        SegmentTree right=query(u<<1|1,l,r);
        SegmentTree ans;
        ans.mmax=max(max(left.mmax,right.mmax),left.rmax+right.lmax);
        ans.lmax=max(left.lmax,left.sum+right.lmax);
        ans.rmax=max(right.rmax,right.sum+left.rmax);
        ans.sum=left.sum+right.sum;
        return ans;
    } else if (l<=mid) return query(u<<1,l,r);
    else return query(u<<1|1,l,r);
}

int main() {
    scanf("%d",&n);
    for (int i=1;i<=n;++i) scanf("%d",&arr[i]);
    build(1,1,n);
    scanf("%d",&q);
    while (q--) {
        int op,a,b;
        scanf("%d %d %d",&op,&a,&b);
        if (!op) modify(1,a,b);
        else printf("%d\n",query(1,a,b).mmax);
    }
    return 0;
}