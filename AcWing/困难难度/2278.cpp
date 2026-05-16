#include <bits/stdc++.h>

#define inf 0x3f3f3f3f

using namespace std;

typedef pair<int,int> pii;

const int N=205;
const int M=100005;

int t,n,S,T;
double d;
int e[M],f[M],ne[M],h[N],tot;
int layer[N],cur[N];
pii arr[N];

void add(int a,int b,int c) {
    e[tot]=b,f[tot]=c,ne[tot]=h[a],h[a]=tot++;
    e[tot]=a,f[tot]=0,ne[tot]=h[b],h[b]=tot++;
}

bool check(pii a,pii b) {
    int x=a.first-b.first;
    int y=a.second-b.second;
    return sqrt(x*x+y*y)<=d;
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
    scanf("%d",&t);
    while (t--) {
        memset(h,-1,sizeof(h));
        tot=0;
        scanf("%d %lf",&n,&d); S=0;
        int cnt=0;
        for (int i=1;i<=n;++i) {
            int a,b,c,d;
            scanf("%d %d %d %d",&a,&b,&c,&d);
            arr[i]={a,b};
            add(S,i,c);
            add(i,n+i,d);
            cnt+=c;
        }
        for (int i=1;i<=n;++i) {
            for (int j=i+1;j<=n;++j) {
                if (check(arr[i],arr[j])) {
                    add(n+i,j,inf);
                    add(n+j,i,inf);
                }
            }
        }
        bool ok=false;
        for (int i=1;i<=n;++i) {
            T=i;
            for (int j=0;j<tot;j+=2) {
                f[j]+=f[j^1];
                f[j^1]=0;
            }
            if (dinic()==cnt) {
                ok=true;
                printf("%d ",i-1);
            }
        }
        if (!ok) {
            puts("-1");
        } else {
            putchar(10);
        }
    }
    return 0;
}