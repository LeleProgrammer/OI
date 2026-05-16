#include <bits/stdc++.h>
using namespace std;

const int N=30005;

int n,q;
int p[N];

struct LCT {
    int s[2],p,v;
    int rev;
    int sum;
} tr[N];

int find(int x) {
    return (p[x]==x)?p[x]:(p[x]=find(p[x]));
}

void pushrev(int x) {
    swap(tr[x].s[0],tr[x].s[1]);
    tr[x].rev^=1;
}

void pushup(int x) {
    tr[x].sum=tr[tr[x].s[0]].sum+tr[tr[x].s[1]].sum+tr[x].v;
}

void pushdown(int x) {
    if (tr[x].rev) {
        pushrev(tr[x].s[0]);
        pushrev(tr[x].s[1]);
        tr[x].rev^=1;
    }
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
    stack<int> stk;
    int k=x;
    stk.push(k);
    while (!isroot(k)) k=tr[k].p,stk.push(k);
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
    for (int y=0;x;y=x,x=tr[x].p) {
        splay(x);
        tr[x].s[1]=y;
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

void split(int x,int y) {
    makeroot(x);
    access(y);
}

int main() {
    scanf("%d",&n);
    for (int i=1;i<=n;++i) {
        scanf("%d",&tr[i].v);
    }
    for (int i=1;i<=n;++i) {
        p[i]=i;
    }
    scanf("%d",&q);
    while (q--) {
        char op[15];
        int x,y;
        scanf("%s %d %d",op,&x,&y);
        if (!strcmp(op,"bridge")) {
            if (find(x)==find(y)) puts("no");
            else puts("yes"),link(x,y),p[find(x)]=find(y);
        } else if (!strcmp(op,"penguins")) {
            splay(x);
            tr[x].v=y;
            pushup(x);
        } else if (!strcmp(op,"excursion")) {
            if (find(x)!=find(y)) puts("impossible");
            else {
                split(x,y);
                printf("%d\n",tr[y].sum);
            }
        }
    }
    return 0;
}