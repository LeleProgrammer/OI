#include <bits/stdc++.h>

#define inf 1000000000

using namespace std;

const int N=100005;
const int M=1000005;

struct node {
    int s[2],p,v,w;
    int size;
    void init(int v,int w,int p) {
        this->v=v;
        this->w=w;
        this->p=p;
        size=1;
    }
} tr[N];

bool vis[M];

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

int get_k(int k) {
    int u=root;
    while (u) {
        if (tr[tr[u].s[0]].size>=k) u=tr[u].s[0];
        else if (tr[tr[u].s[0]].size+1==k) return u;
        else k-=tr[tr[u].s[0]].size+1,u=tr[u].s[1];
    }
    return -1;
}

void insert(int w,int v) {
    int u=root,p=0;
    while (u) p=u,u=tr[u].s[v>tr[u].v];
    u=++tot;
    tr[u].init(v,w,p);
    if (p) tr[p].s[v>tr[p].v]=u;
    splay(u,0);
}

pair<int,int> dfs(int u) {
    int ans1,ans2;
    ans1=tr[u].w;
    ans2=tr[u].v;
    if (tr[u].s[0]) {
        auto t=dfs(tr[u].s[0]);
        ans1+=t.first;
        ans2+=t.second;
    }
    if (tr[u].s[1]) {
        auto t=dfs(tr[u].s[1]);
        ans1+=t.first;
        ans2+=t.second;
    }
    return {ans1,ans2};
}

int main() {
    root=1;
    tr[++tot].init(-inf,-inf,0);
    insert(inf,inf);
    while (true) {
        int op;
        scanf("%d",&op);
        if (!~op) break;
        if (op==1) {
            int w,c;
            scanf("%d %d",&w,&c);
            if (vis[c]) continue;
            insert(w,c);
            vis[c]=true;
            cnt++;
        } else if (op==2) {
            if (!cnt) continue;
            int left=get_k(cnt);
            int right=get_k(cnt+2);
            splay(left,0);
            splay(right,left);
            vis[tr[tr[right].s[0]].v]=false;
            tr[right].s[0]=0;
            cnt--;
        } else if (op==3) {
            if (!cnt) continue;
            int left=get_k(1);
            int right=get_k(3);
            splay(left,0);
            splay(right,left);
            vis[tr[tr[right].s[0]].v]=false;
            tr[right].s[0]=0;
            cnt--;
        }
    }
    auto ans=dfs(root);
    printf("%d %d",ans.first,ans.second);
    return 0;
}