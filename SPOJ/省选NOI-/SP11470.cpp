#include <bits/stdc++.h>
using namespace std;

#define int long long

#define endl '\n'
#define FRR(file) freopen(file,"r",stdin)
#define FRW(file) freopen(file,"w",stdout)
#define _rep(i,a,b) for (int i=(a);i<=(b);++i)
#define _reps(i,a,b,c) for (int i=(a);i<=(b);c)
#define _rrep(i,a,b) for (int i=(a);i>=(b);--i)
#define _rreps(i,a,b,c) for (int i=(a);i>=(b);c)
#define _iter(i,a) for (auto i=a.begin();i!=a.end();++i)
#define _graph(i,u) for (int i=h[u];~i;i=ne[i])
#define rint register int
#define LL long long

const int N=30000005;

int n,m,ts;
int arr[N];
int root[N];

struct SegmentTree {
    int l,r;
    int sum;
    int add;
    int left,right;
} tr[N];

int tot;

int cpy(int u) {
    tr[++tot]=tr[u];
    return tot;
}

void pushup(int u) {
    tr[u].sum=tr[tr[u].left].sum+tr[tr[u].right].sum;
}

void pushdown(int u) {
    auto &root=tr[u];
    if (tr[u].add) {
        auto &left=tr[tr[u].left=cpy(tr[u].left)];
        auto &right=tr[tr[u].right=cpy(tr[u].right)];
        left.add+=root.add;
        right.add+=root.add;
        left.sum+=(left.r-left.l+1)*root.add;
        right.sum+=(right.r-right.l+1)*root.add;
        root.add=0;
    }
}

void build(int u,int l,int r) {
    tr[u]={l,r,arr[l],0,0,0};
    if (l==r) return;
    int mid=l+r>>1;
    build(tr[u].left=++tot,l,mid);
    build(tr[u].right=++tot,mid+1,r);
    pushup(u);
}

void modify(int u,int l,int r,int k) {
    if (tr[u].l>=l && tr[u].r<=r) {
        tr[u].add+=k;
        tr[u].sum+=(tr[u].r-tr[u].l+1)*k;
    } else {
        pushdown(u);
        int mid=tr[u].l+tr[u].r>>1;
        if (l<=mid) modify(tr[u].left=cpy(tr[u].left),l,r,k);
        if (r>mid) modify(tr[u].right=cpy(tr[u].right),l,r,k);
        pushup(u);
    }
}

int query(int u,int l,int r) {
    if (!tr[u].l && !tr[u].r) assert(false);
    if (tr[u].l>=l && tr[u].r<=r) return tr[u].sum;
    pushdown(u);
    int mid=tr[u].l+tr[u].r>>1;
    int ans=0;
    if (l<=mid) ans+=query(tr[u].left,l,r);
    if (r>mid) ans+=query(tr[u].right,l,r);
    return ans;
}

signed main() {
    scanf("%lld %lld",&n,&m);
    _rep(i,1,n) scanf("%lld",&arr[i]);
    build(root[ts=0]=tot=1,1,n);
    while (m--) {
        assert(ts>=0);
        char op[2];
        scanf("%s",op);
        if (*op=='C') {
            int l,r,d;
            scanf("%lld %lld %lld",&l,&r,&d);
            ++ts;
            modify(root[ts]=cpy(root[ts-1]),l,r,d);
            // modify(ts==0?root[ts]:root[ts-1],root[ts],l,r,d);
            // root[ts+1]=cpy(root[ts]),++ts;
        } else if (*op=='Q') {
            int l,r;
            scanf("%lld %lld",&l,&r);
            printf("%lld\n",query(root[ts],l,r));
        } else if (*op=='H') {
            int l,r,t;
            scanf("%lld %lld %lld",&l,&r,&t); // t=max(t-1,0LL);
            printf("%lld\n",query(root[t],l,r));
        } else {
            int t;
            scanf("%lld",&t); // t--;
            ts=t;
        }
    }
    return 0;
}

/*
HACK:

In:
8 4
1 2 3 4 5 6 7 8
C 1 8 1
Q 1 8
C 3 4 1
Q 1 8

Ans:
44
46
*/