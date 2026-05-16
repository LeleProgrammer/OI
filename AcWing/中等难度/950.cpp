#include <bits/stdc++.h>

#define inf 2147483647

using namespace std;

const int N=100005;

int n,m;
int delta;

struct node {
    int s[2],p,v;
    int size;
    void init(int v,int p) {
        this->v=v;
        this->p=p;
        this->size=1;
    }
} tr[N];

int root,tot,cnt;

void pushup(int u) {
    tr[u].size=tr[tr[u].s[0]].size+tr[tr[u].s[1]].size+1;
}

void rotate(int x) {
    int y=tr[x].p;
    int z=tr[y].p;
    int k=tr[y].s[1]==x;
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
            if ((tr[z].s[1]==y)^(tr[y].s[1]==x)) rotate(x);
            else rotate(y);
        }
        rotate(x);
    }
    if (!k) root=x;
}

int insert(int k) {
    int u=root,p=0;
    while (u) p=u,u=tr[u].s[tr[u].v<k];
    u=++tot; ++cnt;
    if (p) tr[p].s[tr[p].v<k]=u;
    tr[u].init(k,p);
    splay(u,0);
    return u;
}

int get_v(int v) {
    int u=root,ret;
    while (u) {
        if (tr[u].v>=v) ret=u,u=tr[u].s[0];
        else u=tr[u].s[1];
    }
    return ret;
}

int get_k(int k) {
    int u=root;
    while (u) {
        if (tr[tr[u].s[0]].size>=k) u=tr[u].s[0];
        else if (tr[tr[u].s[0]].size+1==k) return tr[u].v;
        else k-=tr[tr[u].s[0]].size+1,u=tr[u].s[1];
    }
    return -1;
}

int main() {
    scanf("%d %d",&n,&m);
    int negative_inf=insert(-inf);
    int positive_inf=insert(inf);
    while (n--) {
        char op;
        int k;
        scanf(" %c %d",&op,&k);
        if (op=='I') {
            if (k<m) continue;
            k-=delta;
            insert(k);
        } else if (op=='A') {
            delta+=k;
        } else if (op=='S') {
            delta-=k;
            int r=get_v(m-delta);
            splay(r,0);
            splay(negative_inf,r);
            tr[negative_inf].s[1]=0;
            pushup(negative_inf);
            pushup(r);
        } else {
            if (tr[root].size-2<k) puts("-1");
            else printf("%d\n",get_k(tr[root].size-k)+delta);
        }
    }
    printf("%d\n",cnt-tr[root].size);
    return 0;
}