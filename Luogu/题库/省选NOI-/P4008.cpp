#include <bits/stdc++.h>
using namespace std;

const int N=2097157; // 2*1024*1024+5

int T;

struct node {
    int s[2],p;
    char v;
    int size;
    void init(char v,int p) {
        this->v=v;
        this->p=p;
        size=1;
    }
} tr[N];

int root,tot;
int cur;
char s[N];

void pushup(int u) {
    tr[u].size=tr[tr[u].s[0]].size+tr[tr[u].s[1]].size+1;
}

void rotate(int x) {
    int y=tr[x].p,z=tr[y].p;
    int k=tr[y].s[1]==x;
    tr[z].s[tr[z].s[1]==y]=x,tr[x].p=z;
    tr[y].s[k]=tr[x].s[k^1],tr[tr[x].s[k^1]].p=y;
    tr[x].s[k^1]=y,tr[y].p=x;
    pushup(y);
    pushup(x);
}

void splay(int x,int k) {
    while (tr[x].p!=k) {
        int y=tr[x].p,z=tr[y].p;
        if (z!=k) {
            if ((tr[z].s[1]==y)^(tr[y].s[1]==x)) rotate(x);
            else rotate(y);
        }
        rotate(x);
    }
    if (!k) root=x;
}

int build(int l,int r,int p) {
    int mid=l+r>>1;
    int u=++tot;
    tr[u].init(s[mid],p);
    if (l==r) return u;
    if (l<mid) tr[u].s[0]=build(l,mid-1,u);
    if (r>mid) tr[u].s[1]=build(mid+1,r,u);
    pushup(u);
    return u;
}

int get_k(int k) {
    int u=root;
    while (u) {
        if (tr[tr[u].s[0]].size>=k) u=tr[u].s[0];
        else if (tr[tr[u].s[0]].size+1==k) return u;
        else k-=tr[tr[u].s[0]].size+1,u=tr[u].s[1];
    }
    return -1;
}

void dfs(int u) {
    if (tr[u].s[0]) dfs(tr[u].s[0]);
    printf("%c",tr[u].v);
    if (tr[u].s[1]) dfs(tr[u].s[1]);
}

void init() {
    int l=++tot;
    int r=++tot;
    tr[l].init(' ',0);
    tr[r].init(' ',l);
    tr[l].s[1]=r;
    root=l;
}

void readin(int n) {
    for (int i=1;i<=n;++i) {
        char c;
        c=getchar();
        if (c<32 || c>126) i--;
        else {
            s[i]=c;
        }
    }
}

int main() {
    init();
    scanf("%d",&T);
    while (T--) {
        char op[15];
        scanf("%s",op);
        if (!strcmp(op,"Move")) {
            int k;
            scanf("%d",&k);
            cur=k;
        } else if (!strcmp(op,"Insert")) {
            int n;
            scanf("%d",&n);
            readin(n);
            int left=get_k(cur+1);
            int right=get_k(cur+2);
            splay(left,0);
            splay(right,left);
            int u=build(1,n,right);
            tr[right].s[0]=u;
            pushup(right);
            pushup(left);
            splay(u,0);
        } else if (!strcmp(op,"Delete")) {
            int n;
            scanf("%d",&n);
            int left=get_k(cur+1);
            int right=get_k(cur+1+n+1);
            splay(left,0);
            splay(right,left);
            tr[right].s[0]=0;
            pushup(right);
            pushup(left);
        } else if (!strcmp(op,"Get")) {
            int n;
            scanf("%d",&n);
            int left=get_k(cur+1);
            int right=get_k(cur+1+n+1);
            splay(left,0);
            splay(right,left);
            dfs(tr[right].s[0]);
            putchar(10);
        } else if (!strcmp(op,"Prev")) {
            cur--;
        } else if (!strcmp(op,"Next")) {
            cur++;
        }
    }
    return 0;
}