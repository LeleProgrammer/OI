#include <bits/stdc++.h>

#define int long long
#define inf 2147483647

using namespace std;

const int N=100005;
const int Q=100005;

int n,q,m,op,x,y,k;
int a[N];

struct node {
    int l,r;
    int sum;
    int add,mul;
} tr[4*N];

void pushup(int u) {
    tr[u].sum=tr[u<<1].sum+tr[u<<1|1].sum;
    tr[u].sum%=m;
}

void pushdown_mul(int u) {
    auto &root=tr[u],&left=tr[u<<1],&right=tr[u<<1|1];
    if (root.mul!=1) {
        left.mul*=root.mul; right.mul*=root.mul;
        left.add*=root.mul; right.add*=root.mul;
        left.sum*=root.mul; right.sum*=root.mul;
        left.mul%=m; right.mul%=m;
        left.sum%=m; right.sum%=m;
        left.add%=m; right.add%=m;
        root.mul=1;
    }
}

void pushdown_add(int u) {
    auto &root=tr[u],&left=tr[u<<1],&right=tr[u<<1|1];
    if (root.add!=0) {
        left.add+=root.add; right.add+=root.add;
        left.sum+=(left.r-left.l+1)*root.add;
        right.sum+=(right.r-right.l+1)*root.add;
        left.add%=m; right.add%=m;
        left.sum%=m; right.sum%=m;
        root.add=0;
    }
}

void pushdown(int u) {
    pushdown_mul(u);
    pushdown_add(u);
}

void build(int u,int l,int r) {
    if (l==r) {
        tr[u].l=l;
        tr[u].r=r;
        tr[u].sum=a[l]%m;
        tr[u].add=0;
        tr[u].mul=1;
    } else {
        tr[u].l=l;
        tr[u].r=r;
        tr[u].sum=0;
        tr[u].add=0;
        tr[u].mul=1;
        int mid=l+r>>1;
        build(u<<1,l,mid);
        build(u<<1|1,mid+1,r);
        pushup(u);
    }
}

void modify_mul(int u,int l,int r,int k) {
    if (tr[u].l>=l && tr[u].r<=r) {
        tr[u].mul*=k;
        tr[u].sum*=k;
        tr[u].add*=k;
        tr[u].mul%=m;
        tr[u].sum%=m;
        tr[u].add%=m;
    } else {
        pushdown(u);
        int mid=tr[u].l+tr[u].r>>1;
        if (l<=mid) modify_mul(u<<1,l,r,k);
        if (r>mid) modify_mul(u<<1|1,l,r,k);
        pushup(u);
    }
}

void modify_add(int u,int l,int r,int k) {
    if (tr[u].l>=l && tr[u].r<=r) {
        tr[u].add+=k;
        tr[u].sum+=(tr[u].r-tr[u].l+1)*k;
        tr[u].add%=m;
        tr[u].sum%=m;
    } else {
        pushdown(u);
        int mid=tr[u].l+tr[u].r>>1;
        if (l<=mid) modify_add(u<<1,l,r,k);
        if (r>mid) modify_add(u<<1|1,l,r,k);
        pushup(u);
    }
}

int query(int u,int l,int r) {
    if (tr[u].l>=l && tr[u].r<=r) return tr[u].sum;
    pushdown(u);
    int mid=tr[u].l+tr[u].r>>1;
    int res=0;
    if (l<=mid) res+=query(u<<1,l,r);
    if (r>mid) res+=query(u<<1|1,l,r);
    return res;
}

signed main() {
    scanf("%lld %lld",&n,&m);
    for (int i=1;i<=n;++i) scanf("%lld",&a[i]);
    build(1,1,n);
    scanf("%lld",&q);
    while (q--) {
        scanf("%lld %lld %lld",&op,&x,&y);
        if (op==1) {
            scanf("%lld",&k);
            modify_mul(1,x,y,k);
        } else if (op==2) {
            scanf("%lld",&k);
            modify_add(1,x,y,k);
        } else {
            printf("%lld\n",query(1,x,y)%m);
        }
    }
    return 0;
}