#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N=200005;
const int M=200005;

int n,m,a[N],b[M];

struct node {
    int l,r;
    int sum;
    int add; // lazy tag
} tr[N*4];

void pushup(int u) {
    tr[u].sum=tr[u<<1].sum+tr[u<<1|1].sum;
}

void build(int u,int l,int r) {
    if (l==r) tr[u]={l,r,a[l],0};
    else {
        tr[u]={l,r,0,0};
        int mid=l+r>>1;
        build(u<<1,l,mid);
        build(u<<1|1,mid+1,r);
        pushup(u);
    }
}

void pushdown(int u) {
    auto &root=tr[u],&left=tr[u<<1],&right=tr[u<<1|1];
    left.add+=root.add,right.add+=root.add;
    left.sum+=(left.r-left.l+1)*root.add;
    right.sum+=(right.r-right.l+1)*root.add;
    root.add=0;
}

void modify(int u,int l,int r,int k) {
    if (tr[u].l>=l && tr[u].r<=r) {
        tr[u].add+=k;
        tr[u].sum+=(tr[u].r-tr[u].l+1)*k;
    } else {
        pushdown(u);
        int mid=tr[u].l+tr[u].r>>1;
        if (l<=mid) modify(u<<1,l,r,k);
        if (r>mid) modify(u<<1|1,l,r,k);
        pushup(u);
    }
}

int query(int u,int l,int r) {
    if (tr[u].l>=l && tr[u].r<=r) return tr[u].sum;
    else {
        pushdown(u);
        int mid=tr[u].l+tr[u].r>>1;
        int res=0;
        if (l<=mid) res+=query(u<<1,l,r);
        if (r>mid) res+=query(u<<1|1,l,r);
        return res;
    }
}

signed main() {
    scanf("%lld %lld",&n,&m);
    for (int i=1;i<=n;++i) scanf("%lld",a+i);
    for (int i=1;i<=m;++i) scanf("%lld",b+i),b[i]++;
    build(1,1,n);
    for (int i=1;i<=m;++i) {
        int k=query(1,b[i],b[i]);
        modify(1,b[i],b[i],-k);
        int add=k/n;
        int rem=k%n;
        modify(1,1,n,add);
        if (!rem) continue;
        if (b[i]==n) modify(1,1,rem,1);
        else if (b[i]+rem>n) {
            modify(1,b[i]+1,n,1);
            modify(1,1,rem-(n-b[i]),1);
        } else {
            modify(1,b[i]+1,b[i]+rem,1);
        }
    }
    for (int i=1;i<=n;++i) {
        printf("%lld ",query(1,i,i));
    }
    return 0;
}