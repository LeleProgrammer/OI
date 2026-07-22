#include <bits/stdc++.h>

#define int long long

using namespace std;

int n,m,p;

struct node {
    int l;
    int r;
    int maxx;
} tr[800020];

char op[2]; int t;
int last;

void pushup(int u) {
    tr[u].maxx=max(tr[u<<1].maxx,tr[u<<1|1].maxx);
}

void build(int u,int l,int r) {
    tr[u].l=l;
    tr[u].r=r;
    if (l==r) return;
    int mid=l+r>>1;
    build(u<<1,l,mid);
    build(u<<1|1,mid+1,r);
}

int query(int u,int l,int r) {
    if (tr[u].l>=l && tr[u].r<=r) return tr[u].maxx;
    int mid=tr[u].l+tr[u].r>>1;
    int res=0;
    if (r>=mid+1) res=max(res,query(u<<1|1,l,r));
    if (l<=mid) res=max(res,query(u<<1,l,r));
    return res;
}

void modify(int u,int x,int v) {
    if (tr[u].l==x && tr[u].r==x) tr[u].maxx=v;
    else {
        int mid=tr[u].l+tr[u].r>>1;
        if (x<=mid) modify(u<<1,x,v);
        else modify(u<<1|1,x,v);
        pushup(u);
    }
}

signed main() {
    scanf("%lld %lld",&m,&p);
    build(1,1,m);
    while (m--) {
        scanf("%s %lld",op,&t);
        if (op[0]=='Q') {
            last=query(1,n-t+1,n);
            printf("%lld\n",last);
        } else {
            modify(1,++n,(t+last)%p);
        }
    }
    return 0;
}