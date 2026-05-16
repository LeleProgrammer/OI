#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define FRR(file) freopen(file,"r",stdin)
#define FRW(file) freopen(file,"w",stdout)
#define TIMESTAMP cerr<<fixed<<setprecision(3)<<clock()*1.0/CLOCKS_PER_SEC<<"s"<<endl;
#define _rep(i,a,b) for (int i=(a);i<=(b);++i)
#define _reps(i,a,b,c) for (int i=(a);i<=(b);c)
#define _rrep(i,a,b) for (int i=(a);i>=(b);--i)
#define _rreps(i,a,b,c) for (int i=(a);i>=(b);c)
#define _iter(i,a) for (auto i=a.begin();i!=a.end();++i)
#define _graph(i,u) for (int i=h[u];~i;i=ne[i])
#define rint register int
#define LL long long
typedef pair<int,int> pii;

const int N=200005;

int n,m;

struct Seg {
    int l,r;
    int sum;
    int lmx,rmx,mmx;
    int set; // -1,0,1
    void init() {
        l=r=sum=lmx=rmx=mmx=0;
        set=-1;
    }
} tr[N<<2];

void pushup(Seg& u,Seg& l,Seg& r) {
    // if (l.sum==l.r-l.l+1 && r.sum==r.r-r.l+1) {
    //     u.lmx=u.mmx=u.rmx=u.r-u.l+1;
    // } else if (l.sum==l.r-l.l+1) {
    //     u.lmx=l.sum+r.lmx,u.rmx=r.rmx,u.mmx=max(u.lmx,r.mmx);
    // } else if (r.sum==r.l-r.l+1) {
    //     u.rmx=r.sum+l.rmx,u.lmx=l.lmx,u.mmx=max(u.rmx,l.mmx);
    // } else {
    //     u.lmx=l.lmx,u.rmx=r.rmx,u.mmx=max(max(l.mmx,r.mmx),l.rmx+r.lmx);
    // }
    u.sum=l.sum+r.sum;
    if (l.sum==l.r-l.l+1) u.lmx=l.sum+r.lmx;
    else u.lmx=l.lmx;
    if (r.sum==r.r-r.l+1) u.rmx=r.sum+l.rmx;
    else u.rmx=r.rmx;
    u.mmx=max(max(l.mmx,r.mmx),l.rmx+r.lmx);
    u.mmx=max(u.mmx,max(u.lmx,u.rmx));
}

void pushup(int u) {
    pushup(tr[u],tr[u<<1],tr[u<<1|1]);
}

void pushdown(int u) {
    auto &root=tr[u],&left=tr[u<<1],&right=tr[u<<1|1];
    if (~root.set) {
        left.set=right.set=root.set;
        left.sum=left.lmx=left.rmx=left.mmx=(left.r-left.l+1)*root.set;
        right.sum=right.lmx=right.rmx=right.mmx=(right.r-right.l+1)*root.set;
        root.set=-1;
    }
}

void build(int u,int l,int r) {
    tr[u]={l,r,0,0,0,0,-1};
    if (l==r) return;
    int mid=l+r>>1;
    build(u<<1,l,mid); build(u<<1|1,mid+1,r);
    pushup(u);
}

void modify(int u,int l,int r,int k) {
    if (tr[u].l>=l && tr[u].r<=r) {
        tr[u].lmx=tr[u].rmx=tr[u].mmx=tr[u].sum=(tr[u].r-tr[u].l+1)*k;
        tr[u].set=k;
    } else {
        pushdown(u);
        int mid=tr[u].l+tr[u].r>>1;
        if (l<=mid) modify(u<<1,l,r,k);
        if (r>mid) modify(u<<1|1,l,r,k);
        pushup(u);
    }
}

Seg query(int u,int l,int r) {
    if (tr[u].l>=l && tr[u].r<=r) return tr[u];
    pushdown(u);
    int mid=tr[u].l+tr[u].r>>1;
    Seg L,R,ans;
    L.init(),R.init(),ans.init();
    if (l<=mid) L=query(u<<1,l,r);
    if (r>mid) R=query(u<<1|1,l,r);
    L.l=tr[u].l,L.r=mid,R.l=mid+1,R.r=tr[u].r;
    pushup(ans,L,R);
    return ans;
}

void test() {
    printf("test: ");
    _rep(i,1,n) printf("%d ",query(1,i,i).sum);
    putchar(10);
}

int fix(int u,int l,int r,int k) {
    if (!k) return 0;
    // cout<<"fix "<<tr[u].l<<" "<<tr[u].r<<" "<<k<<endl;
    if (tr[u].l>=l && tr[u].r<=r && tr[u].sum<=k) {
        int t=tr[u].sum;
        if (t) modify(1,tr[u].l,tr[u].r,0);
        // cout<<"fixed "<<t<<endl;
        return t;
    }
    // assert(tr[u].l!=tr[u].r);
    pushdown(u);
    int mid=tr[u].l+tr[u].r>>1;
    int dec=0;
    if (l<=mid) {
        int t=fix(u<<1,l,r,k);
        dec+=t,k-=t;
    }
    if (r>mid && k) {
        int t=fix(u<<1|1,l,r,k);
        dec+=t,k-=t;
    }
    pushup(u);
    return dec;
}

int main() {
    scanf("%d %d",&n,&m);
    build(1,1,n);
    while (m--) {
        int op;
        scanf("%d",&op);
        if (op==0) {
            int l,r;
            scanf("%d %d",&l,&r);
            modify(1,l,r,1);
        } else if (op==1) {
            int l0,r0,l1,r1;
            scanf("%d %d %d %d",&l0,&r0,&l1,&r1);
            int t=r0-l0+1-query(1,l0,r0).sum;
            modify(1,l0,r0,1);
            fix(1,l1,r1,t);
        } else if (op==2) {
            int l,r;
            scanf("%d %d",&l,&r);
            auto t=query(1,l,r);
            printf("%d\n",t.mmx);
        }
        // test();
    }
    return 0;
}