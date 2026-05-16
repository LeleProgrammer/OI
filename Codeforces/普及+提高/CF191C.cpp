#include <bits/stdc++.h>

#define inf 0x3f3f3f3f

using namespace std;

const int N=100005;

int n,k;
int x,y;

int depth[N];
int f[N][25];

int h[N];
int e[N*2];
int ne[N*2];
int id[N*2];
int tot;

void add(int a,int b,int i) {
    e[++tot]=b;
    ne[tot]=h[a];
    id[tot]=i;
    h[a]=tot;
}

void bfs() {
    for (int i=1;i<=n;++i) depth[i]=inf;
    depth[0]=0;
    depth[1]=1;
    queue<int> q;
    q.push(1);
    while (!q.empty()) {
        int curr=q.front();
        q.pop();
        for (int i=h[curr];i;i=ne[i]) {
            if (depth[e[i]]==inf) {
                depth[e[i]]=depth[curr]+1;
                f[e[i]][0]=curr;
                q.push(e[i]);
                for (int j=1;j<=20;++j) {
                    f[e[i]][j]=f[f[e[i]][j-1]][j-1];
                }
            }
        }
    }
}

int lca(int a,int b) {
    if (a==b) return a;
    if (depth[a]<depth[b]) swap(a,b);
    for (int i=20;i>=0;--i) {
        if (depth[f[a][i]]>=depth[b]) {
            a=f[a][i];
        }
    }
    if (a==b) return a;
    for (int i=20;i>=0;--i) {
        if (f[a][i]!=f[b][i]) {
            a=f[a][i];
            b=f[b][i];
        }
    }
    return f[a][0];
}

int pre[N];
int res[N];

void dfs(int curr,int parent) {
    for (int i=h[curr];i;i=ne[i]) {
        if (e[i]==parent) continue;
        dfs(e[i],curr);
        res[id[i]]=pre[e[i]];
        pre[curr]+=pre[e[i]];
    }
}

int main() {
    scanf("%d",&n);
    for (int i=1;i<=n-1;++i) {
        scanf("%d %d",&x,&y);
        add(x,y,i); add(y,x,i);
    }
    bfs();
    scanf("%d",&k);
    while (k--) {
        scanf("%d %d",&x,&y);
        int anc=lca(x,y);
        pre[x]++,pre[y]++;
        pre[anc]-=2;
    }
    dfs(1,-1);
    for (int i=1;i<=n-1;++i) {
        printf("%d ",res[i]);
    }
    return 0;
}