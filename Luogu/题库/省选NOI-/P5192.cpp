#include <bits/stdc++.h>

#define int long long
#define inf 9000000000000000000LL

using namespace std;

const int N=1372; // 365+1000+2+5
const int M=1000005;

int n,m,s,t,S,T;
int e[M],ne[M],f[M],h[N],tot;
int layer[N],cur[N];
int in[N],out[N];

void add(int a,int b,int c) {
    e[tot]=b,f[tot]=c,ne[tot]=h[a],h[a]=tot++;
    e[tot]=a,f[tot]=0,ne[tot]=h[b],h[b]=tot++;
}

void init() {
    memset(h,-1,sizeof(h));
    memset(in,0,sizeof(in));
    memset(out,0,sizeof(out));
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

signed main() {
    while (scanf("%lld %lld",&n,&m)!=EOF) {
        init();
        s=0,t=n+m+1;
        for (int i=1;i<=m;++i) {
            int g;
            scanf("%lld",&g);
            add(n+i,t,inf-g);
            out[n+i]+=g,in[t]+=g;
        }
        for (int i=1;i<=n;++i) {
            int c,d;
            scanf("%lld %lld",&c,&d);
            add(s,i,d);
            for (int j=1;j<=c;++j) {
                int tt,l,r;
                scanf("%lld %lld %lld",&tt,&l,&r);
                tt++;
                add(i,n+tt,r-l);
                out[i]+=l,in[n+tt]+=l;
            }
        }
        S=n+m+2,T=n+m+3;
        int k=0;
        for (int i=s;i<=t;++i) {
            if (in[i]>out[i]) add(S,i,in[i]-out[i]),k+=in[i]-out[i];
            else add(i,T,out[i]-in[i]);
        }
        add(t,s,inf);
        int dn=dinic();
        if (dn!=k) puts("-1");
        else {
            int ans=f[tot-1];
            f[tot-1]=f[tot-2]=0;
            S=s,T=t;
            printf("%lld\n",ans+dinic());
        }
        putchar(10);
    }
    return 0;
}