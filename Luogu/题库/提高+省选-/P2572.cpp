#include <bits/stdc++.h>
using namespace std;

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

const int N=100005;
const int inf=1e9;

int n,m;
int arr[N];

struct SegmentTree {
    int l,r;
    int lmx1,rmx1,mmx1;
    int lmx0,rmx0,mmx0;
    int cnt1,cnt0;
    int tag,rev;
    void init() {
        lmx1=rmx1=mmx1=lmx0=rmx0=mmx0=cnt1=cnt0=0;
        l=inf,r=-inf;
    }
} tr[N<<2];

void pushup(SegmentTree& u,SegmentTree& l,SegmentTree& r) {
    u.lmx1=max(l.lmx1,(l.cnt1==l.r-l.l+1)?(l.cnt1+r.lmx1):0);
    u.rmx1=max(r.rmx1,(r.cnt1==r.r-r.l+1)?(r.cnt1+l.rmx1):0);
    u.mmx1=max(max(l.mmx1,r.mmx1),l.rmx1+r.lmx1);
    u.lmx0=max(l.lmx0,(l.cnt0==l.r-l.l+1)?(l.cnt0+r.lmx0):0);
    u.rmx0=max(r.rmx0,(r.cnt0==r.r-r.l+1)?(r.cnt0+l.rmx0):0);
    u.mmx0=max(max(l.mmx0,r.mmx0),l.rmx0+r.lmx0);
    u.cnt1=l.cnt1+r.cnt1;
    u.cnt0=l.cnt0+r.cnt0;
}

void pushup(int u) {
    pushup(tr[u],tr[u<<1],tr[u<<1|1]);
}

void swap(SegmentTree& u) {
    swap(u.lmx0,u.lmx1);
    swap(u.rmx0,u.rmx1);
    swap(u.mmx0,u.mmx1);
    swap(u.cnt0,u.cnt1);
}

void pushdown(int u) {
    auto &root=tr[u],&left=tr[u<<1],&right=tr[u<<1|1];
    if (root.l==root.r) {
        root.tag=-1;
        root.rev=0;
        return;
    }
    if (~root.tag) {
        if (root.tag) {
            int len;
            len=left.r-left.l+1;
            left={left.l,left.r,len,len,len,0,0,0,len,0,1,0};
            len=right.r-right.l+1;
            right={right.l,right.r,len,len,len,0,0,0,len,0,1,0};
        } else {
            int len;
            len=left.r-left.l+1;
            left={left.l,left.r,0,0,0,len,len,len,0,len,1,0};
            len=right.r-right.l+1;
            right={right.l,right.r,0,0,0,len,len,len,0,len,1,0};
        }
        left.tag=right.tag=root.tag;
        root.tag=-1;
    }
    if (root.rev) {
        swap(left);
        swap(right);
        left.rev^=1;
        right.rev^=1;
        root.rev=0;
    }
}

void build(int u,int l,int r) {
    if (l==r) {
        if (arr[l]) tr[u]={l,r,1,1,1,0,0,0,1,0,-1,0};
        else tr[u]={l,r,0,0,0,1,1,1,0,1,-1,0};
    } else {
        tr[u]={l,r,0,0,0,0,0,0,0,0,-1,0};
        int mid=l+r>>1;
        build(u<<1,l,mid); build(u<<1|1,mid+1,r);
        pushup(u);
    }
}

void modify_set(int u,int l,int r,int k) {
    pushdown(u);
    if (tr[u].l>=l && tr[u].r<=r) {
        int len=tr[u].r-tr[u].l+1;
        if (k) tr[u]={tr[u].l,tr[u].r,len,len,len,0,0,0,len,0,1,0};
        else tr[u]={tr[u].l,tr[u].r,0,0,0,len,len,len,0,len,0,0};
    } else {
        int mid=tr[u].l+tr[u].r>>1;
        if (l<=mid) modify_set(u<<1,l,r,k);
        if (r>mid) modify_set(u<<1|1,l,r,k);
        pushup(u);
    }
}

void modify_rev(int u,int l,int r) {
    pushdown(u);
    if (tr[u].l>=l && tr[u].r<=r) {
        swap(tr[u]);
        tr[u].rev^=1;
    } else {
        int mid=tr[u].l+tr[u].r>>1;
        if (l<=mid) modify_rev(u<<1,l,r);
        if (r>mid) modify_rev(u<<1|1,l,r);
        pushup(u);
    }
}

int query_cnt1(int u,int l,int r) {
    pushdown(u);
    if (tr[u].l>=l && tr[u].r<=r) return tr[u].cnt1;
    int mid=tr[u].l+tr[u].r>>1;
    int ans=0;
    if (l<=mid) ans+=query_cnt1(u<<1,l,r);
    if (r>mid) ans+=query_cnt1(u<<1|1,l,r);
    return ans;
}

SegmentTree query_conn1(int u,int l,int r) {
    pushdown(u);
    if (tr[u].l>=l && tr[u].r<=r) return tr[u];
    SegmentTree ans,left,right;
    left.init();
    right.init();
    int mid=tr[u].l+tr[u].r>>1;
    if (l<=mid) left=query_conn1(u<<1,l,r);
    if (r>mid) right=query_conn1(u<<1|1,l,r);
    pushup(ans,left,right);
    return ans;
}

int main() {
    scanf("%d %d",&n,&m);
    _rep(i,1,n) scanf("%d",&arr[i]);
    build(1,1,n);
    while (m--) {
        int op,l,r;
        scanf("%d %d %d",&op,&l,&r); l++,r++;
        if (op==0) modify_set(1,l,r,0);
        else if (op==1) modify_set(1,l,r,1);
        else if (op==2) modify_rev(1,l,r);
        else if (op==3) printf("%d\n",query_cnt1(1,l,r));
        else printf("%d\n",query_conn1(1,l,r).mmx1);
    }
    return 0;
}