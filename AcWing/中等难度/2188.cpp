#include <bits/stdc++.h>

#define inf 0x3f3f3f3f

using namespace std;

const int N=205;
const int M=30005;

int n,m,S,T,a,b,c,d;
int e[M],ne[M],f[M],l[M],h[N],tot;
int in[N],out[N];
int layer[N],cur[N];

void add(int a,int b,int c,int d) {
    e[tot]=b,f[tot]=d-c,l[tot]=c,ne[tot]=h[a],h[a]=tot++;
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
                cur[e[i]]=h[e[i]];
                layer[e[i]]=layer[u]+1;
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
    scanf("%d %d",&n,&m); S=0,T=n+1;
    while (m--) {
        scanf("%d %d %d %d",&a,&b,&c,&d);
        add(a,b,c,d);
        in[b]+=c,out[a]+=c;
    }
    int k=0; // 从源点出发的边的容量和
    for (int i=1;i<=n;++i) {
        if (in[i]>out[i]) add(S,i,0,in[i]-out[i]),k+=in[i]-out[i];
        else add(i,T,0,out[i]-in[i]);
    }
    if (dinic()!=k) puts("NO");
    else {
        puts("YES");
        for (int i=0;i<tot;i+=2) {
            if (e[i^1]!=S && e[i]!=T) {
                printf("%d\n",f[i^1]+l[i]);
            }
        }
    }
    return 0;
}