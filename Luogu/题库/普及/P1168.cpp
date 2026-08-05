#include <bits/stdc++.h>

#define inf 2e9

using namespace std;

const int N=100005;

int n;
int tot;
int root;

struct node {
    int l,r;
    int key,val;
    int cnt,size;
} tr[N];

int getnode(int k) {
    tr[++tot].key=k;
    tr[tot].val=rand();
    tr[tot].cnt=1;
    tr[tot].size=1;
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
    tr[1].r=2;
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

int query(int &p,int x) {
    if (!p) return inf;
    else if (x<=tr[tr[p].l].size) return query(tr[p].l,x);
    else if (x<=tr[tr[p].l].size+tr[p].cnt) return tr[p].key;
    else return query(tr[p].r,x-tr[tr[p].l].size-tr[p].cnt);
}

int main() {
    scanf("%d",&n);
    build();
    for (int i=1;i<=n;++i) {
        int v;
        scanf("%d",&v);
        insert(root,v);
        if (i%2) printf("%d\n",query(root,(i+1)/2+1));
    }
    return 0;
}