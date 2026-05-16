#include <bits/stdc++.h>

#define inf 0x3f3f3f3f

using namespace std;

const int N=205;
const int M=80005;

int n,m,k,S,T;
int e[M],ne[M],f[M],w[M],h[N],tot;
int layer[N],cur[N];

void add(int a,int b,int c) {
    e[tot]=b,w[tot]=c,ne[tot]=h[a],h[a]=tot++;
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

bool check(int mid) {
    for (int i=0;i<tot;++i) {
        if (w[i]<=mid) f[i]=1;
        else f[i]=0;
    }
    return dinic()>=k;
}

int main() {
    memset(h,-1,sizeof(h));
    scanf("%d %d %d",&n,&m,&k); S=1,T=n;
    while (m--) {
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        add(a,b,c);
        add(b,a,c);
    }
    int l=1,r=1000000;
    while (l<r) {
        int mid=l+r>>1;
        if (check(mid)) r=mid;
        else l=mid+1;
    }
    printf("%d",l);
    return 0;
}