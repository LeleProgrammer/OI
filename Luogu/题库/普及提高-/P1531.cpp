#include <bits/stdc++.h>
using namespace std;

const int N=200005;

int n,m;
int arr[N];
char op[2];
int a,b;

struct node {
    int l,r;
    int maxx;
} tr[N*4];

void pushup(int p) {
    tr[p].maxx=max(tr[p<<1].maxx,tr[p<<1|1].maxx);
}

void build(int u,int l,int r) {
    tr[u]={l,r,0};
    if (l==r) tr[u].maxx=arr[l];
    else {
        int mid=l+r>>1;
        build(u<<1,l,mid);
        build(u<<1|1,mid+1,r);
        pushup(u);
    }
}

int query(int u,int x) {
    if (tr[u].l==x && tr[u].r==x) return tr[u].maxx;
    int mid=tr[u].l+tr[u].r>>1;
    if (x<=mid) return query(u<<1,x);
    else return query(u<<1|1,x);
}

int query(int u,int l,int r) {
    if (tr[u].l>=l && tr[u].r<=r) return tr[u].maxx;
    int mid=tr[u].l+tr[u].r>>1;
    int res=0;
    if (l<=mid) res=query(u<<1,l,r);
    if (r>mid) res=max(query(u<<1|1,l,r),res);
    return res;
}

void modify(int u,int x,int k) {
    if (tr[u].l==x && tr[u].r==x) tr[u].maxx=k;
    else {
        int mid=tr[u].l+tr[u].r>>1;
        if (x<=mid) modify(u<<1,x,k);
        else modify(u<<1|1,x,k);
        pushup(u);
    }
}

int main() {
    scanf("%d %d",&n,&m);
    for (int i=1;i<=n;++i) scanf("%d",&arr[i]);
    build(1,1,n);
    while (m--) {
        scanf("%s %d %d",op,&a,&b);
        if (op[0]=='Q') printf("%d\n",query(1,a,b));
        else if (query(1,a)<b) modify(1,a,b);
    }
    return 0;
}