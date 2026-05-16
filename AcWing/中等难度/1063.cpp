#include <bits/stdc++.h>
using namespace std;

const int N=3000005;

int n,m,q;

struct node {
    int s[2],p,v,id;
    int size;
    void init(int v,int p,int id) {
        this->v=v;
        this->p=p;
        this->id=id;
        this->size=1;
    }
} tr[N];

int root[N],tot;

int p[N];

int find(int x) {
    return (x==p[x])?p[x]:(p[x]=find(p[x]));
}

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

void splay(int x,int k,int b) {
    while (tr[x].p!=k) {
        int y=tr[x].p;
        int z=tr[y].p;
        if (z!=k) {
            if ((tr[z].s[1]==y)^(tr[y].s[1]==x)) rotate(x);
            else rotate(y);
        }
        rotate(x);
    }
    if (k==0) root[b]=x;
}

void insert(int k,int id,int b) {
    int u=root[b];
    int p=0;
    while (u) p=u,u=tr[u].s[tr[u].v<k];
    u=++tot;
    tr[u].init(k,p,id);
    if (p) tr[p].s[tr[p].v<k]=u;
    splay(u,0,b);
}

int get_k(int k,int b) {
    int u=root[b];
    while (u) {
        if (tr[tr[u].s[0]].size>=k) u=tr[u].s[0];
        else if (tr[tr[u].s[0]].size+1==k) return tr[u].id;
        else k-=tr[tr[u].s[0]].size+1,u=tr[u].s[1];
    }
    return -1;
}

void dfs(int x,int b) {
    if (tr[x].s[0]) dfs(tr[x].s[0],b);
    if (tr[x].s[1]) dfs(tr[x].s[1],b);
    insert(tr[x].v,tr[x].id,b);
}

int main() {
    scanf("%d %d",&n,&m);
    for (int i=1;i<=n;++i) {
        int v;
        scanf("%d",&v);
        tr[++tot].init(v,0,i);
        p[i]=i;
        root[i]=i;
    }
    while (m--) {
        int a,b;
        scanf("%d %d",&a,&b);
        a=find(a); b=find(b);
        if (a==b) continue;
        if (tr[root[a]].size>tr[root[b]].size) swap(a,b);
        dfs(root[a],b);
        p[a]=b;
    }
    scanf("%d",&q);
    while (q--) {
        char op;
        int x,k;
        scanf(" %c %d %d",&op,&x,&k);
        if (op=='B') {
            x=find(x); k=find(k);
            if (x==k) continue;
            if (tr[root[x]].size>tr[root[k]].size) swap(x,k);
            dfs(root[x],k);
            p[x]=k;
        } else {
            printf("%d\n",get_k(k,find(x)));
        }
    }
    return 0;
}