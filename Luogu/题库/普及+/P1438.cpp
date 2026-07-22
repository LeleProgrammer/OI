#include <bits/stdc++.h>

#define int long long

using namespace std;

const int MAXN=100005;

int n,m;
int arr[MAXN];
int cf[MAXN];
int opt,l,r,k,d,p;

struct node {
    int l;
    int r;
    int sum;
    int add;
} tr[MAXN*4];

void pushup(int u) {
    tr[u].sum=tr[u<<1].sum+tr[u<<1|1].sum;
}

void pushdown(int u) {
    auto &root=tr[u],&left=tr[u<<1],&right=tr[u<<1|1];
    left.add+=root.add;
    right.add+=root.add;
    left.sum+=(left.r-left.l+1)*root.add;
    right.sum+=(right.r-right.l+1)*root.add;
    root.add=0;
}

void build(int u,int l,int r) {
    if (l==r) tr[u]={l,r,cf[l],0};
    else {
        tr[u]={l,r,0,0};
        int mid=l+r>>1;
        build(u<<1,l,mid);
        build(u<<1|1,mid+1,r);
        pushup(u);
    }
}

void modify(int u,int l,int r,int v) {
    if (tr[u].l>=l && tr[u].r<=r) {
        tr[u].add+=v;
        tr[u].sum+=(tr[u].r-tr[u].l+1)*v;
    } else {
        pushdown(u);
        int mid=tr[u].l+tr[u].r>>1;
        if (l<=mid) modify(u<<1,l,r,v);
        if (r>=mid+1) modify(u<<1|1,l,r,v);
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
    // freopen("P1438_2.in","r",stdin);
    // freopen("P1438.myout","w",stdout);
    scanf("%lld %lld",&n,&m);
    for (int i=1;i<=n;++i) scanf("%lld",&arr[i]);
    for (int i=1;i<=n;++i) cf[i]=arr[i]-arr[i-1];
    build(1,1,n);
    while (m--) {
        scanf("%lld",&opt);
        if (opt==1) {
            scanf("%lld %lld %lld %lld",&l,&r,&k,&d);
            modify(1,l,l,k);
            if (l!=r) modify(1,l+1,r,d); // 等差数列长度为 1 时不加 if 会炸 #4
            if (r+1<=n) modify(1,r+1,r+1,-k-(r-l)*d); // 如果等差数列加到数组末尾，差分数组就不需要修改值了，不然溢出 #1 - #4 RE
        } else {
            scanf("%lld",&p);
            printf("%lld\n",query(1,1,p));
        }
    }
    return 0;
}