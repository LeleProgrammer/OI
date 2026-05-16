#include <bits/stdc++.h>
using namespace std;

const int N=100205;

int n,m,q;

struct node {
    int s[2],p;
    string v;
    int size;
    void init(string v,int p) {
        this->v=v;
        this->p=p;
        size=1;
    }
} tr[N];

int root,tot;

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

int get_k(int k) {
    int u=root;
    while (u) {
        if (tr[tr[u].s[0]].size>=k)  u=tr[u].s[0];
        else if (tr[tr[u].s[0]].size+1==k) return u;
        else k-=tr[tr[u].s[0]].size+1,u=tr[u].s[1];
    }
    return -1;
}

int main() {
    int L=++tot;
    tr[L].init("I AK IOI!",0);
    int R=++tot;
    tr[R].init("I AK NOI!",tot-1);
    tr[L].s[1]=R;
    pushup(L);
    root=L;
    scanf("%d",&n);
    for (int i=1;i<=n;++i) {
        string s;
        cin>>s;
        int left=get_k(i);
        int right=get_k(i+1);
        int u=++tot;
        tr[right].s[0]=u;
        tr[u].init(s,right);
        pushup(right);
        pushup(left);
        splay(u,0);
    }
    scanf("%d",&m);
    while (m--) {
        string s;
        int k;
        cin>>s>>k;
        int left=get_k(k+1);
        int right=get_k(k+2);
        splay(left,0);
        splay(right,left);
        int u=++tot;
        tr[right].s[0]=u;
        tr[u].init(s,right);
        pushup(right);
        pushup(left);
        splay(u,0);
    }
    scanf("%d",&q);
    while (q--) {
        int k;
        scanf("%d",&k);
        int u=get_k(k+2);
        cout<<tr[u].v<<endl;
    }
    return 0;
}