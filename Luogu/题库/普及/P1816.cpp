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
const int inf=2e9;

int n,m;
int arr[N];

struct SegmentTree {
    int l,r;
    int min;
} tr[N<<2];

void pushup(int u) {
    tr[u].min=min(tr[u<<1].min,tr[u<<1|1].min);
}

void build(int u,int l,int r) {
    tr[u]={l,r,arr[l]};
    if (l==r) return;
    int mid=l+r>>1;
    build(u<<1,l,mid); build(u<<1|1,mid+1,r);
    pushup(u);
}

int query(int u,int l,int r) {
    if (tr[u].l>=l && tr[u].r<=r) return tr[u].min;
    int mid=tr[u].l+tr[u].r>>1;
    int ans=inf;
    if (l<=mid) ans=min(ans,query(u<<1,l,r));
    if (r>mid) ans=min(ans,query(u<<1|1,l,r));
    return ans;
}

int main() {
    scanf("%d %d",&n,&m);
    _rep(i,1,n) scanf("%d",&arr[i]);
    build(1,1,n);
    while (m--) {
        int l,r;
        scanf("%d %d",&l,&r);
        printf("%d ",query(1,l,r));
    }
    return 0;
}