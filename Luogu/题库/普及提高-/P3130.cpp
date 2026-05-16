#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N=200005;

int n,q;
char op[2];
int a,b,c;
int arr[N];

struct node {
    int l,r;
    int minn,sum;
    int add;
} tr[N*4];

void pushup(int u) {
    tr[u].minn=min(tr[u<<1].minn,tr[u<<1|1].minn);
    tr[u].sum=tr[u<<1].sum+tr[u<<1|1].sum;
}

void pushdown(int u) {
    auto &root=tr[u],&left=tr[u<<1],&right=tr[u<<1|1];
    if (root.add) {
        left.add+=root.add;
        right.add+=root.add;
        left.minn+=root.add;
        right.minn+=root.add;
        left.sum+=root.add*(left.r-left.l+1);
        right.sum+=root.add*(right.r-right.l+1);
        root.add=0;
    }
}

void build(int u,int l,int r) {
    if (l==r) {
        tr[u]={l,r,arr[l],arr[l],0};
    } else {
        tr[u]={l,r,0,0,0};
        int mid=l+r>>1;
        build(u<<1,l,mid);
        build(u<<1|1,mid+1,r);
        pushup(u);
    }
}

void modify(int u,int l,int r,int k) {
    if (tr[u].l>=l && tr[u].r<=r) {
        tr[u].add+=k;
        tr[u].minn+=k;
        tr[u].sum+=k*(tr[u].r-tr[u].l+1);
    } else {
        pushdown(u);
        int mid=tr[u].l+tr[u].r>>1;
        if (l<=mid) modify(u<<1,l,r,k);
        if (r>mid) modify(u<<1|1,l,r,k);
        pushup(u);
    }
}

int get_minn(int u,int l,int r) {
    if (tr[u].l>=l && tr[u].r<=r) return tr[u].minn;
    pushdown(u);
    int mid=tr[u].l+tr[u].r>>1;
    int res=0x7fffffff;
    if (l<=mid) res=get_minn(u<<1,l,r);
    if (r>mid) res=min(res,get_minn(u<<1|1,l,r));
    return res;
}

int get_sum(int u,int l,int r) {
    if (tr[u].l>=l && tr[u].r<=r) return tr[u].sum;
    pushdown(u);
    int mid=tr[u].l+tr[u].r>>1;
    int res=0;
    if (l<=mid) res+=get_sum(u<<1,l,r);
    if (r>mid) res+=get_sum(u<<1|1,l,r);
    return res;
}

signed main() {
    scanf("%lld %lld",&n,&q);
    for (int i=1;i<=n;++i) scanf("%lld",&arr[i]);
    build(1,1,n);
    while (q--) {
        scanf("%s %lld %lld",op,&a,&b);
        if (op[0]=='P') {
            scanf("%lld",&c);
            modify(1,a,b,c);
        } else if (op[0]=='S') {
            printf("%lld\n",get_sum(1,a,b));
        } else {
            printf("%lld\n",get_minn(1,a,b));
        }
    }
    return 0;
}