#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N=100005;
const int M=25;

int n,m;
int arr[N];

struct SegmentTree {
    int l,r;
    int cnt[M];
    int tag;
} tr[N*4];

int get(int x,int k) {
    return (x>>k)&1;
}

void pushup(int u) {
    for (int i=0;i<M;++i) {
        tr[u].cnt[i]=tr[u<<1].cnt[i]+tr[u<<1|1].cnt[i];
    }
}

void pushdown(int u) {
    auto &root=tr[u],&left=tr[u<<1],&right=tr[u<<1|1];
    if (root.tag) {
        for (int i=0;i<M;++i) {
            if (get(root.tag,i)) {
                left.cnt[i]=left.r-left.l+1-left.cnt[i];
                right.cnt[i]=right.r-right.l+1-right.cnt[i];
            }
        }
        left.tag^=root.tag;
        right.tag^=root.tag;
        root.tag=0;
    }
}

void build(int u,int l,int r) {
    tr[u].l=l,tr[u].r=r,tr[u].tag=0;
    if (l==r) {
        for (int i=0;i<M;++i) {
            tr[u].cnt[i]=get(arr[l],i);
        }
    } else {
        int mid=l+r>>1;
        build(u<<1,l,mid);
        build(u<<1|1,mid+1,r);
        pushup(u);
    }
}

void modify(int u,int l,int r,int x) {
    if (tr[u].l>=l && tr[u].r<=r) {
        tr[u].tag^=x;
        for (int i=0;i<M;++i) {
            if (get(x,i)) {
                tr[u].cnt[i]=tr[u].r-tr[u].l+1-tr[u].cnt[i];
            }
        }
    } else {
        pushdown(u);
        int mid=tr[u].l+tr[u].r>>1;
        if (l<=mid) modify(u<<1,l,r,x);
        if (r>mid) modify(u<<1|1,l,r,x);
        pushup(u);
    }
}

SegmentTree query(int u,int l,int r) {
    if (tr[u].l>=l && tr[u].r<=r) return tr[u];
    pushdown(u);
    int mid=tr[u].l+tr[u].r>>1;
    SegmentTree ans;
    for (int i=0;i<M;++i) {
        ans.cnt[i]=0;
    }
    if (l<=mid) {
        SegmentTree t=query(u<<1,l,r);
        for (int i=0;i<M;++i) {
            ans.cnt[i]+=t.cnt[i];
        }
    }
    if (r>mid) {
        SegmentTree t=query(u<<1|1,l,r);
        for (int i=0;i<M;++i) {
            ans.cnt[i]+=t.cnt[i];
        }
    }
    return ans;
}

signed main() {
    scanf("%lld",&n);
    for (int i=1;i<=n;++i) {
        scanf("%lld",&arr[i]);
    }
    build(1,1,n);
    scanf("%lld",&m);
    while (m--) {
        int op;
        scanf("%lld",&op);
        if (op==1) {
            int l,r;
            scanf("%lld %lld",&l,&r);
            SegmentTree t=query(1,l,r);
            int ans=0;
            for (int i=0;i<M;++i) {
                ans+=(1<<i)*t.cnt[i];
            }
            printf("%lld\n",ans);
        } else {
            int l,r,x;
            scanf("%lld %lld %lld",&l,&r,&x);
            modify(1,l,r,x);
        }
    }
    return 0;
}