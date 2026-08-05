#include <bits/stdc++.h>

#define inf 0x3f3f3f3f

using namespace std;

const int N=500005;

int n,m,s,a,b;
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
    depth[s]=1;
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
        int curr=q.front();
        q.pop();
        for (int i=h[curr];i;i=ne[i]) {
            if (depth[e[i]]!=inf) continue;
            q.push(e[i]);
            depth[e[i]]=depth[curr]+1;
            f[e[i]][0]=curr;
            for (int j=1;j<=20;++j) {
                f[e[i]][j]=f[f[e[i]][j-1]][j-1];
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

int main() {
    scanf("%d %d %d",&n,&m,&s);
    for (int i=1;i<=n-1;++i) {
        scanf("%d %d",&a,&b);
        add(a,b); add(b,a);
    }
    bfs();
    while (m--) {
        scanf("%d %d",&a,&b);
        printf("%d\n",lca(a,b));
    }
    return 0;
}