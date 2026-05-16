#include <bits/stdc++.h>

#define int long long
#define inf 1000000000000000000LL

using namespace std;

typedef pair<int,int> pii;

const int N=505;
const int M=100005;

int n,m,K,S,T;
int e[M],f[M],ne[M],h[N],tot;
int layer[N],cur[N];
int p[N];
vector<pii> arr;

void add(int a,int b,int c,int d) {
    e[tot]=b,f[tot]=c,ne[tot]=h[a],h[a]=tot++;
    e[tot]=a,f[tot]=d,ne[tot]=h[b],h[b]=tot++;
}

void build(int d) {
    memset(h,-1,sizeof(h));
    tot=0;
    for (auto i:arr) {
        add(i.first,i.second,1,1);
    }
    for (int i=1;i<=n;++i) {
        if (~p[i]) {
            if ((p[i]>>d&1)==0) add(S,i,inf,0); // 优先级，需要加括号
            else add(i,T,inf,0);
        }
    }
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
        if (layer[e[i]]==layer[u]+1 && f[i]) {
            int ret=dfs(e[i],min(f[i],limit-k));
            if (!ret) layer[e[i]]=-1;
            k+=ret,f[i]-=ret,f[i^1]+=ret;
        }
    }
    return k;
}

int dinic(int d) {
    build(d);
    int ans=0,k;
    while (bfs()) while (k=dfs(S,inf)) ans+=k;
    return ans;
}

signed main() {
    memset(p,-1,sizeof(p));
    scanf("%lld %lld",&n,&m); S=0,T=n+1;
    while (m--) {
        int a,b;
        scanf("%lld %lld",&a,&b);
        arr.push_back(make_pair(a,b));
    }
    scanf("%lld",&K);
    while (K--) {
        int a,b;
        scanf("%lld %lld",&a,&b);
        p[a]=b;
    }
    int ans=0;
    for (int i=0;i<=30;++i) ans+=dinic(i)<<i;
    printf("%lld",ans);
    return 0;
}