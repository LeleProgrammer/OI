#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N=100005;

int n,m;
int arr[N];

struct SegmentTree {
    int l,r;
    int add;
    int sum,sum2;
} tr[N*4];

void pushup(int u) {
    tr[u].sum=tr[u<<1].sum+tr[u<<1|1].sum;
    tr[u].sum2=tr[u<<1].sum2+tr[u<<1|1].sum2;
}

void pushdown(int u) {
    auto &root=tr[u],&left=tr[u<<1],&right=tr[u<<1|1];
    if (root.add) {
        left.add+=root.add;
        right.add+=root.add;
        left.sum2+=left.sum*2*root.add+(left.r-left.l+1)*root.add*root.add;
        right.sum2+=right.sum*2*root.add+(right.r-right.l+1)*root.add*root.add;
        left.sum+=(left.r-left.l+1)*root.add;
        right.sum+=(right.r-right.l+1)*root.add;
        root.add=0;
    }
}

void build(int u,int l,int r) {
    tr[u]={l,r,0,arr[l],arr[l]*arr[l]};
    if (l==r) return;
    int mid=l+r>>1;
    build(u<<1,l,mid); build(u<<1|1,mid+1,r);
    pushup(u);
}

void modify(int u,int l,int r,int k) {
    if (tr[u].l>=l && tr[u].r<=r) {
        tr[u].sum2+=tr[u].sum*2*k+(tr[u].r-tr[u].l+1)*k*k;
        tr[u].sum+=(tr[u].r-tr[u].l+1)*k;
        tr[u].add+=k;
    } else {
        pushdown(u);
        int mid=tr[u].l+tr[u].r>>1;
        if (l<=mid) modify(u<<1,l,r,k);
        if (r>mid) modify(u<<1|1,l,r,k);
        pushup(u);
    }
}

SegmentTree query(int u,int l,int r) {
    if (tr[u].l>=l && tr[u].r<=r) return tr[u];
    pushdown(u);
    int mid=tr[u].l+tr[u].r>>1;
    SegmentTree ans;
    ans.sum=0;
    ans.sum2=0;
    if (l<=mid) {
        SegmentTree t=query(u<<1,l,r);
        ans.sum+=t.sum;
        ans.sum2+=t.sum2;
    }
    if (r>mid) {
        SegmentTree t=query(u<<1|1,l,r);
        ans.sum+=t.sum;
        ans.sum2+=t.sum2;
    }
    return ans;
}

int gcd(int a,int b) {
    if (!b) return a;
    return gcd(b,a%b);
}

signed main() {
    scanf("%lld %lld",&n,&m);
    for (int i=1;i<=n;++i) {
        scanf("%lld",&arr[i]);
    }
    build(1,1,n);
    while (m--) {
        int op,l,r;
        scanf("%lld %lld %lld",&op,&l,&r);
        if (op==1) {
            int d;
            scanf("%lld",&d);
            modify(1,l,r,d);
        } else if (op==2) {
            SegmentTree ans=query(1,l,r);
            if (ans.sum==0) {
                puts("0/1");
                continue;
            }
            int up=ans.sum;
            int down=r-l+1;
            int k=gcd(up,down);
            up/=k;
            down/=k;
            printf("%lld/%lld\n",up,down);
        } else {
            SegmentTree ans=query(1,l,r);
            int up=ans.sum2*(r-l+1)-ans.sum*ans.sum;
            int down=(r-l+1)*(r-l+1);
            if (up==0) {
                puts("0/1");
                continue;
            }
            int k=gcd(up,down);
            up/=k;
            down/=k;
            printf("%lld/%lld\n",up,down);
        }
    }
    return 0;
}