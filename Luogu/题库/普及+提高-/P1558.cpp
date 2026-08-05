#include <bits/stdc++.h>
using namespace std;

int L,T,O;
char op[2];
int a,b,c;

struct node {
    int l;
    int r;
    int sta;
    int mdf;
} tr[400020];

int transfer(int sta) {
    int res=0;
    while (sta) {
        res+=sta&1;
        sta>>=1;
    }
    return res;
}

void pushup(int u) {
    tr[u].sta=tr[u<<1].sta|tr[u<<1|1].sta;
}

void pushdown(int u) {
    auto &root=tr[u],&left=tr[u<<1],&right=tr[u<<1|1];
    if (root.mdf) {
        left.mdf=right.mdf=root.mdf;
        left.sta=right.sta=1<<(root.mdf-1);
        root.mdf=0;
    }
}

void build(int u,int l,int r) {
    if (l==r) tr[u]={l,r,1,0};
    else {
        tr[u]={l,r,1,0};
        int mid=l+r>>1;
        build(u<<1,l,mid); build(u<<1|1,mid+1,r);
        pushup(u);
    }
}

void modify(int u,int l,int r,int c) {
    if (tr[u].l>=l && tr[u].r<=r) {
        tr[u].mdf=c;
        tr[u].sta=1<<(c-1);
    } else {
        pushdown(u);
        int mid=tr[u].l+tr[u].r>>1;
        if (l<=mid) modify(u<<1,l,r,c);
        if (r>=mid+1) modify(u<<1|1,l,r,c);
        pushup(u);
    }
}

int query(int u,int l,int r) {
    if (tr[u].l>=l && tr[u].r<=r) return tr[u].sta;
    pushdown(u);
    int mid=tr[u].l+tr[u].r>>1;
    int res=0;
    if (l<=mid) res|=query(u<<1,l,r);
    if (r>=mid+1) res|=query(u<<1|1,l,r);
    return res;
}

int main() {
    scanf("%d %d %d",&L,&T,&O);
    build(1,1,L);
    while (O--) {
        scanf("%s",op);
        if (*op=='C') {
            scanf("%d %d %d",&a,&b,&c);
            if (a>b) swap(a,b);
            modify(1,a,b,c);
        } else {
            scanf("%d %d",&a,&b);
            if (a>b) swap(a,b);
            printf("%d\n",transfer(query(1,a,b)));
        }
    }
    return 0;
}