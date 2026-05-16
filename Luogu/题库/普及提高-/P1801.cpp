#include <bits/stdc++.h>

#define inf (2e9+100)

using namespace std;

const int M=200005;
const int N=200005;

int m,n;
int a[M];
int u[N];

int root,tot;

struct node {
    int l,r;
    int key,val;
    int cnt,size;
} tr[M];

void pushup(int k) {
    tr[k].size=tr[tr[k].l].size+tr[tr[k].r].size+tr[k].cnt;
}

int getnode(int k) {
    tr[++tot].key=k;
    tr[tot].val=rand();
    tr[tot].cnt=1;
    tr[tot].size=1;
    return tot;
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
    if (tr[root].val<tr[tr[root].r].val) zag(root);
}

void insert(int &p,int x) {
    if (!p) p=getnode(x);
    else if (x==tr[p].key) tr[p].cnt++;
    else if (x<tr[p].key) {
        insert(tr[p].l,x);
        if (tr[p].val<tr[tr[p].l].val) zig(p);
    } else {
        insert(tr[p].r,x);
        if (tr[p].val<tr[tr[p].r].val) zag(p);
    }
    pushup(p);
}

int query(int p,int k) {
    if (!p) return inf;
    else if (k<=tr[tr[p].l].size) return query(tr[p].l,k);
    else if (k<=tr[tr[p].l].size+tr[p].cnt) return tr[p].key;
    else return query(tr[p].r,k-tr[tr[p].l].size-tr[p].cnt);
}

int main() {
    scanf("%d %d",&m,&n);
    for (int i=1;i<=m;++i) scanf("%d",&a[i]);
    for (int i=1;i<=n;++i) scanf("%d",&u[i]);
    build();
    for (int i=1,j=1;i<=m;++i) {
        insert(root,a[i]);
        while (i==u[j]) {
            int ans=query(root,j+1);
            if (ans!=inf) printf("%d\n",ans);
            ++j;
        }
    }
    return 0;
}