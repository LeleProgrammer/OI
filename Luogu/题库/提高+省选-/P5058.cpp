#include <bits/stdc++.h>
using namespace std;

const int N=200005;
const int M=1000005;

int n,m,s,t;
int e[M],ne[M],h[N],tot;
bool cut[N];
int dcc;
int dfn[N],low[N],ts;
stack<int> stk;
vector<int> dccs[N];
vector<int> ans;
int root;
int d[N];

void add(int a,int b) {
    e[tot]=b,ne[tot]=h[a],h[a]=tot++;
}

void tarjan(int u) {
    dfn[u]=low[u]=++ts;
    stk.push(u);
    if (u==root && h[u]==-1) {
        dcc++;
        dccs[dcc].push_back(u);
        return;
    }
    for (int i=h[u];~i;i=ne[i]) {
        if (!dfn[e[i]]) {
            tarjan(e[i]);
            low[u]=min(low[u],low[e[i]]);
            if (dfn[u]<=low[e[i]]) {
                cut[u]=true;
                dcc++;
                int y;
                do {
                    y=stk.top(); stk.pop();
                    dccs[dcc].push_back(y);
                } while (y!=u);
                stk.push(u);
            }
        } else {
            low[u]=min(low[u],dfn[e[i]]);
        }
    }
}

void bfs1() {
    queue<int> q;
    q.push(s);
    d[s]=1;
    while (!q.empty()) {
        int u=q.front(); q.pop();
        for (int i=h[u];~i;i=ne[i]) {
            if (!d[e[i]]) {
                d[e[i]]=d[u]+1;
                q.push(e[i]);
            }
        }
    }
}

void bfs2() {
    queue<int> q;
    q.push(t);
    bool inq[N];
    memset(inq,0,sizeof(inq));
    inq[t]=true;
    while (!q.empty()) {
        int u=q.front(); q.pop();
        if (u!=s && u!=t && cut[u]) ans.push_back(u);
        inq[u]=false;
        for (int i=h[u];~i;i=ne[i]) {
            if (d[e[i]]==d[u]-1) {
                if (!inq[e[i]]) {
                    q.push(e[i]);
                    inq[e[i]]=true;
                }
            }
        }
    }
}

int main() {
    memset(h,-1,sizeof(h));
    scanf("%d",&n);
    while (true) {
        int a,b;
        scanf("%d %d",&a,&b);
        if (!a && !b) break;
        add(a,b);
        add(b,a);
    }
    scanf("%d %d",&s,&t);
    for (root=1;root<=n;++root) {
        if (!dfn[root]) {
            tarjan(root);
        }
    }
    bfs1();
    bfs2();
    if (ans.size()==0) printf("No solution");
    else {
        int ret=N;
        for (int k:ans) ret=min(ret,k);
        printf("%d",ret);
    }
    return 0;
}