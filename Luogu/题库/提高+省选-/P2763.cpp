#include <bits/stdc++.h>

#define inf 2147483647

using namespace std;

const int N=1025;
const int M=21025;

int k,n,S,T;
int e[M],f[M],ne[M],h[N],tot;
int layer[N],cur[N];
vector<int> ans[N];

void add(int a,int b,int c) {
    e[tot]=b,f[tot]=c,ne[tot]=h[a],h[a]=tot++;
    e[tot]=a,f[tot]=0,ne[tot]=h[b],h[b]=tot++;
}

bool bfs() {
    queue<int> q;
    memset(layer,-1,sizeof(layer));
    q.push(S); layer[S]=0; cur[S]=h[S];
    while (!q.empty()) {
        int u=q.front(); q.pop();
        for (int i=h[u];~i;i=ne[i]) {
            if (layer[e[i]]==-1 && f[i]) {
                layer[e[i]]=layer[u]+1;
                cur[e[i]]=h[e[i]];
                if (e[i]==T) return true;
                q.push(e[i]);
            }
        }
    }
    return false;
}

int dfs(int u,int limit) {
    if (u==T) return limit;
    int k=0;
    for (int i=cur[u];~i && k<limit;i=ne[i]) {
        cur[u]=i;
        if (layer[e[i]]==layer[u]+1 && f[i]) {
            int ret=dfs(e[i],min(f[i],limit-k));
            if (!ret) layer[e[i]]=-1;
            k+=ret,f[i]-=ret,f[i^1]+=ret;
        }
    }
    return k;
}

int dinic() {
    int ans=0,k;
    while (bfs()) while (k=dfs(S,inf)) ans+=k;
    return ans;
}

int main() {
    memset(h,-1,sizeof(h));
    scanf("%d %d",&k,&n); S=0,T=N-1;
    int m=0;
    for (int i=1;i<=k;++i) {
        int v;
        scanf("%d",&v);
        add(i+n,T,v);
        m+=v;
    }
    for (int i=1;i<=n;++i) {
        add(S,i,1);
        int p;
        scanf("%d",&p);
        while (p--) {
            int v;
            scanf("%d",&v);
            add(i,n+v,1);
        }
    }
    if (dinic()!=m) puts("No Solution!");
    else {
        for (int i=0;i<tot;i+=2) {
            if (e[i]>n && e[i]<=n+k && !f[i]) {
                ans[e[i]-n].push_back(e[i^1]);
            }
        }
        for (int i=1;i<=k;++i) {
            printf("%d: ",i);
            for (int v:ans[i]) {
                printf("%d ",v);
            }
            putchar(10);
        }
    }
    return 0;
}