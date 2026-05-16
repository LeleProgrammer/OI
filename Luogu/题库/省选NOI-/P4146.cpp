#include <bits/stdc++.h>

#define inf 1000000000

using namespace std;

const int N=50005;

int n,m;
int arr[N];

struct node {
    int s[2],p,v;
    int size,max;
    int add,fli;
    void init(int v,int p) {
        this->v=v;
        this->p=p;
        max=v;
        size=1;
        add=0;
        fli=0;
    }
} tr[N];

int root,tot;

template<class T>
T max3(T a,T b,T c) {
    return max(max(a,b),c);
}

void pushup(int u) {
    tr[u].size=tr[tr[u].s[0]].size+tr[tr[u].s[1]].size+1;
    tr[u].max=max3(tr[u].v,tr[tr[u].s[0]].max,tr[tr[u].s[1]].max);
}

void pushdown(int x) {
    auto &u=tr[x],&l=tr[tr[x].s[0]],&r=tr[tr[x].s[1]];
    if (u.add) {
        if (u.s[0]) l.add+=u.add,l.max+=u.add,l.v+=u.add;
        if (u.s[1]) r.add+=u.add,r.max+=u.add,r.v+=u.add;
        u.add=0;
    }
    if (u.fli) {
        swap(l.s[0],l.s[1]);
        swap(r.s[0],r.s[1]);
        l.fli^=1;
        r.fli^=1;
        u.fli=0;
    }
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

int get_k(int k){
    int u=root;
    while (u) {
        pushdown(u);
        if (tr[tr[u].s[0]].size>=k) u=tr[u].s[0];
        else if (tr[tr[u].s[0]].size+1==k) return u;
        else k-=tr[tr[u].s[0]].size+1,u=tr[u].s[1];
    }
    return 0;
}

int build(int l,int r,int p) {
    int mid=l+r>>1;
    int u=++tot;
    tr[u].init(arr[mid],p);
    if (l<mid) tr[u].s[0]=build(l,mid-1,u);
    if (r>mid) tr[u].s[1]=build(mid+1,r,u);
    pushup(u);
    return u;
}

int main() {
    scanf("%d %d",&n,&m);
    for (int i=0;i<N;++i) tr[i].max=-inf;
    memset(arr,0,sizeof(arr));
    arr[0]=arr[n+1]=-inf;
    root=build(0,n+1,0);
    while (m--) {
        int op,l,r;
        scanf("%d %d %d",&op,&l,&r);
        if (op==1) {
            int v;
            scanf("%d",&v);
            int left=get_k(l);
            int right=get_k(r+2);
            splay(left,0);
            splay(right,left);
            auto &u=tr[tr[right].s[0]];
            u.add+=v;
            u.max+=v;
            u.v+=v;
            pushup(right);
            pushup(left);
        } else if (op==2) {
            int left=get_k(l);
            int right=get_k(r+2);
            splay(left,0);
            splay(right,left);
            auto &u=tr[tr[right].s[0]];
            u.fli^=1;
            swap(u.s[0],u.s[1]);
            pushup(right);
            pushup(left);
        } else {
            int left=get_k(l);
            int right=get_k(r+2);
            splay(left,0);
            splay(right,left);
            auto &u=tr[tr[right].s[0]];
            printf("%d\n",u.max);
        }
    }
    return 0;
}