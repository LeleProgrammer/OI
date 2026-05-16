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
const int M=26;

int n,m;
char str[N];
int cnt[M];

struct SegmentTree {
    int l,r;
    int sum;
    int tag;
} tr[M][N<<2];

void pushup(int p,int u) {
    auto &root=tr[p][u],&left=tr[p][u<<1],&right=tr[p][u<<1|1];
    root.sum=left.sum+right.sum;
}

void pushdown(int p,int u) {
    auto &root=tr[p][u],&left=tr[p][u<<1],&right=tr[p][u<<1|1];
    if (~root.tag) {
        left.tag=right.tag=root.tag;
        left.sum=(left.r-left.l+1)*root.tag;
        right.sum=(right.r-right.l+1)*root.tag;
        root.tag=-1;
    }
}

void build(int p,int u,int l,int r) {
    tr[p][u]={l,r,0,-1};
    if (l==r) return;
    int mid=l+r>>1;
    build(p,u<<1,l,mid);
    build(p,u<<1|1,mid+1,r);
    pushup(p,u);
}

void modify(int p,int u,int l,int r,int k) {
    auto &root=tr[p][u],&left=tr[p][u<<1],&right=tr[p][u<<1|1];
    if (root.l>=l && root.r<=r) {
        root.tag=k;
        root.sum=(root.r-root.l+1)*k;
    } else {
        pushdown(p,u);
        int mid=root.l+root.r>>1;
        if (l<=mid) modify(p,u<<1,l,r,k);
        if (r>mid) modify(p,u<<1|1,l,r,k);
        pushup(p,u);
    }
}

int query(int p,int u,int l,int r) {
    auto &root=tr[p][u],&left=tr[p][u<<1],&right=tr[p][u<<1|1];
    if (root.l>=l && root.r<=r) return root.sum;
    pushdown(p,u);
    int mid=root.l+root.r>>1;
    int ans=0;
    if (l<=mid) ans+=query(p,u<<1,l,r);
    if (r>mid) ans+=query(p,u<<1|1,l,r);
    return ans;
}

int main() {
    scanf("%d %d",&n,&m);
    scanf("%s",str+1);
    _rep(i,0,25) build(i,1,1,n);
    _rep(i,1,n) modify(str[i]-'a',1,i,i,1);
    while (m--) {
        int l,r,k;
        scanf("%d %d %d",&l,&r,&k);
        _rep(i,0,25) {
            cnt[i]=query(i,1,l,r);
            modify(i,1,l,r,0);
        }
        int st=l;
        if (k) {
            _rep(i,0,25) {
                if (!cnt[i]) continue;
                modify(i,1,st,st+cnt[i]-1,1);
                st+=cnt[i];
            }
        } else {
            _rrep(i,25,0) {
                if (!cnt[i]) continue;
                modify(i,1,st,st+cnt[i]-1,1);
                st+=cnt[i];
            }
        }
    }
    _rep(i,1,n) {
        _rep(j,0,25) {
            if (query(j,1,i,i)) {
                putchar(j+'a');
                break;
            }
        }
    }
    return 0;
}