#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N=500005;
const int inf=1e18;

int n,m;
int arr[N];

struct SegmentTree {
    int l,r;
    int sum;
    int max;
    int cnt;
    int his_max;
    int submax;
    int add;
    int tag;
} tr[N*4];

void pushup(int u) {
    auto &root=tr[u],&left=tr[u<<1],&right=tr[u<<1|1];
    root.sum=left.sum+right.sum;
    root.max=max(left.max,right.max);
    root.his_max=max(left.his_max,right.his_max);
    if (left.max==right.max) {
        root.submax=max(left.submax,right.submax);
        root.cnt=left.cnt+right.cnt;
    } else if (left.max>right.max) {
        root.submax=max(left.submax,right.max);
        root.cnt=left.cnt;
    } else {
        root.submax=max(left.max,right.submax);
        root.cnt=right.cnt;
    }
}

void pushtag(int u,int tag) {
    if (tr[u].max<=tag) return;
    tr[u].sum-=tr[u].cnt*(tr[u].max-tag);
    tr[u].max=tag;
    tr[u].tag=tag;
}

void pushadd(int u) {
    auto &root=tr[u],&left=tr[u<<1],&right=tr[u<<1|1];
    if (root.add) {
        left.add+=root.add;
        right.add+=root.add;
        left.sum+=(left.r-left.l+1)*root.add;
        right.sum+=(right.r-right.l+1)*root.add;
        left.max+=root.add;
        right.max+=root.add;
        if (left.submax!=-inf) left.submax+=root.add;
        if (right.submax!=-inf) right.submax+=root.add;
        left.his_max=max(left.his_max,left.max);
        right.his_max=max(right.his_max,right.max);
        root.add=0;
    }
}

void pushmin(int u) {
    if (tr[u].tag==inf) return;
    pushtag(u<<1,tr[u].tag);
    pushtag(u<<1|1,tr[u].tag);
    tr[u].tag=inf;
}

void pushdown(int u) {
    pushmin(u);
    pushadd(u);
}

void build(int u,int l,int r) {
    tr[u]={l,r,arr[l],arr[l],1,arr[l],-inf,0,inf};
    if (l==r) return;
    int mid=l+r>>1;
    build(u<<1,l,mid);
    build(u<<1|1,mid+1,r);
    pushup(u);
}

void modify_add(int u,int l,int r,int k) {
    if (tr[u].l>=l && tr[u].r<=r) {
        if (tr[u].l!=tr[u].r) pushdown(u);
        tr[u].add+=k;
        tr[u].sum+=(tr[u].r-tr[u].l+1)*k;
        tr[u].max+=k;
        tr[u].his_max=max(tr[u].his_max,tr[u].max);
        if (tr[u].submax!=-inf) tr[u].submax+=k;
    } else {
        pushdown(u);
        int mid=tr[u].l+tr[u].r>>1;
        if (l<=mid) modify_add(u<<1,l,r,k);
        if (r>mid) modify_add(u<<1|1,l,r,k);
        pushup(u);
    }
}

void modify_min(int u,int l,int r,int k) {
    if (tr[u].max<=k) return;
    if (tr[u].l>=l && tr[u].r<=r && k>tr[u].submax) {
        if (tr[u].l!=tr[u].r) pushdown(u);
        pushtag(u,k);
    } else {
        pushdown(u);
        int mid=tr[u].l+tr[u].r>>1;
        if (l<=mid) modify_min(u<<1,l,r,k);
        if (r>mid) modify_min(u<<1|1,l,r,k);
        pushup(u);
    }
}

int query_max(int u,int l,int r) {
    if (tr[u].l>=l && tr[u].r<=r) return tr[u].max;
    pushdown(u);
    int mid=tr[u].l+tr[u].r>>1;
    int ans=-inf;
    if (l<=mid) ans=max(ans,query_max(u<<1,l,r));
    if (r>mid) ans=max(ans,query_max(u<<1|1,l,r));
    return ans;
}

int query_sum(int u,int l,int r) {
    if (tr[u].l>=l && tr[u].r<=r) return tr[u].sum;
    pushdown(u);
    int mid=tr[u].l+tr[u].r>>1;
    int ans=0;
    if (l<=mid) ans+=query_sum(u<<1,l,r);
    if (r>mid) ans+=query_sum(u<<1|1,l,r);
    return ans;
}

int query_his_max(int u,int l,int r) {
    if (tr[u].l>=l && tr[u].r<=r) return tr[u].his_max;
    pushdown(u);
    int mid=tr[u].l+tr[u].r>>1;
    int ans=-inf;
    if (l<=mid) ans=max(ans,query_his_max(u<<1,l,r));
    if (r>mid) ans=max(ans,query_his_max(u<<1|1,l,r));
    return ans;
}

signed main() {
    // freopen("P6242_2.in","r",stdin);
    // freopen("P6242_2","w",stdout);
    scanf("%lld %lld",&n,&m);
    for (int i=1;i<=n;++i) {
        scanf("%lld",&arr[i]);
    }
    build(1,1,n);
    while (m--) {
        int op,l,r;
        scanf("%lld %lld %lld",&op,&l,&r);
        if (op==1) {
            int k;
            scanf("%lld",&k);
            modify_add(1,l,r,k);
        } else if (op==2) {
            int v;
            scanf("%lld",&v);
            modify_min(1,l,r,v);
        } else if (op==3) {
            printf("%lld\n",query_sum(1,l,r));
        } else if (op==4) {
            printf("%lld\n",query_max(1,l,r));
        } else {
            printf("%lld\n",query_his_max(1,l,r));
        }
    }
    return 0;
}