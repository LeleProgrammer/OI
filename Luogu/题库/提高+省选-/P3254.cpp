#include <bits/stdc++.h>

#define inf 0x3f3f3f3f

using namespace std;

const int N=425;
const int M=81845;

int n,m,S,T,cnt;
int a[N],b[N];
int e[M],ne[M],f[M],h[N],tot;
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
    scanf("%d %d",&m,&n); S=0,T=n+m+1;
    for (int i=1;i<=m;++i) scanf("%d",a+i),cnt+=a[i];
    for (int i=1;i<=n;++i) scanf("%d",b+i);
    for (int i=1;i<=m;++i) add(S,i,a[i]);
    for (int i=1;i<=n;++i) add(i+m,T,b[i]);
    for (int i=1;i<=m;++i) {
        for (int j=1;j<=n;++j) {
            add(i,j+m,1);
        }
    }
    if (dinic()!=cnt) puts("0");
    else {
        puts("1");
        for (int i=1;i<=m;++i) {
            for (int j=h[i];~j;j=ne[j]) {
                if (e[j]>=m+1 && !f[j]) {
                    printf("%d ",e[j]-m);
                }
            }
            putchar(10);
        }
    }
    return 0;
}