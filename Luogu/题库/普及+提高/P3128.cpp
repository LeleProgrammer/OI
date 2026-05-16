#include <bits/stdc++.h>

#define inf 0x3f3f3f3f

using namespace std;

const int N=50005;

int n,k,x,y,s,t;
int h[N];
int e[N*2];
int ne[N*2];
int tot;

void add(int a,int b) {
    e[++tot]=b;
    ne[tot]=h[a];
    h[a]=tot;
}

int depth[N];
int f[N][25];

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

void dfs(int curr,int parent) {
    for (int i=h[curr];i;i=ne[i]) {
        if (e[i]==parent) continue;
        dfs(e[i],curr);
        pre[curr]+=pre[e[i]];
    }
}

int ans;

int main() {
    scanf("%d %d",&n,&k);
    for (int i=1;i<=n-1;++i) {
        scanf("%d %d",&x,&y);
        add(x,y); add(y,x);
    }
    bfs();
    while (k--) {
        scanf("%d %d",&s,&t);
        int anc=lca(s,t);
        pre[anc]--;
        pre[f[anc][0]]--;
        pre[s]++;
        pre[t]++;
    }
    dfs(1,-1);
    for (int i=1;i<=n;++i) {
        ans=max(ans,pre[i]);
    }
    printf("%d",ans);
    return 0;
}