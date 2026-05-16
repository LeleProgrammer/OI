#include <bits/stdc++.h>

#define inf 0x3f3f3f3f

using namespace std;

const int N=205;
const int M=50005;

int n,m,s,t,S,T,a,b,c,d;
int e[M],ne[M],f[M],h[N],tot;
int in[N],out[N];
int layer[N],cur[N];

void add(int a,int b,int c) {
    e[tot]=b,f[tot]=c,ne[tot]=h[a],h[a]=tot++;
    e[tot]=a,f[tot]=0,ne[tot]=h[b],h[b]=tot++;
}

bool bfs() {
    memset(layer,-1,sizeof(layer));
    queue<int> q;
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
    scanf("%d %d %d %d",&n,&m,&s,&t);
    while (m--) {
        scanf("%d %d %d %d",&a,&b,&c,&d);
        add(a,b,d-c);
        in[b]+=c,out[a]+=c;
    }
    S=0,T=n+1;
    int k=0;
    for (int i=1;i<=n;++i) {
        if (in[i]>out[i]) add(S,i,in[i]-out[i]),k+=in[i]-out[i];
        else add(i,T,out[i]-in[i]);
    }
    add(t,s,inf);
    if (dinic()<k) puts("No Solution");
    else {
        int ans=f[tot-1];
        f[tot-1]=f[tot-2]=0;
        S=s,T=t;
        printf("%d",ans+dinic());
    }
    return 0;
}