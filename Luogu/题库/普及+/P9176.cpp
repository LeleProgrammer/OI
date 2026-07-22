#include <bits/stdc++.h>

#define int long long
#define inf 2e9

using namespace std;

const int N=200005;

int n,v,a;
int tot;
int root;
int stu;

struct node {
    int l,r;
    int key,val;
    int cnt,size;
} tr[N];

int getnode(int k,int cnt=1) {
    tr[++tot].key=k;
    tr[tot].val=rand();
    tr[tot].cnt=cnt;
    tr[tot].size=cnt;
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
    getnode(-inf);
    getnode(inf);
    root=1;
    tr[root].r=2;
    if (tr[tr[root].r].val>tr[root].val) zag(root);
}

void insert(int &p,int key,int size) {
    if (!p) p=getnode(key,size);
    else if (key<tr[p].key) {
        insert(tr[p].l,key,size);
        if (tr[tr[p].l].val>tr[p].val) zig(p);
    }
    else if (key>tr[p].key) {
        insert(tr[p].r,key,size);
        if (tr[tr[p].r].val>tr[p].val) zag(p);
    }
    else tr[p].cnt+=size;
    pushup(p);
}

int query(int p,int rank) {
    if (rank<=tr[tr[p].l].size) return query(tr[p].l,rank);
    else if (rank<=tr[tr[p].l].size+tr[p].cnt) return tr[p].key;
    else return query(tr[p].r,rank-tr[tr[p].l].size-tr[p].cnt);
}

signed main() {
    scanf("%lld",&n);
    build();
    while (n--) {
        scanf("%lld %lld",&v,&a);
        insert(root,v,a);
        stu+=a;
        if (stu%2) printf("%lld\n",query(root,(stu+1)/2+1));
        else printf("%lld\n",min(query(root,stu/2+1),query(root,stu/2+1+1)));
    }
    return 0;
}