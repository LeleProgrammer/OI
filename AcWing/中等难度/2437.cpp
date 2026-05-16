#include <bits/stdc++.h>
using namespace std;

const int N=100005;

int n,m,l,r;

struct node {
    
    int s[2],p,v;
    int size,flag;

    void init(int v,int p) {
        this->v=v;
        this->p=p;
        this->size=1;
    }

} tr[N];

int root,tot;

void pushup(int u) {
    tr[u].size=tr[tr[u].s[0]].size+tr[tr[u].s[1]].size+1;
}

void pushdown(int u) {
    if (tr[u].flag) {
        swap(tr[u].s[0],tr[u].s[1]);
        tr[tr[u].s[0]].flag^=1;
        tr[tr[u].s[1]].flag^=1;
        tr[u].flag^=1;
    }
}

void rotate(int x) {
    int y=tr[x].p;
    int z=tr[y].p;
    int k=(x==tr[y].s[1]);
    tr[z].s[tr[z].s[1]==y]=x,tr[x].p=z;
    tr[y].s[k]=tr[x].s[k^1],tr[tr[x].s[k^1]].p=y;
    tr[x].s[k^1]=y,tr[y].p=x;
    pushup(y);
    pushup(x);
}

void splay(int x,int k) {
    while (tr[x].p!=k) {
        int y=tr[x].p;
        int z=tr[y].p;
        if (z!=k) {
            if ((tr[z].s[0]==y)^(tr[y].s[0]==x)) {
                rotate(x);
            } else {
                rotate(y);
            }
        }
        rotate(x);
    }
    if (k==0) root=x;
}

// 这道题目的插入只会在有翻转操作前进行
// 所以插入的时候是满足 BST 的性质的
// 翻转了就不符合了
void insert(int x) {
    int u=root,p=0;
    while (u) p=u,u=tr[u].s[x>tr[u].v];
    u=++tot;
    if (p) tr[p].s[x>tr[p].v]=u;
    tr[u].init(x,p);
    splay(u,0);
}

int get_k(int k) {
    int u=root;
    while (true) {
        pushdown(u);
        if (tr[tr[u].s[0]].size>=k) u=tr[u].s[0];
        else if (tr[tr[u].s[0]].size+1==k) return u;
        else k-=tr[tr[u].s[0]].size+1,u=tr[u].s[1];
    }
    return -1;
}

void print(int u) {
    pushdown(u);
    if (tr[u].s[0]) print(tr[u].s[0]);
    if (tr[u].v && tr[u].v<=n) printf("%d ",tr[u].v);
    if (tr[u].s[1]) print(tr[u].s[1]);
}

int main() {
    scanf("%d %d",&n,&m);
    for (int i=0;i<=n+1;++i) insert(i);
    while (m--) {
        scanf("%d %d",&l,&r);
        l=get_k(l-1+1);
        r=get_k(r+1+1);
        splay(l,0);
        splay(r,l);
        tr[tr[r].s[0]].flag^=1;
    }
    print(root);
    return 0;
}