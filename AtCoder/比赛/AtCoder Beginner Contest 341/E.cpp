#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N=1000005;

int n,q;
string s;
int a[N],pre[N];

struct node {
    int l,r;
    int sum;
    int add;
} tr[N*4];

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
    if (l==r) tr[u]={l,r,a[l],0};
    else {
        tr[u]={l,r,0,0};
        int mid=l+r>>1;
        build(u<<1,l,mid);
        build(u<<1|1,mid+1,r);
        pushup(u);
    }
}

void modify(int u,int l,int r,int k) {
    if (tr[u].l>=l && tr[u].r<=r) {
        tr[u].sum+=(tr[u].r-tr[u].l+1)*k;
        tr[u].add=k;
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
    pushdown(u);
    int mid=tr[u].l+tr[u].r>>1;
    int res=0;
    if (l<=mid) res+=query(u<<1,l,r);
    if (r>mid) res+=query(u<<1|1,l,r);
    return res;
}

signed main() {
    scanf("%lld %lld",&n,&q);
    cin>>s;
    for (int i=0;i<n-1;++i) {
        if (s[i]!=s[i+1]) a[i+1]=1;
        else a[i+1]=0;
    }
    build(1,1,n);
    while (q--) {
        int op,b,c;
        scanf("%lld %lld %lld",&op,&b,&c);
        if (op==1) {
            if (b-1) modify(1,b-1,b-1,a[b-1]?-1:1),a[b-1]^=1;
            modify(1,c,c,a[c]?-1:1),a[c]^=1;
        } else {
            if (b==c) {puts("Yes"); continue;}
            if (query(1,b,c-1)==c-1-b+1) puts("Yes");
            else puts("No");
        }
    }
    return 0;
}