#include <bits/stdc++.h>
using namespace std;

const int N=50005;

int n,q,h[N];
int a,b;

struct node {
    int l,r;
    int maxx;
    int minn;
} tr[N*4];

void pushup(int u) {
    tr[u].maxx=max(tr[u<<1].maxx,tr[u<<1|1].maxx);
    tr[u].minn=min(tr[u<<1].minn,tr[u<<1|1].minn);
}

void build(int u,int l,int r) {
    if (l==r) {
        tr[u]={l,r,h[l],h[l]};
    } else {
        tr[u]={l,r,0,0};
        int mid=l+r>>1;
        build(u<<1,l,mid);
        build(u<<1|1,mid+1,r);
        pushup(u);
    }
}

int query_maxx(int u,int l,int r) {
    if (tr[u].l>=l && tr[u].r<=r) return tr[u].maxx;
    else {
        int mid=tr[u].l+tr[u].r>>1;
        int res=0;
        if (l<=mid) res=query_maxx(u<<1,l,r);
        if (r>mid) res=max(res,query_maxx(u<<1|1,l,r));
        return res;
    }
}

int query_minn(int u,int l,int r) {
    if (tr[u].l>=l && tr[u].r<=r) return tr[u].minn;
    else {
        int mid=tr[u].l+tr[u].r>>1;
        int res=0x3f3f3f;
        if (l<=mid) res=query_minn(u<<1,l,r);
        if (r>mid) res=min(res,query_minn(u<<1|1,l,r));
        return res;
    }
}

int main() {
    scanf("%d %d",&n,&q);
    for (int i=1;i<=n;++i) scanf("%d",&h[i]);
    build(1,1,n);
    while (q--) {
        scanf("%d %d",&a,&b);
        printf("%d\n",query_maxx(1,a,b)-query_minn(1,a,b));
    }
    return 0;
}