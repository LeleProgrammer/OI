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
const int inf=2e9;

int h,w,n;
int ans[N];

struct node {
    int r,c,l,i;
    friend bool operator < (const node& a,const node& b) {
        return a.r>b.r;
    }
} arr[N];

struct Seg {
    int l,r;
    int mn,set;
} tr[N<<2];

void pushup(int u) {
    tr[u].mn=min(tr[u<<1].mn,tr[u<<1|1].mn);
}

void pushdown(int u) {
    auto &root=tr[u],&left=tr[u<<1],&right=tr[u<<1|1];
    if (root.set) {
        left.set=root.set;
        right.set=root.set;
        left.mn=root.set;
        right.mn=root.set;
        root.set=0;
    }
}

void build(int u,int l,int r) {
    tr[u]={l,r,h,0};
    if (l==r) return;
    int mid=l+r>>1;
    build(u<<1,l,mid); build(u<<1|1,mid+1,r);
    pushup(u);
}

void modify(int u,int l,int r,int k) {
    if (tr[u].l>=l && tr[u].r<=r) {
        tr[u].set=k;
        tr[u].mn=k;
    } else {
        pushdown(u);
        int mid=tr[u].l+tr[u].r>>1;
        if (l<=mid) modify(u<<1,l,r,k);
        if (r>mid) modify(u<<1|1,l,r,k);
        pushup(u);
    }
}

int query(int u,int l,int r) {
    if (tr[u].l>=l && tr[u].r<=r) return tr[u].mn;
    int ans=inf;
    pushdown(u);
    int mid=tr[u].l+tr[u].r>>1;
    if (l<=mid) ans=min(ans,query(u<<1,l,r));
    if (r>mid) ans=min(ans,query(u<<1|1,l,r));
    return ans;
}

int main() {
    scanf("%d %d %d",&h,&w,&n);
    _rep(i,1,n) {
        int r,c,l;
        scanf("%d %d %d",&r,&c,&l);
        arr[i]={r,c,l,i};
    }
    sort(arr+1,arr+1+n);
    build(1,1,w);
    _rep(i,1,n) {
        int r=arr[i].r,c=arr[i].c,l=arr[i].l,id=arr[i].i;
        int k=query(1,c,c+l-1);
        ans[id]=k;
        modify(1,c,c+l-1,k-1);
    }
    _rep(i,1,n) printf("%d\n",ans[i]);
    return 0;
}