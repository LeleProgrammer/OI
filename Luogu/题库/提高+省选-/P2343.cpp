#include <bits/stdc++.h>

#define int long long

using namespace std;

const int M=100005;
const int Q=30005;
const int inf=2147483648+100;

int m,q,c,v,n;
int root,tot,len;

struct node {
    int l,r;
    int key,val;
    int cnt,size;
} tr[M+Q];

int getnode(int k) {
    tr[++tot].key=k;
    tr[tot].val=rand();
    tr[tot].size=1;
    tr[tot].cnt=1;
    return tot;
}

void pushup(int p) {
    tr[p].size=tr[tr[p].l].size+tr[tr[p].r].size+tr[p].cnt;
}

void zig(int &p) {
    int q=tr[p].l;
    tr[p].l=tr[q].r;
    tr[q].r=p;
    p=q;
    pushup(tr[p].r);
    pushup(p);
}

void zag(int &p) {
    int q=tr[p].r;
    tr[p].r=tr[q].l;
    tr[q].l=p;
    p=q;
    pushup(tr[p].l);
    pushup(p);
}

void build() {
    getnode(-inf); getnode(inf);
    root=1;
    tr[root].r=2;
    pushup(root);
    if (tr[tr[root].r].val>tr[root].val) zag(root);
}

void insert(int &p,int x) {
    if (!p) p=getnode(x);
    else if (x==tr[p].key) tr[p].cnt++;
    else if (x<tr[p].key) {
        insert(tr[p].l,x);
        if (tr[tr[p].l].val>tr[p].val) zig(p);
    } else {
        insert(tr[p].r,x);
        if (tr[tr[p].r].val>tr[p].val) zag(p);
    }
    pushup(p);
}

int query(int p,int x) {
    if (!p) return 0;
    else if (x<=tr[tr[p].l].size) return query(tr[p].l,x);
    else if (x<=tr[tr[p].l].size+tr[p].cnt) return tr[p].key;
    else return query(tr[p].r,x-tr[tr[p].l].size-tr[p].cnt);
}

signed main() {
    scanf("%lld %lld",&m,&q);
    build();
    for (int i=1;i<=m;++i) {
        scanf("%lld",&v);
        insert(root,v);
        ++len;
    }
    while (q--) {
        scanf("%lld %lld",&c,&n);
        if (c==1) printf("%lld\n",query(root,len-n+1+1));
        else insert(root,n),++len;
    }
    return 0;
}