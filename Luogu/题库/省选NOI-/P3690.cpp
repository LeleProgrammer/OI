#include <bits/stdc++.h>
using namespace std;

const int N=100005;

int n,m;

stack<int> stk;

struct LCT {
    int s[2],p,v;
    int sum;
    int rev;
} tr[N];

void pushrev(int x) {
    swap(tr[x].s[0],tr[x].s[1]);
    tr[x].rev^=1;
}

void pushdown(int x) {
    if (tr[x].rev) {
        pushrev(tr[x].s[0]);
        pushrev(tr[x].s[1]);
        tr[x].rev^=1;
    }
}

void pushup(int x) {
    tr[x].sum=tr[tr[x].s[0]].sum^tr[tr[x].s[1]].sum^tr[x].v;
}

bool isroot(int x) {
    return tr[tr[x].p].s[0]!=x && tr[tr[x].p].s[1]!=x;
}

void rotate(int x) {
    int y=tr[x].p;
    int z=tr[y].p;
    int k=tr[y].s[1]==x;
    if (!isroot(y)) tr[z].s[tr[z].s[1]==y]=x;
    tr[x].p=z;
    tr[y].s[k]=tr[x].s[k^1],tr[tr[x].s[k^1]].p=y;
    tr[x].s[k^1]=y,tr[y].p=x;
    pushup(y);
    pushup(x);
}

void splay(int x) {
    int k=x;
    stk.push(k);
    while (!isroot(k)) {
        stk.push(k=tr[k].p);
    }
    while (!stk.empty()) pushdown(stk.top()),stk.pop();
    while (!isroot(x)) {
        int y=tr[x].p;
        int z=tr[y].p;
        if (!isroot(y)) {
            if ((tr[z].s[1]==y)^(tr[y].s[1]==x)) rotate(x);
            else rotate(y);
        }
        rotate(x);
    }
}

void access(int x) {
    int k=x;
    for (int p=0;x;p=x,x=tr[x].p) {
        splay(x);
        tr[x].s[1]=p;
        pushup(x);
    }
    splay(k);
}

void makeroot(int x) {
    access(x);
    pushrev(x);
}

int findroot(int x) {
    access(x);
    while (tr[x].s[0]) pushdown(x),x=tr[x].s[0];
    splay(x);
    return x;
}

void link(int x,int y) {
    makeroot(x);
    if (findroot(y)!=x) tr[x].p=y;
}

void cut(int x,int y) {
    makeroot(x);
    if (findroot(y)==x && tr[y].p==x && !tr[y].s[0]) {
        tr[x].s[1]=0;
        tr[y].p=0;
        pushup(x);
    }
}

void split(int x,int y) {
    makeroot(x);
    access(y);
}

int main() {
    scanf("%d %d",&n,&m);
    for (int i=1;i<=n;++i) {
        scanf("%d",&tr[i].v); // 直接读进 splay 节点，起初是有 n 棵单节点的树的森林
    }
    while (m--) {
        int op,x,y;
        scanf("%d %d %d",&op,&x,&y);
        if (op==0) {
            split(x,y); // 此时 y 在 splay 的顶部
            printf("%d\n",tr[y].sum);
        } else if (op==1) {
            link(x,y);
        } else if (op==2) {
            cut(x,y);
        } else {
            splay(x);
            tr[x].v=y;
            pushup(x); // 对自己进行修改也会影响结果，所以也要 pushup
        }
    }
    return 0;
}