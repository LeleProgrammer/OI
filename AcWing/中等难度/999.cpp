#include <bits/stdc++.h>

#define inf 2147483647

using namespace std;

const int N=150005;

int n,m;
int p[N];
// stack<int> stk;
int stk[N],tt;

struct Splay {
    int s[2],p,v;
    int max;
    int rev;
} tr[N];

struct Edge {
    int x,y,a,b;
    friend bool operator < (const Edge& a,const Edge& b) {
        return a.a<b.a;
    }
} e[N];

int find(int x) {
    return (p[x]==x)?p[x]:(p[x]=find(p[x]));
}

bool isroot(int x) {
    return tr[tr[x].p].s[0]!=x && tr[tr[x].p].s[1]!=x;
}

void pushrev(int x) {
    swap(tr[x].s[0],tr[x].s[1]);
    tr[x].rev^=1;
}

void pushup(int x) {
    tr[x].max=x;
    for (int i=0;i<=1;++i) {
        if (tr[tr[tr[x].s[i]].max].v>tr[tr[x].max].v) {
            tr[x].max=tr[tr[x].s[i]].max;
        }
    }
}

void pushdown(int x) {
    if (tr[x].rev) {
        pushrev(tr[x].s[0]);
        pushrev(tr[x].s[1]);
        tr[x].rev^=1;
    }
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
    stk[++tt]=k;
    while (!isroot(k)) k=tr[k].p,stk[++tt]=k;
    while (tt) pushdown(stk[tt]),tt--;
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

int findroot(int x) {
    access(x);
    while (tr[x].s[0]) {
        pushdown(x);
        x=tr[x].s[0];
    }
    splay(x);
    return x;
}

void makeroot(int x) {
    access(x);
    pushrev(x);
}

void split(int x,int y) {
    makeroot(x);
    access(y);
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

int main() {
    scanf("%d %d",&n,&m);
    for (int i=1;i<=m;++i) {
        scanf("%d %d %d %d",&e[i].x,&e[i].y,&e[i].a,&e[i].b);
    }
    sort(e+1,e+1+m);
    for (int i=1;i<=n+m;++i) {
        p[i]=i;
        if (i>=n+1) {
            tr[i].v=e[i-n].b;
        }
        tr[i].max=i;
    }
    int ans=inf;
    for (int i=1;i<=m;++i) {
        if (find(e[i].x)==find(e[i].y)) {
            split(e[i].x,e[i].y);
            int maxx=tr[e[i].y].max;
            if (tr[maxx].v>e[i].b) {
                cut(e[maxx-n].x,maxx);
                cut(e[maxx-n].y,maxx);
                link(e[i].x,i+n);
                link(e[i].y,i+n);
            }
        } else {
            p[find(e[i].x)]=find(e[i].y);
            link(e[i].x,i+n);
            link(e[i].y,i+n);
        }
        if (find(1)==find(n)) {
            split(1,n);
            int maxx=tr[n].max;
            ans=min(ans,e[i].a+tr[maxx].v);
        }
    }
    if (ans==inf) puts("-1");
    else printf("%d",ans);
    return 0;
}