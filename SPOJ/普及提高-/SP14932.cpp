#include <bits/stdc++.h>

#define inf 0x3f3f3f3f

using namespace std;

const int N=1005;

int T,n,m,q,u,v;

int h[N];
int e[N];
int ne[N];
int tot;
bool flag[N];

void add(int a,int b) {
    e[++tot]=b;
    ne[tot]=h[a];
    h[a]=tot;
}

int f[N][25];
int depth[N];

void bfs(int root) {
    for (int i=1;i<=N-1;++i) {
        depth[i]=inf;
    }
    memset(f,0,sizeof(f));
    depth[0]=0;
    depth[root]=1;
    queue<int> q;
    q.push(root);
    while (!q.empty()) {
        int curr=q.front();
        q.pop();
        for (int i=h[curr];i;i=ne[i]) {
            if (depth[e[i]]==inf) {
                depth[e[i]]=depth[curr]+1;
                f[e[i]][0]=curr;
                for (int j=1;j<=20;++j) {
                    f[e[i]][j]=f[f[e[i]][j-1]][j-1];
                }
                q.push(e[i]);
            }
        }
    }
}

int lca(int a,int b) {
    if (a==b) return a;
    if (depth[a]<depth[b]) swap(a,b);
    for (int j=20;j>=0;--j) {
        if (depth[f[a][j]]>=depth[b]) {
            a=f[a][j];
        }
    }
    if (a==b) return a;
    for (int j=20;j>=0;--j) {
        if (f[a][j]!=f[b][j]) {
            a=f[a][j];
            b=f[b][j];
        }
    }
    return f[a][0];
}

int main() {
    scanf("%d",&T);
    for (int Case=1;Case<=T;++Case) {
        printf("Case %d:\n",Case);
        memset(h,0,sizeof(h));
        memset(e,0,sizeof(e));
        memset(ne,0,sizeof(ne));
        memset(flag,false,sizeof(flag));
        tot=0;
        scanf("%d",&n);
        for (int i=1;i<=n;++i) {
            scanf("%d",&m);
            while (m--) {
                scanf("%d",&u);
                add(i,u);
                flag[u]=true;
            }
        }
        int root;
        for (root=1;root<=n;++root) {
            if (!flag[root]) break;
        }
        bfs(root);
        scanf("%d",&q);
        while (q--) {
            scanf("%d %d",&u,&v);
            printf("%d\n",lca(u,v));
        }
    }
    return 0;
}