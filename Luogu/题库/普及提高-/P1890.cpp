#include <bits/stdc++.h>
using namespace std;

const int N=1005;

int n,m;
int arr[N];

struct SegmentTree {
    int l,r;
    int val;
} tr[N*4];

int gcd(int a,int b) {
    if (!b) return a;
    else return gcd(b,a%b);
}

void pushup(int u) {
    tr[u].val=gcd(tr[u<<1].val,tr[u<<1|1].val);
}

void build(int u,int l,int r) {
    tr[u]={l,r,arr[l]};
    if (l==r) return;
    int mid=l+r>>1;
    build(u<<1,l,mid); build(u<<1|1,mid+1,r);
    pushup(u);
}

int query(int u,int l,int r) {
    if (tr[u].l>=l && tr[u].r<=r) return tr[u].val;
    int mid=tr[u].l+tr[u].r>>1;
    int ans=0;
    if (l<=mid) ans=query(u<<1,l,r);
    if (r>mid) {
        if (!ans) ans=query(u<<1|1,l,r);
        else ans=gcd(ans,query(u<<1|1,l,r));
    }
    return ans;
}

int main() {
    scanf("%d %d",&n,&m);
    for (int i=1;i<=n;++i) {
        scanf("%d",&arr[i]);
    }
    build(1,1,n);
    while (m--) {
        int l,r;
        scanf("%d %d",&l,&r);
        printf("%d\n",query(1,l,r));
    }
    return 0;
}