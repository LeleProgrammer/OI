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

const int N=500005;
const int inf=1e9;

int n,q;
int arr[N];

struct Seg {
    int l,r;
    int lmx1,rmx1,mmx1;
    int lmx0,rmx0,mmx0;
    int cnt1,cnt0;
    int rev;
    void init() {
        lmx1=rmx1=mmx1=lmx0=rmx0=mmx0=cnt1=cnt0=rev=0;
        l=inf,r=-inf;
    }
} tr[N<<2];

void pushup(Seg& u,Seg& l,Seg& r) {
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

void swap(Seg& u) {
    swap(u.lmx0,u.lmx1);
    swap(u.rmx0,u.rmx1);
    swap(u.mmx0,u.mmx1);
    swap(u.cnt0,u.cnt1);
}

void pushdown(int u) {
    auto &root=tr[u],&left=tr[u<<1],&right=tr[u<<1|1];
    if (root.rev) {
        left.rev^=1,right.rev^=1;
        swap(left),swap(right);
        root.rev=0;
    }
}

void build(int u,int l,int r) {
    tr[u].init();
    tr[u].l=l,tr[u].r=r;
    if (l==r) {
        if (!arr[l]) tr[u]={l,r,0,0,0,1,1,1,0,1,0};
        else tr[u]={l,r,1,1,1,0,0,0,1,0,0};
    } else {
        int mid=l+r>>1;
        build(u<<1,l,mid);
        build(u<<1|1,mid+1,r);
        pushup(u);
    }
}

void modify(int u,int l,int r) {
    if (tr[u].l>=l && tr[u].r<=r) {
        swap(tr[u]);
        tr[u].rev^=1;
    } else {
        pushdown(u);
        int mid=tr[u].l+tr[u].r>>1;
        if (l<=mid) modify(u<<1,l,r);
        if (r>mid) modify(u<<1|1,l,r);
        pushup(u);
    }
}

Seg query(int u,int l,int r) {
    if (tr[u].l>=l && tr[u].r<=r) return tr[u];
    Seg ans,left,right;
    ans.init();
    left.init();
    right.init();
    pushdown(u);
    int mid=tr[u].l+tr[u].r>>1;
    if (l<=mid) left=query(u<<1,l,r);
    if (r>mid) right=query(u<<1|1,l,r);
    pushup(ans,left,right);
    return ans;
}

int main() {
    scanf("%d %d",&n,&q);
    _rep(i,1,n) scanf("%1d",&arr[i]);
    build(1,1,n);
    while (q--) {
        int op,l,r;
        scanf("%d %d %d",&op,&l,&r);
        if (op==1) modify(1,l,r);
        else printf("%d\n",query(1,l,r).mmx1);
    }
    return 0;
}