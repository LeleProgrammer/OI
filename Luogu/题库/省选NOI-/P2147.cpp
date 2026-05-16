#include <bits/stdc++.h>
using namespace std;

const int N=10005;

int n,m;

struct LCT {
    int s[2],p,v;
    int rev;
} tr[N];

void pushrev(int x) {
    swap(tr[x].s[0],tr[x].s[1]);
    tr[x].rev^=1;
}

void pushup(int x) {
    ;
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
    while (tr[x].s[0]) x=tr[x].s[0];
    splay(x);
    return x;
}

void link(int x,int y) {
    makeroot(x);
    if (findroot(y)!=x) tr[x].p=y;
    splay(y);
}

void cut(int x,int y) {
    makeroot(x);
    if (findroot(y)==x && tr[y].p==x && !tr[y].s[0]) {
        tr[y].p=0;
        tr[x].s[1]=0;
        pushup(x);
    }
}

void split(int x,int y) {
    makeroot(x);
    access(y);
}

bool is_connected(int x,int y) {
    makeroot(x);
    return findroot(y)==x;
}

int main() {
    scanf("%d %d",&n,&m);
    while (m--) {
        char op[15];
        int x,y;
        scanf("%s %d %d",op,&x,&y);
        if (!strcmp(op,"Query")) {
            if (is_connected(x,y)) puts("Yes");
            else puts("No");
        } else if (!strcmp(op,"Connect")) {
            link(x,y);
        } else {
            cut(x,y);
        }
    }
    return 0;
}