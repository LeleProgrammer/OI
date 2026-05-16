#include <bits/stdc++.h>

#define inf 0x3f3f3f3f

using namespace std;

const int N=50005;
const int M=200005;

int n,m;
int arr[N];

struct node {
    int l,r;
    multiset<int> s;
} tr[M];

void build(int u,int l,int r) {
    tr[u].l=l;
    tr[u].r=r;
    tr[u].s.insert(-inf);
    tr[u].s.insert(inf);
    for (int i=l;i<=r;++i) {
        tr[u].s.insert(arr[i]);
    }
    if (l==r) return;
    int mid=l+r>>1;
    build(u<<1,l,mid);
    build(u<<1|1,mid+1,r);
}

void modify(int u,int pos,int x) {
    tr[u].s.erase(tr[u].s.find(arr[pos]));
    tr[u].s.insert(x);
    if (tr[u].l==tr[u].r) return;
    int mid=tr[u].l+tr[u].r>>1;
    if (pos<=mid) modify(u<<1,pos,x);
    else modify(u<<1|1,pos,x);
}

int query(int u,int l,int r,int x) {
    if (tr[u].l>=l && tr[u].r<=r) {
        auto iter=tr[u].s.lower_bound(x);
        iter--;
        return *iter;
    } else {
        int res=-inf;
        int mid=tr[u].l+tr[u].r>>1;
        if (l<=mid) res=max(res,query(u<<1,l,r,x));
        if (r>mid) res=max(res,query(u<<1|1,l,r,x));
        return res;
    }
}

int main() {
    scanf("%d %d",&n,&m);
    for (int i=1;i<=n;++i) {
        scanf("%d",&arr[i]);
    }
    build(1,1,n);
    while (m--) {
        int op;
        scanf("%d",&op);
        if (op==1) {
            int pos,x;
            scanf("%d %d",&pos,&x);
            modify(1,pos,x);
            arr[pos]=x;
        } else if (op==2) {
            int l,r,x;
            scanf("%d %d %d",&l,&r,&x);
            printf("%d\n",query(1,l,r,x));
        }
    }
    return 0;
}