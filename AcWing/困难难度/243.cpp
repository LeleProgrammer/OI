#include <bits/stdc++.h>

#define int long long

using namespace std;

int n,m;
int arr[100005];
char op[2];
int l,r,d;

struct node {
    int l;
    int r;
    int sum;
    int add; // lazy mark
} tr[400020];

void pushup(int u) {
    tr[u].sum=tr[u<<1].sum+tr[u<<1|1].sum;
}

void pushdown(int u) {
    tr[u<<1].add+=tr[u].add;
    tr[u<<1|1].add+=tr[u].add;
    tr[u<<1].sum+=(tr[u<<1].r-tr[u<<1].l+1)*tr[u].add;
    tr[u<<1|1].sum+=(tr[u<<1|1].r-tr[u<<1|1].l+1)*tr[u].add;
    tr[u].add=0;
}

void build(int u,int l,int r) {
    tr[u].l=l;
    tr[u].r=r;
    if (l==r) tr[u].sum=arr[l];
    else {
        int mid=l+r>>1;
        build(u<<1,l,mid);
        build(u<<1|1,mid+1,r);
        pushup(u);
    }
}

void modify(int u,int l,int r,int x) {
    if (tr[u].l>=l && tr[u].r<=r) {
        tr[u].add+=x;
        tr[u].sum+=(tr[u].r-tr[u].l+1)*x;
    } else {
        pushdown(u);
        int mid=tr[u].l+tr[u].r>>1;
        if (l<=mid) modify(u<<1,l,r,x);
        if (r>=mid+1) modify(u<<1|1,l,r,x);
        pushup(u);
    }
}

int query(int u,int l,int r) {
    if (tr[u].l>=l && tr[u].r<=r) return tr[u].sum;
    pushdown(u);
    int mid=tr[u].l+tr[u].r>>1;
    int res=0;
    if (l<=mid) res+=query(u<<1,l,r);
    if (r>=mid+1) res+=query(u<<1|1,l,r);
    return res;
}

signed main() {
    scanf("%lld %lld",&n,&m);
    for (int i=1;i<=n;++i) {
        scanf("%lld",&arr[i]);
    }
    build(1,1,n);
    while (m--) {
        scanf("%s %lld %lld",op,&l,&r);
        if (op[0]=='C') {
            scanf("%lld",&d);
            modify(1,l,r,d);
        } else {
            printf("%lld\n",query(1,l,r));
        }
    }
    return 0;
}