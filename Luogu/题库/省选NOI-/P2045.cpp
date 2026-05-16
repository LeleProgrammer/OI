#include <bits/stdc++.h>
using namespace std;

const int N=5007;
const int M=60009;
const int inf=1e9;

int n,k,S,T;
int arr[55][55];
int e[M],f[M],c[M],ne[M],h[N],tot;
int dis[N],flow[N],back[N];
bool inq[N];

void add(int a,int b,int flow,int cost) {
    e[tot]=b,f[tot]=flow,c[tot]=cost,ne[tot]=h[a],h[a]=tot++;
    e[tot]=a,f[tot]=0,c[tot]=-cost,ne[tot]=h[b],h[b]=tot++;
}

int get(int i,int j) {
    return (i-1)*n+j;
}

bool spfa() {
    queue<int> q;
    for (int i=0;i<N;++i) dis[i]=-inf,flow[i]=inf;
    q.push(S); dis[S]=0; inq[S]=true;
    while (!q.empty()) {
        int u=q.front(); q.pop(); inq[u]=false;
        for (int i=h[u];~i;i=ne[i]) {
            if (dis[e[i]]<dis[u]+c[i] && f[i]) {
                dis[e[i]]=dis[u]+c[i];
                back[e[i]]=i;
                flow[e[i]]=min(flow[u],f[i]);
                if (!inq[e[i]]) {
                    q.push(e[i]);
                    inq[e[i]]=true;
                }
            }
        }
    }
    return dis[T]!=-inf;
}

int EK() {
    int ans=0;
    while (spfa()) {
        int u=T;
        while (u!=S) {
            ans+=flow[T]*c[back[u]];
            f[back[u]]-=flow[T];
            f[back[u]^1]+=flow[T];
            u=e[back[u]^1];
        }
    }
    return ans;
}

int main() {
    memset(h,-1,sizeof(h));
    scanf("%d %d",&n,&k); S=0,T=N-1;
    for (int i=1;i<=n;++i) {
        for (int j=1;j<=n;++j) {
            scanf("%d",&arr[i][j]);
        }
    }
    add(S,get(1,1),k,0);
    add(get(n,n)+n*n,T,k,0);
    for (int i=1;i<=n;++i) {
        for (int j=1;j<=n;++j) {
            if (i!=n) add(get(i,j)+n*n,get(i+1,j),k,0);
            if (j!=n) add(get(i,j)+n*n,get(i,j+1),k,0);
            add(get(i,j),get(i,j)+n*n,1,arr[i][j]);
            for (int p=2;p<=k;++p) add(get(i,j),get(i,j)+n*n,1,0);
        }
    }
    printf("%d\n",EK());
    return 0;
}